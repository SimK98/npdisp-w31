#include <windows.h>
#include <stdlib.h>
#include "NPDMODE.H"

#define SYSTEM_INI "SYSTEM.INI"

char g_szAppName[] = "NPDISP Mode Utility";

static void LoadCurrentSettings(HWND hwnd);
static void ApplySettings(HWND hwnd);

static HINSTANCE g_hInst;

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

BOOL CALLBACK MainDlgProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
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

    GetPrivateProfileString(
        "npdisp.drv",
        "width",
        "640",
        buf,
        sizeof(buf),
        SYSTEM_INI);

    SetDlgItemText(hwnd, IDC_WIDTH, buf);

    GetPrivateProfileString(
        "npdisp.drv",
        "height",
        "480",
        buf,
        sizeof(buf),
        SYSTEM_INI);

    SetDlgItemText(hwnd, IDC_HEIGHT, buf);

    GetPrivateProfileString(
        "npdisp.drv",
        "bpp",
        "8",
        buf,
        sizeof(buf),
        SYSTEM_INI);

    SetDlgItemText(hwnd, IDC_BPP, buf);
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

    DialogBox(
        hInst,
        MAKEINTRESOURCE(IDD_MAIN),
        NULL,
        MainDlgProc);

    return 0;
}
