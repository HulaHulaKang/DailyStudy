>split命令：将一个大文件分割成若干个特定大小的小文件

```shell
split   #分割文件
        -b   #指定分割后每个小文件的大小
            10c     # byte
              w     # word
              k     # 1024 byte
              M     # 1024 k
              G     # 1024 M
        -d   #生成的文件名以数字为后缀(缺省时以字母为后缀)
        -a   #指定后缀的长度(字符数)
            4
        -l   #按行数分割文件，指定分割后每个小文件的行数
            10
```

>如何指定前缀：将前缀作为最后一个参数