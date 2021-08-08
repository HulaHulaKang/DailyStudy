//activity文件中

方法一（隐式）：
Intent myIntent=new Intent("目标Action");
startActivity(myIntent);

方法二（显示指出目标活动名）：
Intent myIntent=new Intent(当前活动名.this,目标活动名.class)；
startActivity(myIntent);
