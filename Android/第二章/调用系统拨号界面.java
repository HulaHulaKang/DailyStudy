//activity文件中
Intent it=new Intent(Intent.ACTION_DIAL);
it.setData(Uri.parse("tel:电话号码"));
startActivity(it);
