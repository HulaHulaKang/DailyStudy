//activity文件中
Intent it=new Intent(Intent.ACTION_VIEW);
it.setData(Uri.parse("网址"));
startActivity(it);