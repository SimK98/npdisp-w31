#include <windows.h>

#define ESC_ON  0x7222
#define ESC_OFF 0x7223

int PASCAL WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    HDC hdc;
    int escapeCode;

    while (*lpCmdLine == ' ' || *lpCmdLine == '\t')
        ++lpCmdLine;

    if (*lpCmdLine == '\0')
    {
        escapeCode = ESC_ON;
    }
    else if (lstrcmpi(lpCmdLine, "ON") == 0)
    {
        escapeCode = ESC_ON;
    }
    else if (lstrcmpi(lpCmdLine, "OFF") == 0)
    {
        escapeCode = ESC_OFF;
    }
    else
    {
        return 1;
    }

    hdc = GetDC(NULL);

    if (hdc != NULL)
    {
        Escape(hdc, escapeCode, 0, NULL, NULL);

        ReleaseDC(NULL, hdc);
    }

    return 0;
}
