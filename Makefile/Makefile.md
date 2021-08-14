# [Makefile基础](https://www.gnu.org/software/make/manual/html_node/)

目标:   依赖项  
    构建命令  
    构建命令  
    ...  

## 依赖项

多个文件名由空格隔开，或单个文件名  

## make命令执行过程

第一步，构建依赖项（按第二步的法则）  
第二步，如果目标不存在或者依赖项中有部分比目标新，就执行构建命令  

## 用法  

```shell
make    #构建Makefile文件中的第一个目标
make xxx    #构建xxx
```

## 变量

变量直接以文本形式替换，包括空白字符  
=和:=都是赋值运算符，区别在于:  
如果用`A=$(B) -v`赋值，则A和B永久绑定，后面只要B改变，A就跟着变;  
如果用`A:=$(B) -v`赋值，则赋值完之后，A与B就切断了联系，除非重新赋值，A的值不会改变。  
参见[GNU文档](https://www.gnu.org/software/make/manual/html_node/Flavors.html#Flavors)  

### 示例

```Makefile
objects = program.o foo.o utils.o   #定义变量
program : $(objects)                #使用变量
        cc -o program $(objects)    #使用变量

$(objects) : defs.h                 #使用变量
```

### 极端案例

```Makefile
foo = c             #变量foo严格替换为单个字母"c"
prog.o : prog.$(foo)
        $(foo)$(foo) -$(foo) prog.$(foo)
```  

除了用`$(...)`，还可以用`${...}`  

### 自动变量
  
参见[GNU文档](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)  

### 函数  

参见[GNU文档](https://www.gnu.org/software/make/manual/html_node/#toc-Functions-for-Transforming-Text)  
调用格式:`$(function arguments)`或`${function arguments}`  

## [假目标](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html#Phony-Targets)

```Makefile
.PHONY 假目标名
假目标名:   依赖项
        构建命令
        构建命令
        ...
```  
