# C++中的const限定符详解

## 引用

“常量引用”的意思是：对常量的引用  
即它所指向的是常量  

如果目标是常量，则引用必须用const修饰  
即：

```C++
const int a=1;
int& a1=a;      //错误
const int& a2=a;//正确
```  

如果目标不是常量，则引用可以用const修饰，也可以不用  
即：

```C++
int a=1;
int& a1=a;      //正确
const int& a2=a;//正确
```  

正确定义引用变量后，可不可以修改引用的值（注意，这个值也就是目标的值）取决于引用变量（而非目标）本身是否有const修饰  
比如：

```C++
int a=100;      //[1]
int &a1=a;      //[2]
const int &a2=a;//[3]
a++;    //正确，因为[1]没有const限定符
a1++;   //正确，因为[2]没有const限定符
a2++;   //错误，因为[3]有const限定符
```

## 指针

一、指向常量的指针  
如果目标是常量，则指针必须用const修饰，且const在类型（int等）前  
如：

```C++
const double pi=3.14;
double *p1 = &pi;    //错误
const double *p2 = &pi; //正确
```  

二、自身是常量的指针  
指针指向不变，而目标是不是常量都无所谓，const放在`*`后面  
如：

```C++
int i=0;
int *const p1 = &i; //正确，指向的是变量
const double pi=3.14;
double *const p2 = &pi;//正确，指向的是常量
//p1和p2指向均不可变
```  

## 顶层const和底层const

顶层const：表示任意对象本身是常量  
底层const：表示所指对象是常量  

只有指针和引用等复合类型可以是底层const  
所有类型都可以是顶层const  
