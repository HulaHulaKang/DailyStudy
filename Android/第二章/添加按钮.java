//layout文件中
<Button android:id="@+id/bt1"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:text="按钮"/>

//activity文件中
Button bt1=(Button)findViewById(R.id.button_1);
bt1.setOnClickListener
(
    new View.OnClickListener()
        {
            @Override
            public void onClick(View myView)
            {
                //要执行的操作
            }
        }
);