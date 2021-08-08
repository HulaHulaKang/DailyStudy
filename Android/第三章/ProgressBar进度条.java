<progressBar
android:id="..."
android:layout_width="..."
android:layout_height="..."
android:visibility="..."
style="..."
android:max="..."
/>

------------------------
visibility  可见性
取值 visible可见 invisible不可见但占空间 gone不可见也不占空间
默认visible

---------------------
运行时改变可见性：
private ProgressBar pb=(ProgressBar)findViewById(R.id.xxx);
if(pb.getVisibility()==View.GONE)
{
    pb.setVisibility()==View.VISIBLE;
}
//getVisibility的返回值和setVisibility的设定值有三种
//View.VISIBLE  View.INVISIBLE  View.GONE

---------------------------------
style   样式
取值    如"?android:attr/progressBarStyleHorizontal"表示水平进度条
如果不设，默认进度条是圆形

--------------------------------
max 最大取值
对圆形进度条无效


----------------------------
运行时改变进度条取值：
private ProgressBar pb=(ProgressBar)findViewById(R.id.xxx);
int progress=pb.getProgress();
progress+=10；
pb.setProgress(progress);


