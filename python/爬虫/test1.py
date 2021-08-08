#POST方式获取源代码
#提交一组表单数据
#返回对应源码
from os import write
import requests

data1={'name':"kwh",'password':"1234567"}
html_formdata=requests.post("http://www.baidu.com",data=data1)

outputfilename="baidu.html"
with open(outputfilename,"w") as file_obj:
    file_obj.write(html_formdata.content.decode())

