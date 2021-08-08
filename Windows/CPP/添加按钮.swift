//基本常识：按钮是一个[子窗口]

//加入按钮
//在MainWindow的HandleMessage函数中
//添加如下代码：
WM_CREATE:
{   
    HWND hBtn = CreateWindow(
    L"Button",//这项是窗口类，不能改，要改必须自己新注册窗口类
    L"Hello, Button!",      //文本内容
    WS_CHILD | WS_BORDER | WS_VISIBLE | BS_FLAT,//样式，其中WS_CHILD和WS_VISIBLE必须有
    30, 20, 150, 50,//起始x、起始y、x跨度、y跨度
    m_hwnd,//父窗口句柄
    (HMENU)666,//控件编号，用于写响应操作
    (HINSTANCE)GetWindowLongPtr(m_hwnd,GWLP_HINSTANCE),//不用动（父窗口句柄改的时候参数要跟着改）
    NULL);//这里可以传一个指针，目前我不知道怎么用
}
return 0;



//添加点击事件
//在MainWindow的HandleMessage函数中添加如下代码：
WM_COMMAND:
{
    WORD wmId = LOWORD(wParam);
    WORD wmEvent = HIWORD(wParam);
    switch (wmId)
        {
        case 666:
            MessageBox(m_hwnd, L"按钮2被点击", L"Title", MB_ICONMASK);
            break;
        default:
            return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
            break;
        }
}
return 0;