//基本常识：下拉框是一个子窗口

//创建：
HWND hWndComboBox = CreateWindow(
    TEXT("ComboBox"), 
    TEXT("11"),
    CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,//WS_CHILD和WS_VISIBLE必须有，CBS_DROPDOWN最好也有
    100,100,200,200, 
    m_hwnd,
    NULL,//hmenu
    (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE),
    NULL); 

//添加选项：
//方法一：在最后面添加
SendMessage(
 hWndComboBox,//下拉框窗口句柄（其本身，而非其子窗口）
 (UINT)CB_ADDSTRING,
 (WPARAM)0,
 (LPARAM)TEXT("Apple")//选项名称（或者叫[选项内容]）
 );
//方法二：在指定位置添加
SendMessage(hWndComboBox,
 (UINT)CB_INSERTSTRING ,
 index,//目标位置，0，1，2，3，...
 (LPARAM)TEXT("Apple"));

//响应操作：
case WM_COMMAND:
{
    if(HIWORD(wParam)==CBN_SELCHANGE)
    {
        //具体操作
    }
}

//获取选择项（以下代码应嵌套在上述[响应操作]代码中）
int ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,(WPARAM)0, (LPARAM)0)//返回值为选择项的序号，从上到下依次为0，1，2，...

//获取选择项的内容(按索引)（以下代码应嵌套在上述[响应操作]代码中）
TCHAR  ListItem[20];
SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,(WPARAM)ItemIndex, (LPARAM)ListItem);
//第三个参数为要获取内容的选项的序号
//第四个参数是用来存结果的字符数组

//总结：对下拉框的操作基本都是通过SendMessage函数实现的
//主要参数为第二个，以CB_开头，此项不同则操作不同