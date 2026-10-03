#include <windows.h>
#include <stdlib.h>
#include "NPDMODE.H"

#define SYSTEM_INI "SYSTEM.INI"

char g_szAppName[] = "NPDISP Mode Utility";

static void LoadCurrentSettings(HWND hwnd);
static void ApplySettings(HWND hwnd);
static LPCSTR GetFileNamePart(LPCSTR path);
static BOOL CheckNP2VDDGrabber(void);
static void InitExtendedSettings(HWND hwnd);
static void LoadExtendedSettings(HWND hwnd);
static void ApplyExtendedSettings(HWND hwnd);

static HINSTANCE g_hInst;
static BOOL g_fExtendedSettings;

static void AskRestartWindows(HWND hwnd)
{
    int r;

    r = MessageBox(
        hwnd,
        "設定を反映するにはWindowsを再起動する必要があります。\r\n今すぐWindowsを再起動しますか？",
        g_szAppName,
        MB_YESNO | MB_ICONQUESTION);

    if (r == IDYES)
    {
        ExitWindows(EW_RESTARTWINDOWS, 0);
    }
}

static void AddBppItem(HWND hwnd, LPCSTR text, int value)
{
    int idx;

    idx = (int)SendDlgItemMessage(
        hwnd,
        IDC_BPP,
        CB_ADDSTRING,
        0,
        (LPARAM)(LPSTR)text);

    if (idx != CB_ERR)
    {
        SendDlgItemMessage(
            hwnd,
            IDC_BPP,
            CB_SETITEMDATA,
            idx,
            value);
    }
}

static void SetDialogFont(HWND hwnd, HWND hctl)
{
    HFONT hfont;

    if (!hctl)
        return;

    hfont = (HFONT)SendMessage(hwnd, WM_GETFONT, 0, 0);
    if (hfont)
        SendMessage(hctl, WM_SETFONT, (WPARAM)hfont, 0);
}

static HWND CreateDlgControl(
    HWND hwnd,
    LPCSTR cls,
    LPCSTR text,
    DWORD style,
    int id,
    int x,
    int y,
    int cx,
    int cy)
{
    RECT r;
    HWND hctl;

    r.left = x;
    r.top = y;
    r.right = x + cx;
    r.bottom = y + cy;
    MapDialogRect(hwnd, &r);

    hctl = CreateWindow(
        cls,
        text,
        WS_CHILD | WS_VISIBLE | style,
        r.left,
        r.top,
        r.right - r.left,
        r.bottom - r.top,
        hwnd,
        (HMENU)id,
        g_hInst,
        NULL);

    SetDialogFont(hwnd, hctl);
    return hctl;
}

static void MoveDlgItemDown(HWND hwnd, int id, int dy)
{
    HWND hctl;
    RECT r;
    POINT pt;

    hctl = GetDlgItem(hwnd, id);
    if (!hctl)
        return;

    GetWindowRect(hctl, &r);
    pt.x = r.left;
    pt.y = r.top;
    ScreenToClient(hwnd, &pt);

    SetWindowPos(
        hctl,
        NULL,
        pt.x,
        pt.y + dy,
        r.right - r.left,
        r.bottom - r.top,
        SWP_NOZORDER | SWP_NOACTIVATE);
}

static void InitExtendedSettings(HWND hwnd)
{
    RECT wr;
    RECT dr;
    int dy;

    dr.left = 0;
    dr.top = 0;
    dr.right = 0;
    dr.bottom = 72;
    MapDialogRect(hwnd, &dr);
    dy = dr.bottom;

    GetWindowRect(hwnd, &wr);
    SetWindowPos(
        hwnd,
        NULL,
        0,
        0,
        wr.right - wr.left,
        (wr.bottom - wr.top) + dy,
        SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

    MoveDlgItemDown(hwnd, IDOK, dy);
    MoveDlgItemDown(hwnd, IDCANCEL, dy);

    CreateDlgControl(
        hwnd, "BUTTON", "DOS窓グラフィック",
        BS_GROUPBOX, IDC_NP2_GROUP, 8, 52, 164, 74);
    CreateDlgControl(
        hwnd, "BUTTON", "ウィンドウモード拡張有効",
        BS_AUTOCHECKBOX | WS_TABSTOP, IDC_NP2_USEGRAPH, 15, 64, 145, 10);
    CreateDlgControl(
        hwnd, "BUTTON", "256色モードでGDI描画を使用",
        BS_AUTOCHECKBOX | WS_TABSTOP, IDC_NP2_USEDIB8, 15, 76, 145, 10);
    CreateDlgControl(
        hwnd, "BUTTON", "多色でも256色DIB経由で描画",
        BS_AUTOCHECKBOX | WS_TABSTOP, IDC_NP2_USEDIB8HC, 15, 88, 145, 10);
    CreateDlgControl(
        hwnd, "STATIC", "白黒変換モード:",
        0, IDC_NP2_MONOLABEL, 15, 102, 145, 10);
    CreateDlgControl(
        hwnd, "BUTTON", "輝度",
        BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP,
        IDC_NP2_MONOMODE_LUMA, 22, 112, 40, 10);
    CreateDlgControl(
        hwnd, "BUTTON", "0以外",
        BS_AUTORADIOBUTTON | WS_TABSTOP,
        IDC_NP2_MONOMODE_NONZERO, 66, 112, 40, 10);
    CreateDlgControl(
        hwnd, "BUTTON", "ディザ",
        BS_AUTORADIOBUTTON | WS_TABSTOP,
        IDC_NP2_MONOMODE_DITHER, 110, 112, 40, 10);

    LoadExtendedSettings(hwnd);
}

BOOL CALLBACK __export MainDlgProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_INITDIALOG:
    {
        char buf[32];
        HICON hIcon;
	    int currentBpp;
	    int count;
	    int i;
    
        hIcon = LoadIcon(g_hInst, "APPICON");
    
        if (hIcon)
        {
            SetClassWord(hwnd, GCW_HICON, (WORD)hIcon);
        }
    
        AddBppItem(hwnd, "1 (白黒)", 1);
        AddBppItem(hwnd, "4 (16色)", 4);
        AddBppItem(hwnd, "8 (256色)", 8);
        AddBppItem(hwnd, "15", 15);
        AddBppItem(hwnd, "16 (64K色)", 16);
        AddBppItem(hwnd, "24 (16M色)", 24);
        AddBppItem(hwnd, "32", 32);
        
        LoadCurrentSettings(hwnd);

        g_fExtendedSettings = CheckNP2VDDGrabber();
        if (g_fExtendedSettings)
            InitExtendedSettings(hwnd);
        
        GetPrivateProfileString(
            "npdisp.drv",
            "bpp",
            "8",
            buf,
            sizeof(buf),
            SYSTEM_INI);
        
        currentBpp = atoi(buf);
    
        count = (int)SendDlgItemMessage(
            hwnd,
            IDC_BPP,
            CB_GETCOUNT,
            0,
            0);
        
        for (i = 0; i < count; i++)
        {
            if ((int)SendDlgItemMessage(
                    hwnd,
                    IDC_BPP,
                    CB_GETITEMDATA,
                    i,
                    0) == currentBpp)
            {
                SendDlgItemMessage(
                    hwnd,
                    IDC_BPP,
                    CB_SETCURSEL,
                    i,
                    0);
        
                break;
            }
        }
        return TRUE;
    }
    case WM_COMMAND:
        switch (LOWORD(wp))
        {
        case IDOK:
            ApplySettings(hwnd);
            return TRUE;

        case IDCANCEL:
            EndDialog(hwnd, 0);
            return TRUE;
        }
        break;
    }

    return FALSE;
}
          
static void LoadCurrentSettings(HWND hwnd)
{      
    char buf[64];                  
    
    if(GetPrivateProfileString(
        "npdisp.drv",
        "width",
        "640",
        buf,
        sizeof(buf),
        SYSTEM_INI)==0) {  
    	buf[0] = '\0';
    }
    
    SetDlgItemText(hwnd, IDC_WIDTH, buf);
    
    if(GetPrivateProfileString(
        "npdisp.drv",
        "height",
        "480",
        buf,
        sizeof(buf),
   		SYSTEM_INI)==0) {  
    	buf[0] = '\0';
    }

    SetDlgItemText(hwnd, IDC_HEIGHT, buf);
    
    if(GetPrivateProfileString(
        "npdisp.drv",
        "bpp",
        "8",
        buf,
        sizeof(buf),
    	SYSTEM_INI)==0) {  
    	buf[0] = '\0';
    }

    SetDlgItemText(hwnd, IDC_BPP, buf);
}

static void LoadExtendedSettings(HWND hwnd)
{
    int mono;

    CheckDlgButton(
        hwnd,
        IDC_NP2_USEGRAPH,
        GetPrivateProfileInt("386Enh", "NP2UseGraph", 0, SYSTEM_INI) ? 1 : 0);
    CheckDlgButton(
        hwnd,
        IDC_NP2_USEDIB8,
        GetPrivateProfileInt("386Enh", "NP2UseDIB8", 0, SYSTEM_INI) ? 1 : 0);
    CheckDlgButton(
        hwnd,
        IDC_NP2_USEDIB8HC,
        GetPrivateProfileInt("386Enh", "NP2UseDIB8HC", 0, SYSTEM_INI) ? 1 : 0);

    mono = GetPrivateProfileInt("386Enh", "NP2MonoMode", 0, SYSTEM_INI);
    if (mono < 0 || mono > 2)
        mono = 0;

    CheckRadioButton(
        hwnd,
        IDC_NP2_MONOMODE_LUMA,
        IDC_NP2_MONOMODE_DITHER,
        IDC_NP2_MONOMODE_LUMA + mono);
}

static void ApplyExtendedSettings(HWND hwnd)
{
    char buf[8];
    int mono;

    WritePrivateProfileString(
        "386Enh",
        "NP2UseGraph",
        IsDlgButtonChecked(hwnd, IDC_NP2_USEGRAPH) ? "1" : "0",
        SYSTEM_INI);
    WritePrivateProfileString(
        "386Enh",
        "NP2UseDIB8",
        IsDlgButtonChecked(hwnd, IDC_NP2_USEDIB8) ? "1" : "0",
        SYSTEM_INI);
    WritePrivateProfileString(
        "386Enh",
        "NP2UseDIB8HC",
        IsDlgButtonChecked(hwnd, IDC_NP2_USEDIB8HC) ? "1" : "0",
        SYSTEM_INI);

    mono = 0;
    if (IsDlgButtonChecked(hwnd, IDC_NP2_MONOMODE_NONZERO))
        mono = 1;
    else if (IsDlgButtonChecked(hwnd, IDC_NP2_MONOMODE_DITHER))
        mono = 2;

    wsprintf(buf, "%d", mono);
    WritePrivateProfileString(
        "386Enh",
        "NP2MonoMode",
        buf,
        SYSTEM_INI);
}

static BOOL ValidateBPP(int bpp)
{
    switch (bpp)
    {
    case 1:
    case 4:
    case 8:
    case 15:
    case 16:
    case 24:
    case 32:
        return TRUE;
    }

    return FALSE;
}

static void ApplySettings(HWND hwnd)
{
    char buf[64];

    int width;
    int height;
    int bpp;
    int sel;

    char desc[128];

    GetDlgItemText(hwnd, IDC_WIDTH, buf, sizeof(buf));
    width = atoi(buf);

    GetDlgItemText(hwnd, IDC_HEIGHT, buf, sizeof(buf));
    height = atoi(buf);

    sel = (int)SendDlgItemMessage(
        hwnd,
        IDC_BPP,
        CB_GETCURSEL,
        0,
        0);
    
    if (sel == CB_ERR)
    {
        MessageBox(
            hwnd,
            "色深度を選択してください。",
            g_szAppName,
            MB_OK | MB_ICONEXCLAMATION);
        return;
    }
    bpp = (int)SendDlgItemMessage(hwnd, IDC_BPP, CB_GETITEMDATA, sel, 0);

    if (width < 320 || height < 200)
    {
        MessageBox(
            hwnd,
            "画面サイズが小さすぎます。",
            g_szAppName,
            MB_OK | MB_ICONEXCLAMATION);

        return;
    }
    if (width > 4096 || height > 4096)
    {
        MessageBox(
            hwnd,
            "4096pxを超える画面サイズにはできません。",
            g_szAppName,
            MB_OK | MB_ICONEXCLAMATION);

        return;
    }

    if (!ValidateBPP(bpp))
    {
        MessageBox(
            hwnd,
            "指定された色深度は無効です。\r\n\r\n可能な設定: 1, 4, 8, 15, 16, 24, 32",
            g_szAppName,
            MB_OK | MB_ICONEXCLAMATION);

        return;
    }

    wsprintf(buf, "%d", width);
    WritePrivateProfileString(
        "npdisp.drv",
        "width",
        buf,
        SYSTEM_INI);

    wsprintf(buf, "%d", height);
    WritePrivateProfileString(
        "npdisp.drv",
        "height",
        buf,
        SYSTEM_INI);

    wsprintf(buf, "%d", bpp);
    WritePrivateProfileString(
        "npdisp.drv",
        "bpp",
        buf,
        SYSTEM_INI);

    if (g_fExtendedSettings)
        ApplyExtendedSettings(hwnd);

    wsprintf(
        desc,
        "Neko Project 21/W %dx%d %dbpp",
        width,
        height,
        bpp);

    WritePrivateProfileString(
        "boot.description",
        "display.drv",
        desc,
        SYSTEM_INI);

    /*
        Flush SYSTEM.INI
    */
    WritePrivateProfileString(NULL, NULL, NULL, SYSTEM_INI);

    AskRestartWindows(hwnd);
    EndDialog(hwnd, IDOK);
}

static LPCSTR GetFileNamePart(LPCSTR path)
{
    LPCSTR p;
    LPCSTR last;

    last = path;

    for (p = path; *p; p++)
    {
        if (*p == '\\' || *p == '/' || *p == ':')
        {
            last = p + 1;
        }
    }

    return last;
}

static BOOL ValueMatchesFileName(LPCSTR value, LPCSTR expected)
{
    char token[128];
    LPCSTR p;
    LPCSTR fname;
    int i;

    p = value;
    while (*p == ' ' || *p == '\t' || *p == '\"')
        p++;

    fname = GetFileNamePart(p);
    i = 0;
    while (*fname &&
           *fname != ' ' && *fname != '\t' &&
           *fname != ',' && *fname != ';' && *fname != '\"' &&
           i < (int)sizeof(token) - 1)
    {
        token[i++] = *fname++;
    }
    token[i] = '\0';

    return (lstrcmpi(token, expected) == 0);
}

static BOOL CheckNP2VDDGrabber(void)
{
    char grabber[128];
    char vdd[128];
    DWORD len;

    len = GetPrivateProfileString(
        "boot",
        "386grabber",
        "",
        grabber,
        sizeof(grabber),
        SYSTEM_INI);
    if (len == 0 || !ValueMatchesFileName(grabber, "GRABNP2.3GR"))
        return FALSE;

    /*
     * The PC-98 VDD is normally the [386Enh] display driver.
     * Also accept a device= entry for installations that load it that way.
     */
    len = GetPrivateProfileString(
        "386Enh",
        "display",
        "",
        vdd,
        sizeof(vdd),
        SYSTEM_INI);
    if (len != 0 && ValueMatchesFileName(vdd, "VDDNP2.386"))
        return TRUE;

    len = GetPrivateProfileString(
        "386Enh",
        "device",
        "",
        vdd,
        sizeof(vdd),
        SYSTEM_INI);
    if (len != 0 && ValueMatchesFileName(vdd, "VDDNP2.386"))
        return TRUE;

    return FALSE;
}

static BOOL CheckCurrentDriver(void)
{
    char drv[128];
    LPCSTR fname;
    DWORD len;

    len = GetPrivateProfileString(
        "boot",
        "display.drv",
        "",
        drv,
        sizeof(drv),
        SYSTEM_INI);
    
    if (len==0 || len > 100){
        MessageBox(
            NULL,
            "現在のディスプレイドライバを取得できませんでした。",
            g_szAppName,
            MB_OK | MB_ICONSTOP);

        return FALSE;
    }

    fname = GetFileNamePart(drv);

    if (lstrcmpi(fname, "npdisp.drv") != 0)
    {
        MessageBox(
            NULL,
            "現在のディスプレイドライバはNPDISPではありません。",
            g_szAppName,
            MB_OK | MB_ICONSTOP);

        return FALSE;
    }

    return TRUE;
}

int PASCAL WinMain(
    HINSTANCE hInst,
    HINSTANCE hPrev,
    LPSTR lpCmdLine,
    int nCmdShow)
{
	FARPROC lpfnDlg;
	
    if (hPrev)
    {
        MessageBox(
            NULL,
            "既に起動しています。",
            g_szAppName,
            MB_OK | MB_ICONINFORMATION);

        return 0;
    }
    	
	g_hInst = hInst;
	
    if (!CheckCurrentDriver())
        return 0;

	lpfnDlg = MakeProcInstance((FARPROC)MainDlgProc, hInst);
    DialogBox(
        hInst,
        MAKEINTRESOURCE(IDD_MAIN),
        NULL,
        lpfnDlg);
    
    FreeProcInstance((FARPROC)MainDlgProc);

    return 0;
}
