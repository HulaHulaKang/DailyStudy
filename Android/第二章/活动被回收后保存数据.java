//保存
@Override
protected void onSaveInstanceState(Bundle outState)
{
    super.onSaveInstanceState(outState);
    String tempData="字符串内容";
    outState.putString("键名",tempData);
}

//恢复
@Override
protected void onCreate(Bundle savedInstanceState)
{
    //......
    if(savedInstanceState!=null)
    {
        String tempData=savedInstanceState.getString("键名");
        //......
    }
}