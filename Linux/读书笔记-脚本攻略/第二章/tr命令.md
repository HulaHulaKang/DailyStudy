```shell
tr [option] set1 set2
# set1 和 set2 都是字符集合
# set1 中的第一个字符映射到 set2 中的第一个字符，依次类推
#如果 set1 长度大于 set2 ，则超出部分全部映射到set2的最后一个字符
```

>字符集的简写：<br/>
>'1-9'相当于'123456789'<br/>
>'a-z'相当于'abcdefghijklmnopqrstuvwxyz'<br/>
>'A-Z'相当于'ABCDEFGHIJKLMNOPQRSTUVWXYZ'<br/>

>tr命令可用于简单的加密和解密<br/>


```shell
tr  -d  set0 #删除 set0 中的字符<br/>
```

```shell
#注：以下均只讨论 set0 只含一个字符的情况，原因是我不清楚多字符集会怎么样<br/>
tr  -c  set1 set0   #将不在 set1 中的字符全部替换成 set0 中的字符<br/>
tr  -s  set0        #将 set0 中的字符所有连续出现多个的地方压缩为一个<br/>
```

> 字符类<br/>
> 可以用 [:class:] 表示字符集合 `# class 为字符类的名称<br/>`
>> alnum —— 字母和数字<br/>
>> alpha —— 字母<br/>
>> cntrl —— 控制字符(非打印)<br/>
>> digit —— 数字<br/>
>> graph —— 图形字符<br/>
>> lower —— 小写字母<br/>
>> print —— 可打印字符<br/>
>> punct —— 标点符号<br/>
>> space —— 空白字符<br/>
>> upper —— 大写字母<br/>
>> xdigit —— 十六进制字符<br/>