//说明：
//startActivityForResult()方法：
//启动一个活动，并在启动的活动结束时给原活动传回一个值

//原Activity
//打开新活动：
Intent it=new Intent(当前活动.this,目标活动.class);
startActivityForResult(it,请求码);//请求码是整型
//处理传回值：
@override
protected void onActivityResult(int requestCode/*请求码*/,int resultCode/*RESULT_XXX*/,Intent myIntent)
{
    switch(requestCode)
    {
        case 1://请求码为1时
        {
            if(resultCode==RESULT_OK)
            {
                String 标识符1=myIntent.getStringExtra("hhh");
                //一些操作
            }
        }
        //case ........
    }
}

//新打开的activity
Intent it=new Intent();
it.putExtra("hhh","字符串内容");//这里的hhh可以自定义，原活动会用到
setResult(RESULT_OK或RESULT_CANCELED,it); //RESULT_XXX就是上面的resultCode
finish();