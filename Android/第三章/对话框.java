AlertDialog.Builder dl=new AlertDialog.Builder(活动名.this);
dl.setTitle("标题");
dl.setMessage("内容");
dl.setCancelable(boolean);//是否可用返回键关闭，默认为true
dl.setPositiveButton
(
    "OK",new DialogInterface.OnClickListener()
    {
        @Override
        public void onClick(DialogInterface dialog,int which)
        {
            //一些操作
        }
    }
);
dl.setNegativeButton
("Cancel",new DialogInterface.OnClickListener()
    {
        @Override
        public void onClick(DialogInterface dialog,int which)
        {
            //一些操作
        }
    }
);
dl.show();
