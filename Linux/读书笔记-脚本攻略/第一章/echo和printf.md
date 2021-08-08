 # 在终端中显示输出





## 单双引号字符串的区别——是否解释变量名

> 双引号解释变量名
> 单引号不解释变量名
>
> 示例：
>
> >[kang@myArch ~]$ printf 	&quot;$PATH&quot;
> >`/usr/local/sbin:/usr/local/bin:/usr/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl`
> >[kang@myArch ~]$printf  	&apos;$PATH&apos;
> >`$PATH`

缺省：解释变量名





## echo命令



### <kbd>-e</kbd>选项——是否解释转义字符

`echo -e "..."   			#解释转义字符`

缺省：不解释转义字符



### <kbd>-n</kbd>选项——是否自动换行

`echo -n "..."   #不自动换行`

缺省：自动换行





## printf命令



### 输出功能

`printf  		格式 			[参数]`

><font color="red">基本说明：<br />参数由空格分隔<br/>不自动换行<br />默认解释转义字符<br/>是否解释变量名取决于用的是单引号还是双引号</font>

例如：

`printf 		"	%-5s 			%-10s 			%-4.2f	\n	" 			No			 Name 			80.3456`



### 赋值功能

`printf 			-v 		var(变量名)		格式		 [参数]`

<font color="red">将格式化的结果赋给变量<br/>有了-v选项就不再输出</font>

