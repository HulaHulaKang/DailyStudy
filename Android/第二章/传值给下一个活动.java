//发出方activity文件中
string 标识符1="字符串内容";
Intent it=new Intent(发出方活动名.this，接收方活动名.class);
it.putExtra("hhh",标识符1);
startActivity(it);

//接收方activity文件中
Intent it=getIntent();
String 标识符2=it.getStringExtra("hhh");