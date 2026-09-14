#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


static void log_printf(const char *fmt, ...);

#ifndef GL_REPLACE
#define GL_REPLACE 0x1E01
#endif
#ifndef GL_COLOR_MATERIAL_PARAMETER
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#endif

#ifndef OPENGL_GETINFO
#define OPENGL_GETINFO 4353
#endif
#ifndef QUERYESCSUPPORT
#define QUERYESCSUPPORT 8
#endif

typedef struct {
    DWORD version;
    DWORD driverVersion;
    char driverName[262];
} TEST_GLDRVINFO;

#define TEST_GLDRVINFO_OUTPUT_BYTES 532

static void log_escape_state(HDC hdc)
{
    DWORD esc;
    DWORD sub;
    int ret;
    BYTE output[TEST_GLDRVINFO_OUTPUT_BYTES];
    TEST_GLDRVINFO *info = (TEST_GLDRVINFO *)output;
    unsigned char *name = (unsigned char *)info->driverName;

    log_printf("--- Direct OPENGL_GETINFO check ---");
    esc = OPENGL_GETINFO;
    SetLastError(0);
    ret = ExtEscape(hdc, QUERYESCSUPPORT, sizeof(esc), (LPCSTR)&esc, 0, NULL);
    log_printf("ExtEscape(QUERYESCSUPPORT, OPENGL_GETINFO): ret=%d error=%lu", ret, GetLastError());

    ZeroMemory(output, sizeof(output));
    sub = 0;
    SetLastError(0);
    ret = ExtEscape(hdc, OPENGL_GETINFO, sizeof(sub), (LPCSTR)&sub,
        sizeof(output), (LPSTR)output);
    info->driverName[sizeof(info->driverName) - 1] = 0;
    log_printf("ExtEscape(OPENGL_GETINFO): ret=%d error=%lu cbOutput=%u payload=%u", ret, GetLastError(),
        (unsigned)sizeof(output), (unsigned)sizeof(*info));
    log_printf("Returned version=%lu driverVersion=%lu driverName=%s",
        info->version, info->driverVersion, info->driverName[0] ? info->driverName : "(empty)");
    log_printf("Win9x ICD GETINFO ABI: expected version=2 ANSI name, cbOutput=532; match=%s",
        (info->version == 2 && info->driverVersion == 1 && info->driverName[0] != 0) ? "YES" : "NO");
    log_printf("Returned name bytes: %02X %02X %02X %02X %02X %02X %02X %02X",
        (unsigned)name[0], (unsigned)name[1], (unsigned)name[2], (unsigned)name[3],
        (unsigned)name[4], (unsigned)name[5], (unsigned)name[6], (unsigned)name[7]);
    log_printf("");
}

static void log_manual_icd_chain(HDC hdc)
{
    typedef BOOL (APIENTRY *PFN_DRVVALIDATEVERSION)(ULONG);
    typedef LONG (APIENTRY *PFN_DRVDESCRIBEPIXELFORMAT)(HDC, INT, ULONG, PIXELFORMATDESCRIPTOR *);
    DWORD sub = 0;
    BYTE output[TEST_GLDRVINFO_OUTPUT_BYTES];
    TEST_GLDRVINFO *info = (TEST_GLDRVINFO *)output;
    char driverName[264];
    char dllName[260];
    HKEY key;
    DWORD type, size;
    LONG rc;
    HMODULE mod;
    PFN_DRVVALIDATEVERSION validate;
    PFN_DRVDESCRIBEPIXELFORMAT describe;
    PIXELFORMATDESCRIPTOR pfd;
    int ret;

    log_printf("--- Manual ICD loader chain ---");
    ZeroMemory(output, sizeof(output));
    SetLastError(0);
    ret = ExtEscape(hdc, OPENGL_GETINFO, sizeof(sub), (LPCSTR)&sub, sizeof(output), (LPSTR)output);
    info->driverName[sizeof(info->driverName) - 1] = 0;
    lstrcpyn(driverName, info->driverName, sizeof(driverName));
    log_printf("GETINFO: ret=%d error=%lu version=%lu driverVersion=%lu name=%s", ret, GetLastError(), info->version, info->driverVersion, driverName);
    if (ret <= 0 || !driverName[0]) {
        log_printf("Manual chain stopped: OPENGL_GETINFO failed.");
        log_printf("");
        return;
    }

    rc = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        "Software\\Microsoft\\Windows\\CurrentVersion\\OpenGLdrivers",
        0, KEY_READ, &key);
    log_printf("OpenGLdrivers open: rc=%ld", rc);
    if (rc != ERROR_SUCCESS) { log_printf(""); return; }
    size = sizeof(dllName); type = 0; dllName[0] = 0;
    rc = RegQueryValueEx(key, driverName, NULL, &type, (LPBYTE)dllName, &size);
    RegCloseKey(key);
    log_printf("Registry lookup by returned name: rc=%ld type=%lu size=%lu dll=%s", rc, type, size, rc == ERROR_SUCCESS ? dllName : "(none)");
    if (rc != ERROR_SUCCESS || type != REG_SZ || !dllName[0]) { log_printf(""); return; }

    SetLastError(0);
    mod = LoadLibrary(dllName);
    log_printf("LoadLibrary(resolved DLL): %08lX error=%lu", (DWORD)mod, GetLastError());
    if (!mod) { log_printf(""); return; }

    validate = (PFN_DRVVALIDATEVERSION)GetProcAddress(mod, "DrvValidateVersion");
    if (validate) {
        SetLastError(0);
        log_printf("DrvValidateVersion(%lu): %u error=%lu", info->driverVersion, validate(info->driverVersion) ? 1U : 0U, GetLastError());
    } else {
        log_printf("DrvValidateVersion: missing");
    }

    describe = (PFN_DRVDESCRIBEPIXELFORMAT)GetProcAddress(mod, "DrvDescribePixelFormat");
    if (describe) {
        ZeroMemory(&pfd, sizeof(pfd));
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        SetLastError(0);
        ret = (int)describe(hdc, 0, 0, NULL);
        log_printf("DrvDescribePixelFormat(count): ret=%d error=%lu", ret, GetLastError());
        SetLastError(0);
        ret = (int)describe(hdc, 1, sizeof(pfd), &pfd);
        log_printf("DrvDescribePixelFormat(1): ret=%d error=%lu flags=%08lX color=%u depth=%u", ret, GetLastError(), pfd.dwFlags, (unsigned)pfd.cColorBits, (unsigned)pfd.cDepthBits);
    } else {
        log_printf("DrvDescribePixelFormat: missing");
    }

    FreeLibrary(mod);
    log_printf("");
}

static void log_icd_dll_state(void)
{
    static const char *exports[] = {
        "DrvCopyContext",
        "DrvCreateContext",
        "DrvCreateLayerContext",
        "DrvDeleteContext",
        "DrvDescribeLayerPlane",
        "DrvDescribePixelFormat",
        "DrvGetLayerPaletteEntries",
        "DrvGetProcAddress",
        "DrvRealizeLayerPalette",
        "DrvReleaseContext",
        "DrvSetCallbackProcs",
        "DrvSetContext",
        "DrvSetLayerPaletteEntries",
        "DrvSetPixelFormat",
        "DrvShareLists",
        "DrvSwapBuffers",
        "DrvSwapLayerBuffers",
        "DrvValidateVersion"
    };
    HMODULE mod;
    FARPROC proc;
    int i;
    int missing = 0;

    log_printf("--- Direct NPOGL32.DLL load/export check ---");
    SetLastError(0);
    mod = LoadLibrary("NPOGL32.DLL");
    log_printf("LoadLibrary(NPOGL32.DLL): %08lX error=%lu", (DWORD)mod, GetLastError());
    if (!mod) {
        log_printf("Direct DLL load FAILED. OpenGL32 cannot use this ICD until this is fixed.");
        log_printf("");
        return;
    }

    for (i = 0; i < (int)(sizeof(exports) / sizeof(exports[0])); ++i) {
        proc = GetProcAddress(mod, exports[i]);
        if (!proc) {
            ++missing;
            log_printf("EXPORT MISSING: %s error=%lu", exports[i], GetLastError());
        }
    }
    log_printf("Required export check: %s (%d missing)", missing ? "FAIL" : "OK", missing);

    FreeLibrary(mod);
    log_printf("");
}

static HDC g_dc;
static HGLRC g_rc;
static FILE *g_log;

static void log_printf(const char *fmt, ...)
{
    va_list ap;
    if (!g_log) return;
    va_start(ap, fmt);
    vfprintf(g_log, fmt, ap);
    va_end(ap);
    fputs("\r\n", g_log);
    fflush(g_log);
}

static const char *safe_gl_string(GLenum name)
{
    const GLubyte *s = glGetString(name);
    return s ? (const char *)s : "(null)";
}

static const char *pixel_format_path(const PIXELFORMATDESCRIPTOR *pfd)
{
    if (pfd->dwFlags & PFD_GENERIC_FORMAT) {
        if (pfd->dwFlags & PFD_GENERIC_ACCELERATED) return "Generic accelerated (MCD-style path)";
        return "Windows GDI Generic software OpenGL";
    }
    return "Installable Client Driver (ICD)";
}

static void log_install_state(void)
{
    HKEY key;
    LONG rc;
    DWORD type;
    DWORD size;
    char value[260];
    char sysdir[MAX_PATH];
    char path[MAX_PATH];
    DWORD attr;

    log_printf("--- NPDISP ICD installation check ---");
    value[0] = 0;
    size = sizeof(value);
    type = 0;
    rc = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
        "Software\\Microsoft\\Windows\\CurrentVersion\\OpenGLdrivers",
        0, KEY_READ, &key);
    log_printf("RegOpenKey(OpenGLdrivers): rc=%ld", rc);
    if (rc == ERROR_SUCCESS) {
        rc = RegQueryValueEx(key, "NPOGL32", NULL, &type, (LPBYTE)value, &size);
        if (rc == ERROR_SUCCESS) {
            value[sizeof(value) - 1] = 0;
            log_printf("Registry NPOGL32: type=%lu size=%lu value=%s", type, size, value);
        } else {
            log_printf("Registry NPOGL32: NOT FOUND rc=%ld", rc);
        }
        RegCloseKey(key);
    }

    if (GetSystemDirectory(sysdir, sizeof(sysdir))) {
        lstrcpy(path, sysdir);
        if (lstrlen(path) && path[lstrlen(path) - 1] != '\\') lstrcat(path, "\\");
        lstrcat(path, "NPOGL32.DLL");
        attr = GetFileAttributes(path);
        log_printf("ICD file: %s", path);
        log_printf("ICD file status: %s (attr=0x%08lX)", attr == 0xffffffffUL ? "NOT FOUND" : "present", attr);
    }
    log_printf("");
}

static void log_pixel_formats(void)
{
    PIXELFORMATDESCRIPTOR p;
    int count;
    int i;

    ZeroMemory(&p, sizeof(p));
    p.nSize = sizeof(p);
    p.nVersion = 1;
    count = DescribePixelFormat(g_dc, 1, sizeof(p), &p);
    log_printf("--- Pixel format enumeration ---");
    log_printf("DescribePixelFormat reports %d format(s)", count);
    if (count > 128) count = 128;
    for (i = 1; i <= count; ++i) {
        ZeroMemory(&p, sizeof(p));
        p.nSize = sizeof(p);
        p.nVersion = 1;
        if (DescribePixelFormat(g_dc, i, sizeof(p), &p)) {
            log_printf("PF %d: flags=%08lX color=%u depth=%u stencil=%u dbl=%u generic=%u genaccel=%u path=%s",
                i, p.dwFlags, (unsigned)p.cColorBits, (unsigned)p.cDepthBits, (unsigned)p.cStencilBits,
                (p.dwFlags & PFD_DOUBLEBUFFER) ? 1U : 0U,
                (p.dwFlags & PFD_GENERIC_FORMAT) ? 1U : 0U,
                (p.dwFlags & PFD_GENERIC_ACCELERATED) ? 1U : 0U,
                pixel_format_path(&p));
        }
    }
    log_printf("");
}

static void show_renderer_info(HWND hwnd, int pf)
{
    PIXELFORMATDESCRIPTOR actual;
    const char *vendor;
    const char *renderer;
    const char *version;
    const char *path;
    const char *result;
    HMODULE icdModule;
    char text[1792];
    char title[256];

    ZeroMemory(&actual, sizeof(actual));
    actual.nSize = sizeof(actual);
    actual.nVersion = 1;
    if (!DescribePixelFormat(g_dc, pf, sizeof(actual), &actual)) ZeroMemory(&actual, sizeof(actual));

    vendor = safe_gl_string(GL_VENDOR);
    renderer = safe_gl_string(GL_RENDERER);
    version = safe_gl_string(GL_VERSION);
    path = pixel_format_path(&actual);
    icdModule = GetModuleHandle("NPOGL32.DLL");

    if (strstr(vendor, "Neko Project II") || strstr(renderer, "NPDISP")) {
        result = "NPDISP ICD ACTIVE - Microsoft GDI Generic is NOT being used.";
    } else if ((actual.dwFlags & PFD_GENERIC_FORMAT) && !(actual.dwFlags & PFD_GENERIC_ACCELERATED)) {
        result = "WINDOWS SOFTWARE OPENGL - Microsoft GDI Generic is being used.";
    } else if ((actual.dwFlags & PFD_GENERIC_FORMAT) && (actual.dwFlags & PFD_GENERIC_ACCELERATED)) {
        result = "GENERIC ACCELERATED OPENGL path is active.";
    } else {
        result = "VENDOR ICD ACTIVE - Microsoft GDI Generic is NOT being used.";
    }

    log_printf("--- Selected renderer ---");
    log_printf("Result: %s", result);
    log_printf("Pixel format: %d", pf);
    log_printf("Pixel-format path: %s", path);
    log_printf("PFD flags: 0x%08lX", actual.dwFlags);
    log_printf("GL_VENDOR: %s", vendor);
    log_printf("GL_RENDERER: %s", renderer);
    log_printf("GL_VERSION: %s", version);
    log_printf("GetModuleHandle(NPOGL32.DLL): %08lX", (DWORD)icdModule);
    log_printf("");

    wsprintf(text,
        "%s\r\n\r\n"
        "Pixel format: %d\r\n"
        "Pixel-format path: %s\r\n"
        "PFD flags: 0x%08lX\r\n\r\n"
        "GL_VENDOR: %s\r\n"
        "GL_RENDERER: %s\r\n"
        "GL_VERSION: %s\r\n"
        "NPOGL32.DLL loaded: %s\r\n\r\n"
        "Diagnostic details were written to TESTGL.LOG.\r\n\r\n"
        "Note: NPDISP uses an ICD frontend and the NPDISP host-side software rasterizer.",
        result, pf, path, actual.dwFlags, vendor, renderer, version,
        icdModule ? "YES" : "NO");

    wsprintf(title, "TESTGL - %s / %s", vendor, renderer);
    SetWindowText(hwnd, title);
    MessageBox(hwnd, text, "OpenGL Renderer Identification", MB_OK | MB_ICONINFORMATION);
}

static LRESULT CALLBACK wndproc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg) {
    case WM_SIZE:
        if (g_rc) {
            int w = LOWORD(lp);
            int h = HIWORD(lp);
            if (h < 1) h = 1;
            glViewport(0, 0, w, h);
        }
        return 0;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
    WNDCLASS wc;
    HWND hwnd;
    PIXELFORMATDESCRIPTOR pfd;
    PIXELFORMATDESCRIPTOR actual;
    MSG msg;
    int pf;
    BOOL running = TRUE;
    DWORD err;
    int capsBpp;
    int capsPlanes;
    int capsX;
    int capsY;
    GLubyte checker[8 * 8 * 4];
    GLubyte checker2[8 * 8 * 4];
    GLubyte pixelBlock[8 * 8 * 4];
    GLubyte pixelReadback[8 * 8 * 4];
    GLubyte pixelCopyReadback[8 * 8 * 4];
    GLfloat rasterPos[4];
    GLint packAlignmentQuery;
    GLint unpackAlignmentQuery;
    GLboolean rasterValidQuery;
    GLubyte polygonStipple[128];
    GLubyte polygonStippleReadback[128];
    GLuint displayLists;
    GLubyte displayListIndices[2];
    GLfloat colorBeforeList[4];
    GLfloat colorAfterList[4];
    GLfloat modelviewBeforeList[16];
    GLfloat modelviewAfterList[16];
    GLfloat lineWidthBeforeList;
    GLfloat lineWidthAfterList;
    GLfloat fogDensityBeforeList;
    GLfloat fogDensityAfterList;
    GLfloat materialBeforeList[4];
    GLfloat materialAfterList[4];
    GLfloat lightBeforeList[4];
    GLfloat lightAfterList[4];
    GLint texFilterBeforeList;
    GLint texFilterAfterList;
    GLint texEnvBeforeList;
    GLint texEnvAfterList;
    GLint colorMaterialBeforeList;
    GLint colorMaterialAfterList;
    GLuint textures[2];
    GLenum glerr;
    int tx;
    int ty;
    static const GLfloat triVertices[9] = {
        -0.95f, -0.55f, 0.0f,
        -0.35f, -0.55f, 0.0f,
        -0.65f,  0.60f, 0.0f
    };
    static const GLubyte triColors[12] = {
        255, 38, 26, 255,
        26, 255, 51, 255,
        26, 89, 255, 255
    };
    static const GLfloat quadVertices[12] = {
         0.35f, -0.55f, 0.0f,
         0.95f, -0.55f, 0.0f,
         0.95f,  0.55f, 0.0f,
         0.35f,  0.55f, 0.0f
    };
    static const GLfloat quadTexCoords[8] = {
        0.0f, 0.0f,
        2.0f, 0.0f,
        2.0f, 2.0f,
        0.0f, 2.0f
    };
    static const GLushort quadIndices[4] = { 0, 1, 2, 3 };
    static const GLfloat lightPos[4] = { 0.25f, 0.55f, 1.0f, 0.0f };
    static const GLfloat lightDiffuse[4] = { 1.0f, 0.95f, 0.85f, 1.0f };
    static const GLfloat materialDiffuse[4] = { 0.95f, 0.45f, 0.12f, 1.0f };
    static const GLfloat materialSpecular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    static const GLfloat fogColor[4] = { 0.08f, 0.10f, 0.18f, 1.0f };
    static const GLfloat listLightDiffuse[4] = { 0.25f, 0.65f, 1.0f, 1.0f };
    static const GLfloat listLightAmbient[4] = { 0.12f, 0.14f, 0.18f, 1.0f };
    static const GLfloat listMaterialDiffuse[4] = { 0.20f, 0.80f, 0.35f, 1.0f };
    GLfloat query4[4];
    GLint scissorQuery[4];
    GLint hintQuery;
    GLint polygonQuery[2];
    GLfloat pointQuery;
    GLfloat lineQuery;
    RECT clientRc;
    (void)prev;
    (void)cmd;
    (void)show;

    g_log = fopen("testgl.log", "wt");
    log_printf("NPDISP OpenGL diagnostic test");
    log_printf("GetVersion: 0x%08lX", GetVersion());
    log_printf("");
    log_install_state();

    ZeroMemory(&wc, sizeof(wc));
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = wndproc;
    wc.hInstance = inst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "NPDISP_OGL_TEST";
    if (!RegisterClass(&wc)) {
        err = GetLastError();
        log_printf("RegisterClass failed: error=%lu", err);
        if (g_log) fclose(g_log);
        return 1;
    }
    hwnd = CreateWindow(wc.lpszClassName, "NPDISP OpenGL Phase 5i", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, inst, NULL);
    if (!hwnd) {
        err = GetLastError();
        log_printf("CreateWindow failed: error=%lu", err);
        if (g_log) fclose(g_log);
        return 1;
    }

    g_dc = GetDC(hwnd);
    capsBpp = GetDeviceCaps(g_dc, BITSPIXEL);
    capsPlanes = GetDeviceCaps(g_dc, PLANES);
    capsX = GetDeviceCaps(g_dc, HORZRES);
    capsY = GetDeviceCaps(g_dc, VERTRES);
    log_printf("Display caps: %dx%d BITSPIXEL=%d PLANES=%d total_bpp=%d",
        capsX, capsY, capsBpp, capsPlanes, capsBpp * capsPlanes);
    log_printf("");
    log_escape_state(g_dc);
    log_manual_icd_chain(g_dc);
    log_icd_dll_state();
    log_pixel_formats();

    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 16;
    pfd.cDepthBits = 12;
    pfd.cStencilBits = 4;
    pfd.iLayerType = PFD_MAIN_PLANE;

    SetLastError(0);
    pf = ChoosePixelFormat(g_dc, &pfd);
    err = GetLastError();
    log_printf("ChoosePixelFormat: pf=%d error=%lu", pf, err);
    if (!pf) {
        MessageBox(hwnd, "ChoosePixelFormat failed. See TESTGL.LOG.", "TESTGL", MB_OK | MB_ICONERROR);
        if (g_log) fclose(g_log);
        return 2;
    }

    ZeroMemory(&actual, sizeof(actual));
    actual.nSize = sizeof(actual);
    actual.nVersion = 1;
    if (DescribePixelFormat(g_dc, pf, sizeof(actual), &actual)) {
        log_printf("Chosen PF before SetPixelFormat: flags=%08lX path=%s color=%u depth=%u stencil=%u",
            actual.dwFlags, pixel_format_path(&actual), (unsigned)actual.cColorBits, (unsigned)actual.cDepthBits, (unsigned)actual.cStencilBits);
    }

    SetLastError(0);
    if (!SetPixelFormat(g_dc, pf, &pfd)) {
        err = GetLastError();
        log_printf("SetPixelFormat failed: pf=%d error=%lu", pf, err);
        MessageBox(hwnd, "SetPixelFormat failed. See TESTGL.LOG.", "TESTGL", MB_OK | MB_ICONERROR);
        if (g_log) fclose(g_log);
        return 2;
    }
    log_printf("SetPixelFormat: OK pf=%d GetPixelFormat=%d", pf, GetPixelFormat(g_dc));

    SetLastError(0);
    g_rc = wglCreateContext(g_dc);
    err = GetLastError();
    log_printf("wglCreateContext: hglrc=%08lX error=%lu", (DWORD)g_rc, err);
    if (!g_rc) {
        MessageBox(hwnd, "wglCreateContext failed. See TESTGL.LOG.", "TESTGL", MB_OK | MB_ICONERROR);
        if (g_log) fclose(g_log);
        return 3;
    }

    SetLastError(0);
    if (!wglMakeCurrent(g_dc, g_rc)) {
        err = GetLastError();
        log_printf("wglMakeCurrent failed: error=%lu", err);
        MessageBox(hwnd, "wglMakeCurrent failed. See TESTGL.LOG.", "TESTGL", MB_OK | MB_ICONERROR);
        if (g_log) fclose(g_log);
        return 3;
    }
    log_printf("wglMakeCurrent: OK");

    show_renderer_info(hwnd, pf);

    glClearColor(0.08f, 0.10f, 0.18f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (ty = 0; ty < 8; ++ty) {
        for (tx = 0; tx < 8; ++tx) {
            int i = (ty * 8 + tx) * 4;
            GLubyte v = ((tx ^ ty) & 1) ? 255 : 48;
            checker[i + 0] = v;
            checker[i + 1] = ((tx ^ ty) & 1) ? 210 : 72;
            checker[i + 2] = ((tx ^ ty) & 1) ? 64 : 255;
            checker[i + 3] = 255;
            checker2[i + 0] = ((tx / 2) & 1) ? 255 : 40;
            checker2[i + 1] = ((tx / 2) & 1) ? 64 : 180;
            checker2[i + 2] = ((tx / 2) & 1) ? 80 : 255;
            checker2[i + 3] = 255;
        }
    }
    for (ty = 0; ty < 8; ++ty) {
        for (tx = 0; tx < 8; ++tx) {
            int i = (ty * 8 + tx) * 4;
            pixelBlock[i + 0] = (tx & 1) ? 255 : 0;
            pixelBlock[i + 1] = (ty & 1) ? 255 : 0;
            pixelBlock[i + 2] = ((tx ^ ty) & 1) ? 255 : 0;
            pixelBlock[i + 3] = 255;
        }
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    textures[0] = textures[1] = 0;
    glGenTextures(2, textures);
    log_printf("Phase 5i glGenTextures: names=%lu,%lu prebind_isTexture=%u,%u",
        (DWORD)textures[0], (DWORD)textures[1], glIsTexture(textures[0]) ? 1U : 0U, glIsTexture(textures[1]) ? 1U : 0U);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, checker);

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, checker2);
    log_printf("Phase 5i postbind isTexture=%u,%u", glIsTexture(textures[0]) ? 1U : 0U, glIsTexture(textures[1]) ? 1U : 0U);

    glDeleteTextures(1, &textures[1]);
    log_printf("Phase 5i delete second texture isTexture=%u", glIsTexture(textures[1]) ? 1U : 0U);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glerr = glGetError();
    log_printf("Phase 5i texture-object/array setup: glGetError=0x%04X expected=0", (unsigned)glerr);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpecular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_MODE, (GLfloat)GL_LINEAR);
    glFogf(GL_FOG_START, 0.0f);
    glFogf(GL_FOG_END, 1.0f);
    glGetLightfv(GL_LIGHT0, GL_POSITION, query4);
    log_printf("Phase 5i light0 position: %.2f %.2f %.2f %.2f", query4[0], query4[1], query4[2], query4[3]);
    glGetMaterialfv(GL_FRONT, GL_DIFFUSE, query4);
    log_printf("Phase 5i material diffuse: %.2f %.2f %.2f %.2f", query4[0], query4[1], query4[2], query4[3]);
    glerr = glGetError();
    log_printf("Phase 5i lighting/fog setup: glGetError=0x%04X expected=0", (unsigned)glerr);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_FOG_HINT, GL_FASTEST);
    glGetIntegerv(GL_PERSPECTIVE_CORRECTION_HINT, &hintQuery);
    log_printf("Phase 5i perspective hint: 0x%04X expected=0x%04X", (unsigned)hintQuery, (unsigned)GL_NICEST);
    glGetIntegerv(GL_FOG_HINT, &hintQuery);
    log_printf("Phase 5i fog hint: 0x%04X expected=0x%04X", (unsigned)hintQuery, (unsigned)GL_FASTEST);
    GetClientRect(hwnd, &clientRc);
    glScissor((clientRc.right - clientRc.left) * 3 / 4, (clientRc.bottom - clientRc.top) / 4,
        (clientRc.right - clientRc.left) / 4, (clientRc.bottom - clientRc.top) / 2);
    glGetIntegerv(GL_SCISSOR_BOX, scissorQuery);
    log_printf("Phase 5i scissor box: %d,%d %dx%d", scissorQuery[0], scissorQuery[1], scissorQuery[2], scissorQuery[3]);
    glerr = glGetError();
    log_printf("Phase 5i scissor/hint setup: glGetError=0x%04X expected=0", (unsigned)glerr);
    glClearStencil(0);
    glStencilMask(0x0F);
    glStencilFunc(GL_ALWAYS, 1, 0x0F);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    glerr = glGetError();
    log_printf("Phase 5i stencil setup: stencilBits=%u glGetError=0x%04X expected=0", (unsigned)actual.cStencilBits, (unsigned)glerr);
    glPointSize(7.0f);
    glLineWidth(5.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glGetFloatv(GL_POINT_SIZE, &pointQuery);
    glGetFloatv(GL_LINE_WIDTH, &lineQuery);
    glGetIntegerv(GL_POLYGON_MODE, polygonQuery);
    glerr = glGetError();
    log_printf("Phase 5i raster state: point=%.1f line=%.1f polygon=%04X/%04X glGetError=0x%04X expected=0", pointQuery, lineQuery, (unsigned)polygonQuery[0], (unsigned)polygonQuery[1], (unsigned)glerr);
    glLineStipple(3, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
    { GLint stipplePattern=0, stippleRepeat=0; glGetIntegerv(GL_LINE_STIPPLE_PATTERN,&stipplePattern); glGetIntegerv(GL_LINE_STIPPLE_REPEAT,&stippleRepeat); log_printf("Phase 5i line stipple: enabled=%u factor=%d pattern=%04X", glIsEnabled(GL_LINE_STIPPLE)?1U:0U, stippleRepeat, (unsigned)(stipplePattern & 0xffff)); }
    glDisable(GL_LINE_STIPPLE);
    { int i; for(i=0;i<128;++i) polygonStipple[i]=(GLubyte)(((i & 4) ? 0xAA : 0x55)); }
    memset(polygonStippleReadback,0,sizeof(polygonStippleReadback));
    glPolygonStipple(polygonStipple);
    glGetPolygonStipple(polygonStippleReadback);
    glEnable(GL_POLYGON_STIPPLE);
    log_printf("Phase 5i polygon stipple: enabled=%u readback=%s", glIsEnabled(GL_POLYGON_STIPPLE)?1U:0U, memcmp(polygonStipple,polygonStippleReadback,128)==0?"OK":"FAIL");
    glDisable(GL_POLYGON_STIPPLE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPointSize(1.0f);
    glLineWidth(1.0f);

    glColor4f(0.15f, 0.25f, 0.35f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLineWidth(1.0f);
    glDisable(GL_BLEND);
    glFogf(GL_FOG_DENSITY, 0.35f);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glGetFloatv(GL_CURRENT_COLOR, colorBeforeList);
    glGetFloatv(GL_MODELVIEW_MATRIX, modelviewBeforeList);
    glGetFloatv(GL_LINE_WIDTH, &lineWidthBeforeList);
    glGetFloatv(GL_FOG_DENSITY, &fogDensityBeforeList);
    glGetMaterialfv(GL_FRONT, GL_DIFFUSE, materialBeforeList);
    glGetLightfv(GL_LIGHT0, GL_DIFFUSE, lightBeforeList);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &texFilterBeforeList);
    glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &texEnvBeforeList);
    glGetIntegerv(GL_COLOR_MATERIAL_PARAMETER, &colorMaterialBeforeList);
    displayLists = glGenLists(3);
    displayListIndices[0] = 0; displayListIndices[1] = 1;
    if (displayLists) {
        glNewList(displayLists, GL_COMPILE);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(-0.80f, 0.57f, 0.0f);
        glColor3f(1.0f, 0.2f, 0.8f);
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.12f, -0.09f, 0.0f);
        glVertex3f( 0.12f, -0.09f, 0.0f);
        glVertex3f( 0.00f,  0.09f, 0.0f);
        glEnd();
        glPopMatrix();
        glEndList();

        glNewList(displayLists + 1, GL_COMPILE);
        glLineWidth(3.0f);
        glLineStipple(2, 0x0F0F);
        glEnable(GL_LINE_STIPPLE);
        glColor3f(0.2f, 1.0f, 0.85f);
        glBegin(GL_LINES);
        glVertex3f(-0.62f, 0.57f, 0.0f);
        glVertex3f(-0.38f, 0.57f, 0.0f);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        glEndList();

        glNewList(displayLists + 2, GL_COMPILE);
        glMatrixMode(GL_MODELVIEW);
        glTranslatef(0.25f, 0.0f, 0.0f);
        glLineWidth(9.0f);
        glEnable(GL_BLEND);
        glFogf(GL_FOG_DENSITY, 0.72f);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, listLightDiffuse);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, listLightAmbient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, listMaterialDiffuse);
        glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glEndList();
    }
    glGetFloatv(GL_CURRENT_COLOR, colorAfterList);
    glGetFloatv(GL_MODELVIEW_MATRIX, modelviewAfterList);
    glGetFloatv(GL_LINE_WIDTH, &lineWidthAfterList);
    glGetFloatv(GL_FOG_DENSITY, &fogDensityAfterList);
    glGetMaterialfv(GL_FRONT, GL_DIFFUSE, materialAfterList);
    glGetLightfv(GL_LIGHT0, GL_DIFFUSE, lightAfterList);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &texFilterAfterList);
    glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &texEnvAfterList);
    glGetIntegerv(GL_COLOR_MATERIAL_PARAMETER, &colorMaterialAfterList);
    log_printf("Phase 5i display lists: base=%lu isList=%u,%u,%u compile_preserves color=%s matrix=%s line=%s fog=%s material=%s light=%s texture=%s", (DWORD)displayLists,
        displayLists ? (glIsList(displayLists) ? 1U : 0U) : 0U,
        displayLists ? (glIsList(displayLists + 1) ? 1U : 0U) : 0U,
        displayLists ? (glIsList(displayLists + 2) ? 1U : 0U) : 0U,
        memcmp(colorBeforeList, colorAfterList, sizeof(colorBeforeList)) == 0 ? "YES" : "NO",
        memcmp(modelviewBeforeList, modelviewAfterList, sizeof(modelviewBeforeList)) == 0 ? "YES" : "NO",
        lineWidthBeforeList == lineWidthAfterList ? "YES" : "NO",
        fogDensityBeforeList == fogDensityAfterList ? "YES" : "NO",
        memcmp(materialBeforeList, materialAfterList, sizeof(materialBeforeList)) == 0 ? "YES" : "NO",
        memcmp(lightBeforeList, lightAfterList, sizeof(lightBeforeList)) == 0 ? "YES" : "NO",
        (texFilterBeforeList == texFilterAfterList && texEnvBeforeList == texEnvAfterList && colorMaterialBeforeList == colorMaterialAfterList) ? "YES" : "NO");
    if (displayLists) glCallList(displayLists + 2);
    glGetFloatv(GL_FOG_DENSITY, &fogDensityAfterList);
    glGetMaterialfv(GL_FRONT, GL_DIFFUSE, materialAfterList);
    glGetLightfv(GL_LIGHT0, GL_DIFFUSE, lightAfterList);
    glGetTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, &texFilterAfterList);
    glGetTexEnviv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, &texEnvAfterList);
    glGetIntegerv(GL_COLOR_MATERIAL_PARAMETER, &colorMaterialAfterList);
    log_printf("Phase 5i display-list replay: fog=%.2f material=%.2f/%.2f/%.2f light=%.2f/%.2f/%.2f minFilter=%04X env=%04X colorMaterial=%04X",
        fogDensityAfterList, materialAfterList[0], materialAfterList[1], materialAfterList[2], lightAfterList[0], lightAfterList[1], lightAfterList[2],
        (unsigned)texFilterAfterList, (unsigned)texEnvAfterList, (unsigned)colorMaterialAfterList);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glLineWidth(1.0f); glDisable(GL_BLEND);
    glFogf(GL_FOG_DENSITY, 0.35f); glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse); glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glerr = glGetError();
    log_printf("Phase 5i display-list lighting/fog/texture setup: glGetError=0x%04X expected=0", (unsigned)glerr);
    log_printf("Phase 5i display: first list uses matrix push/translate/pop; second uses line width/stipple state; third validates lighting/fog/texture state replay.");

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGetIntegerv(GL_PACK_ALIGNMENT, &packAlignmentQuery);
    glGetIntegerv(GL_UNPACK_ALIGNMENT, &unpackAlignmentQuery);
    glClear(GL_COLOR_BUFFER_BIT);
    glRasterPos2f(0.62f, 0.58f);
    glGetFloatv(GL_CURRENT_RASTER_POSITION, rasterPos);
    memset(pixelReadback, 0, sizeof(pixelReadback));
    glDrawPixels(8, 8, GL_RGBA, GL_UNSIGNED_BYTE, pixelBlock);
    glReadPixels((GLint)rasterPos[0], (GLint)rasterPos[1], 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, pixelReadback);
    glRasterPos2f(0.72f, 0.58f);
    {
        GLfloat copyPos[4];
        glGetFloatv(GL_CURRENT_RASTER_POSITION, copyPos);
        glCopyPixels((GLint)rasterPos[0], (GLint)rasterPos[1], 8, 8, GL_COLOR);
        memset(pixelCopyReadback, 0, sizeof(pixelCopyReadback));
        glReadPixels((GLint)copyPos[0], (GLint)copyPos[1], 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, pixelCopyReadback);
    }
    glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &rasterValidQuery);
    glerr = glGetError();
    log_printf("Phase 5i pixel path: pack=%d unpack=%d draw/read=%s copy/read=%s raster=%.1f,%.1f valid=%u glGetError=0x%04X expected=0",
        packAlignmentQuery, unpackAlignmentQuery,
        memcmp(pixelBlock, pixelReadback, sizeof(pixelBlock)) == 0 ? "OK" : "FAIL",
        memcmp(pixelBlock, pixelCopyReadback, sizeof(pixelBlock)) == 0 ? "OK" : "FAIL",
        rasterPos[0], rasterPos[1], rasterValidQuery ? 1U : 0U, (unsigned)glerr);
    log_printf("Phase 5i pixel support: glRasterPos + glDrawPixels + glReadPixels + glCopyPixels + PACK/UNPACK alignment.");

    while (running) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) { running = FALSE; break; }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if (!running) break;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glDisable(GL_TEXTURE_2D);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, triVertices);
        glColorPointer(4, GL_UNSIGNED_BYTE, 0, triColors);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        glEnable(GL_STENCIL_TEST);
        glStencilMask(0x0F);
        glStencilFunc(GL_ALWAYS, 1, 0x0F);
        glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        glDisable(GL_LIGHTING);
        glDisable(GL_FOG);
        glColor3f(0.08f, 0.10f, 0.18f);
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.22f, -0.40f, 0.0f);
        glVertex3f( 0.22f, -0.40f, 0.0f);
        glVertex3f( 0.00f,  0.42f, 0.0f);
        glEnd();

        glStencilMask(0x00);
        glStencilFunc(GL_EQUAL, 1, 0x0F);
        glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_FOG);
        glBegin(GL_TRIANGLES);
        glNormal3f(-0.45f, 0.0f, 1.0f);
        glVertex3f(-0.30f, -0.54f, -0.10f);
        glNormal3f(0.45f, 0.0f, 1.0f);
        glVertex3f(0.30f, -0.54f, -0.55f);
        glNormal3f(0.0f, 0.55f, 1.0f);
        glVertex3f(0.00f, 0.62f, -0.90f);
        glEnd();
        glDisable(GL_STENCIL_TEST);
        glDisable(GL_FOG);
        glDisable(GL_NORMALIZE);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);

        GetClientRect(hwnd, &clientRc);
        glScissor((clientRc.right - clientRc.left) * 3 / 4, (clientRc.bottom - clientRc.top) / 4,
            (clientRc.right - clientRc.left) / 4, (clientRc.bottom - clientRc.top) / 2);
        glEnable(GL_SCISSOR_TEST);
        glClearColor(0.16f, 0.20f, 0.30f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.08f, 0.10f, 0.18f, 1.0f);
        glEnable(GL_TEXTURE_2D);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColor3f(1.0f, 1.0f, 1.0f);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, quadVertices);
        glTexCoordPointer(2, GL_FLOAT, 0, quadTexCoords);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_SHORT, quadIndices);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_SCISSOR_TEST);

        glDisable(GL_STENCIL_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_FOG);
        glColor3f(1.0f, 0.9f, 0.2f);
        glPointSize(7.0f);
        glBegin(GL_POINTS);
        glVertex3f(-0.90f, 0.84f, 0.0f);
        glEnd();
        glColor3f(0.2f, 0.9f, 1.0f);
        glLineWidth(5.0f);
        glLineStipple(3, 0x00FF);
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINES);
        glVertex3f(-0.78f, 0.84f, 0.0f);
        glVertex3f(-0.32f, 0.84f, 0.0f);
        glEnd();
        glDisable(GL_LINE_STIPPLE);
        glColor3f(0.4f, 1.0f, 0.4f);
        glLineWidth(3.0f);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.18f, 0.72f, 0.0f);
        glVertex3f( 0.18f, 0.72f, 0.0f);
        glVertex3f( 0.00f, 0.96f, 0.0f);
        glEnd();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(1.0f, 0.45f, 0.15f);
        glEnable(GL_POLYGON_STIPPLE);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.26f, 0.72f, 0.0f);
        glVertex3f(0.62f, 0.72f, 0.0f);
        glVertex3f(0.44f, 0.96f, 0.0f);
        glEnd();
        glDisable(GL_POLYGON_STIPPLE);
        glPointSize(1.0f);
        glLineWidth(1.0f);

        if (displayLists) {
            glListBase(displayLists);
            glCallLists(2, GL_UNSIGNED_BYTE, displayListIndices);
            glLineWidth(1.0f);
        }

        glPixelZoom(2.0f, 2.0f);
        glRasterPos2f(0.70f, 0.76f);
        glDrawPixels(8, 8, GL_RGBA, GL_UNSIGNED_BYTE, pixelBlock);
        glPixelZoom(1.0f, 1.0f);

        SwapBuffers(g_dc);
        Sleep(10);
    }

    if (displayLists) {
        glDeleteLists(displayLists, 3);
        log_printf("Phase 5i display-list delete: isList=%u,%u,%u", glIsList(displayLists) ? 1U : 0U, glIsList(displayLists + 1) ? 1U : 0U, glIsList(displayLists + 2) ? 1U : 0U);
    }
    log_printf("Shutting down.");
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(g_rc);
    ReleaseDC(hwnd, g_dc);
    if (g_log) fclose(g_log);
    return 0;
}
