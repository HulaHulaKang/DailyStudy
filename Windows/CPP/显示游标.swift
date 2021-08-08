//基本常识：游标是一个[窗口属性],一个窗口至多有一个游标

//三件套：
CreateCaret
(
  m_hwnd,//要显示游标的窗口句柄
  (HBITMAP)0,//游标样式，貌似只能0或1
  1, //游标宽度
  20//游标高度
);
SetCaretPos(80,80);//X坐标，y坐标
ShowCaret(m_hwnd);//窗口句柄

