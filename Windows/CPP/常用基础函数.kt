//MessageBox
int MessageBox(
  HWND    hWnd,//父窗口句柄
  LPCTSTR lpText,//内容
  LPCTSTR lpCaption,//标题
  UINT    uType//样式，以MB_开头
);

//SendMessage
LRESULT SendMessage(
  HWND   hWnd,//接收消息的窗口句柄
  UINT   Msg,//消息类别，以WM_、BM_等开头
  WPARAM wParam,//
  LPARAM lParam//
);

//CreateWindow
void CreateWindow(
   lpClassName,//窗口所属的类名，这决定了它是什么样的窗口，比如按钮是TEXT("Button"),下拉框是TEXT("ComboBox"),主窗口通常是自己注册的类。
   lpWindowName,//窗口名称，会显示出来，具体怎么显示取决于是哪种窗口，比如主窗口显示为标题，按钮显示为按钮中的文本
   dwStyle,//样式，以WM_、BM_等开头
   x,//起始x
   y,//起始y
   nWidth,//x跨度
   nHeight,//y跨度
   hWndParent,//父窗口句柄
   hMenu,//
   hInstance,//
   lpParam//这是一个指针
);