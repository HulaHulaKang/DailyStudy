#include <windows.h>
#include<stdio.h>
#include<Tchar.h>

void tip() { MessageBox(NULL, TEXT("此功能未实现"), TEXT("TIP"), MB_OK); }
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND hEdit;
TCHAR file_name[100];


const UINT_PTR MENU_FILE_NEW = 11;
const UINT_PTR MENU_FILE_OPEN = 12;
const UINT_PTR MENU_FILE_SAVE = 13;
const UINT_PTR MENU_FILE_ANOTHER = 14;

const UINT_PTR MENU_LOOK_BGCOLOR = 21;
const UINT_PTR MENU_LOOK_FONT = 22;
const UINT_PTR MENU_LOOK_TITLE = 23;
const UINT_PTR MENU_LOOK_BORDER = 24;


const UINT_PTR MENU_ABOUT = 31;

const int x_of_main_window = 500;
const int  y_of_main_window = 500;

int WINAPI wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ PWSTR pCmdLine,_In_ int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("注册失败!"),szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName,                  // window class name
        TEXT("PL Editor"), // window caption
        WS_OVERLAPPEDWINDOW,        // window style
        100,              // initial x position
        100,              // initial y position
        x_of_main_window,              // initial x size
        y_of_main_window,              // initial y size
        NULL,                       // parent window handle
        NULL,                       // window menu handle
        hInstance,                  // program instance handle
        NULL);                     // creation parameters

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    switch (message)
    {
    case WM_CREATE:
    {
        //创建Edit控件
        {
            hEdit = CreateWindow(TEXT("Edit"), NULL, WS_VISIBLE | WS_CHILD | WS_HSCROLL | WS_VSCROLL | WS_BORDER | ES_MULTILINE, 0, 0, x_of_main_window, y_of_main_window, hwnd, NULL, NULL, NULL);

        }

        //创建菜单栏
        {
            HMENU hMenu = CreateMenu();

            //文件
            HMENU hFileMenu = CreateMenu();
            {
                AppendMenu(hFileMenu, MF_STRING, MENU_FILE_NEW, TEXT("新建"));
                AppendMenu(hFileMenu, MF_STRING, MENU_FILE_OPEN, TEXT("打开"));
                AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
                AppendMenu(hFileMenu, MF_STRING, MENU_FILE_SAVE, TEXT("保存"));
                AppendMenu(hFileMenu, MF_STRING, MENU_FILE_ANOTHER, TEXT("另存为"));

                AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, TEXT("文件"));
            }

            //外观
            HMENU hLookMenu = CreateMenu();
            {
                AppendMenu(hLookMenu, MF_STRING, MENU_LOOK_BGCOLOR, TEXT("背景颜色"));
                AppendMenu(hLookMenu, MF_STRING, MENU_LOOK_FONT, TEXT("字体"));
                AppendMenu(hLookMenu, MF_STRING, MENU_LOOK_TITLE, TEXT("标题"));
                AppendMenu(hLookMenu, MF_STRING, MENU_LOOK_BORDER, TEXT("边框"));

                AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hLookMenu, TEXT("外观"));
            }

            //关于
            AppendMenu(hMenu, MF_STRING, MENU_ABOUT, TEXT("关于"));

            SetMenu(hwnd, hMenu);
        }
    }
        return 0;

    case WM_SIZE:
    {
        int newwidth = LOWORD(lParam);
        int newheight = HIWORD(lParam);
        SetWindowPos(hEdit, NULL, 0, 0, newwidth, newheight, SWP_NOMOVE | SWP_NOZORDER);
    }
        break;

    case WM_COMMAND:
    {
        switch (wParam)
        {
            //文件
            //打开
            case MENU_FILE_OPEN:
            {
                OPENFILENAME ofn;



                ZeroMemory(&ofn, sizeof(OPENFILENAME));

                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFile = file_name;
                ofn.lpstrFile[0] = TEXT('\0');
                ofn.nMaxFile = 100;
                ofn.lpstrFilter = TEXT("All file\0*.*\0Source Files\0*.CPP\0Text file\0*.TXT\0");
                ofn.nFilterIndex = 1;

                if (GetOpenFileName(&ofn) == TRUE)
                {
                    HANDLE hFile = CreateFile(
                        ofn.lpstrFile,
                        GENERIC_READ,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_EXISTING,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);
                    if (hFile != INVALID_HANDLE_VALUE)
                    {
                        int  filesize = GetFileSize(hFile, NULL);

                        TCHAR* data = new TCHAR[filesize + 1];

                        bool bRead = ReadFile(hFile, data, filesize, NULL, NULL);

                        if (!bRead) { MessageBox(hwnd, TEXT("读取文件失败"), TEXT("警告"), MB_ICONERROR); }

                        data[filesize] = TEXT('0');

                        SetWindowText(hEdit, data);

                        delete[]data;

                        CloseHandle(hFile);
                    }
                }
            }
            break;

            //保存
            case MENU_FILE_SAVE:
            {
                //OPENFILENAME ofn;

                //TCHAR file_name[100];

                //ZeroMemory(&ofn, sizeof(OPENFILENAME));

                //ofn.lStructSize = sizeof(OPENFILENAME);
                //ofn.hwndOwner = hwnd;
                //ofn.lpstrFile = file_name;
                //ofn.lpstrFile[0] = TEXT('\0');
                //ofn.nMaxFile = 100;
                //ofn.lpstrFilter = TEXT("All file\0*.*\0Source Files\0*.CPP\0Text file\0*.TXT\0");
                //ofn.nFilterIndex = 1;

                //if (GetSaveFileName(&ofn) == TRUE)
                if (file_name[0] == 0) 
                {
                    MessageBox(hEdit, TEXT("你未打开文件，即将跳转到“另存为”选项"), TEXT("盲点"), MB_OK);
                    SendMessage(hwnd, WM_COMMAND, MENU_FILE_ANOTHER, 1234567);
                    break;
                }

                HANDLE hFile = CreateFile(
                    file_name,
                    GENERIC_WRITE,
                    FILE_SHARE_READ,
                    NULL,
                    OPEN_ALWAYS,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL);
                if (hFile != INVALID_HANDLE_VALUE)
                {
                    TCHAR data[200];


                    GetWindowText(hEdit, data, 200);

                    bool bWrite = WriteFile(hFile, data, lstrlen(data) * sizeof(TCHAR), NULL, NULL);

                    ZeroMemory(data, 200);

                    if (bWrite == FALSE)
                    {
                        MessageBox(hwnd, TEXT("写入文件失败"), TEXT("警告"), MB_ICONERROR);
                    }

                    CloseHandle(hFile);
                }

                

                else MessageBox(hwnd, TEXT("yyy错误"), TEXT("警告"), MB_ICONERROR);


            }
            break;

            //新建
            case MENU_FILE_NEW:
            {
                OPENFILENAME ofn;

                ZeroMemory(&ofn, sizeof(OPENFILENAME));

                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFile = file_name;
                ofn.lpstrFile[0] = TEXT('\0');
                ofn.nMaxFile = 100;
                ofn.lpstrFilter = TEXT("All file\0*.*\0Source Files\0*.CPP\0Text file\0*.TXT\0");
                ofn.nFilterIndex = 1;

                if (GetOpenFileName(&ofn) == TRUE)
                {
                    HANDLE hFile = CreateFile(
                        file_name,
                        GENERIC_READ | GENERIC_WRITE,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);
                    if (hFile != INVALID_HANDLE_VALUE)
                    {
                        TCHAR data[200];

                        GetWindowText(hEdit, data, 200);

                        bool bWrite = WriteFile(hFile, data, lstrlen(data) * sizeof(TCHAR), NULL, NULL);

                        ZeroMemory(data, 200);

                        if (bWrite == FALSE)
                        {
                            MessageBox(hwnd, TEXT("写入文件失败"), TEXT("警告"), MB_ICONERROR);
                        }

                        CloseHandle(hFile);
                    }
                }
            }
            break;

            //另存为
            case MENU_FILE_ANOTHER:
                tip(); break;

            //外观
            //字体
            case MENU_LOOK_FONT:
                {                // display device context of owner window

                    CHOOSEFONT cf;            // common dialog box structure
                    LOGFONT lf;        // logical font structure
                    DWORD rgbCurrent;  // current text color
                    HFONT hfont;

                    // Initialize CHOOSEFONT
                    ZeroMemory(&cf, sizeof(cf));
                    cf.lStructSize = sizeof(cf);
                    cf.hwndOwner = hwnd;
                    cf.lpLogFont = &lf;
                    cf.rgbColors = rgbCurrent;
                    cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

                    if (ChooseFont(&cf) == TRUE)
                    {
                        hfont = CreateFontIndirect(cf.lpLogFont);

                        HDC hdc = GetDC(hEdit);
                       /* hfontPrev = (HFONT)SelectObject(hdc, hfont);*/
                        rgbCurrent = cf.rgbColors;
                        
                        SendMessage(hEdit, WM_SETFONT, (WPARAM)hfont, (LPARAM)TRUE);
                        SetTextColor(hdc, rgbCurrent);
                        ReleaseDC(hwnd, hdc);
                    }
                }
                break;

            //背景颜色
            case MENU_LOOK_BGCOLOR:
                tip();
                break;

            //标题
            case MENU_LOOK_TITLE:
                tip(); break;

            //边框
            case MENU_LOOK_BORDER:
                tip(); break;

            //关于
            case MENU_ABOUT:
                tip(); break;
             
        }
    }
        break;

    case WM_DESTROY:
    {
        PostQuitMessage(0);
    }
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
