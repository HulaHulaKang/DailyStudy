#获取http网页源代码
#这种方法叫GET方式
#requests.get('网址').content.decode("编码方式")
#"编码方式"留空时，缺省值为UTF-8

import requests
html = requests.get("http://www.kangkang.link")
#("https://www.kangkang.link:666")
#("http://www.baidu.com") 
html_byte=html.content
print("================================\n[[ html.content ]]= \n",html_byte)
html_str=html_byte.decode()
print("================================\n[[ html.content.decode ]]=\n",html_str)
