//在app/src/main/res下创建文件夹menu

//在app/src/main/res/menu文件夹下创建MENU源文件

//MENU源文件中
<item
    android:id="@+id/某item的id"
    android:title="某item名称"/>
<item
    android:id="@+id/另一item的id"
    android:title="另一item名称"/>

//activity文件中(直接处于活动定义下一级)
@Override
public boolean onCreateOptionsMenu(Menu myMenu) 
{
    getMenuInflater().inflate(R.menu.MENU源文件名称,myMenu);
    return true;
}

@Override
public boolean onOptionsItemSelected(@NonNull MenuItem myItem) 
{
    switch(myItem.getItemId())
    {
        case R.id.某item的id:
            //一些活动
            break;
        case R.id.另一item的id:
            //一些操作
            break;
        default:
    }
        return true;
}
