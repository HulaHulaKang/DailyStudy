//基本常识：调用文件框的操作是一个函数
//在适当的时机执行如下操作：

//一般不动的：
OPENFILENAME ofn;
TCHAR szFile[260/*允许文件名长度的最大值*/]; //用来存储文件名的内存
ZeroMemory(&ofn, sizeof(ofn));
ofn.lStructSize = sizeof(ofn);
ofn.lpstrFile = szFile;//用于存储文件名的缓冲区地址
ofn.lpstrFile[0] = TEXT('\0');  //防止lpstrFile中保存了来自szFile的垃圾值
ofn.nMaxFile = sizeof(szFile);
ofn.lpstrFileTitle = NULL;
ofn.nMaxFileTitle = 0;
ofn.lpstrInitialDir = NULL;
ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

//一般要改的：
ofn.hwndOwner = m_hwnd;//所属窗口句柄
ofn.lpstrFilter = TEXT("All\0*.*\0Text\0*.txt\0");//文件名筛选条件，这句话的意思是All(*.*)或TEXT(*.txt)
ofn.nFilterIndex = 1;//指定默认选择的过滤器的索引,从1开始计数，如此处1代表All，2代表TEXT

HANDLE hf; //文件句柄

if (GetOpenFileName(&ofn) == TRUE)
{   //这里是打开文件框之后的操作 

//CreateFile函数的详细信息，可查阅https://blog.csdn.net/qq_32619837/article/details/89327250
    hf = CreateFile(ofn.lpstrFile,
        GENERIC_READ,
        0,
        (LPSECURITY_ATTRIBUTES)NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        (HANDLE)NULL);
}