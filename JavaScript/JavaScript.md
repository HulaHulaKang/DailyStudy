JavaScript基本语法
===================

是否区分大小写：`是`  
是否使用Unicode编码：`是`  
语句分隔符：分号(`;`)或者换行（`Enter`）  
注释：（1）`//注释`（2）`/*注释*/`  
标识符命名原则：字母、数字、`_`、`$` 组成，字母、`_`、`$` 开头  图
JavaScript是一种`动态类型语言(dynamically typed language)`。这意味着你在声明变量时可以不必指定数据类型，而数据类型会在代码执行时会根据需要自动转换。  

undefined和null
----------------

未被赋值时，变量的值为`undefined`，可用`==undefined`判断是否赋值  
undefined进行数值运算得NaN  

null进行数值运算时，null被视为0  

数据类型
---------------

>布尔Boolean  
>空值null  
>未定义值undefined  
>数字Number（整数或浮点数）  
>任意位数的大整数BigInt  
>字符串String  
>不知道是啥Symbol  
>对象Object  

字符串转数字[parseInt](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/parseInt "关于parseInt的MDN文档")、[parseFloat](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/parseFloat "关于parseFloat的MDN文档")  

字面值
-------------------
  
数组写法`［1,2,3,4］`  
注意：如果两个逗号之间（或逗号与方括号之间）没有元素，则视该元素为undefined,如`[1,,3,]`的第2、4个元素为undefined。自己写代码的时候，可以显示地写出undefined.  
  
布尔值写法：`true`、`false`  
  
>整数写法：  
>十进制 没有前缀0
>八进制 前缀为0、0O、0o开头，只包含数字0～7  
>十六进制   前缀为0x、0X，包含a～f或A～F  
>二进制 前缀为0b、0B,只包含数字0～1  
严格模式下，八进制整数字面量必须以0o或0O开头，而不能以0开头。  
  
[浮点数写法](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Grammar_and_types#%E6%B5%AE%E7%82%B9%E6%95%B0%E5%AD%97%E9%9D%A2%E9%87%8F_floating-point_literals "语法和数据类型 - JavaScript | MDN") `[(+|-)][digits][.digits][(E|e)[(+|-)]digits]`  
  
>对象写法：  
>
>```javascript
>var Sales = "Toyota";
>
>function CarTypes(name) {
>  return (name === "Honda") ?
>    name :
>    "Sorry, we don't sell " + name + "." ;
>}
>
>var car = { myCar: "Saturn", getCar: CarTypes("Honda"), special: Sales };  
>console.log(car.special); // Toyota  
>```
>
>对象[^1]的属性值也可是对象，如
>
>```js
>var car = { manyCars: {a: "Saab", "b": "Jeep"}, 7: "Mazda" };
>console.log(car.manyCars.b); // Jeep
>```  
>
>数字可以作键[^2],但请注意：
>
>```js
>var foo = {a: "alpha", 2: "two"};
>console.log(foo.a);    // alpha
>console.log(foo[2]);   // two
>//console.log(foo.2);  // SyntaxError: missing ) after argument list
>//console.log(foo[a]); // ReferenceError: a is not defined
>console.log(foo["a"]); // alpha
>console.log(foo["2"]); // two
>```

字符串写法：  
双引号或单引号均可，字符串内有引号的，要么用转义字符`\"`和`\'`，要么`单包双 双包单`

流程控制
-------------

if语句

```js
if (condition) {
  statement_1;
}else {
  statement_2;
} //推荐使用严格的语句块模式，语句else可选
```  

```js
if (condition_1) {
  statement_1;
}else if (condition_2) {
  statement_2;
}else if (condition_n_1) {
  statement_n;
}else {
  statement_last;
}
```

`false、undefined、null、0、NaN、空字符串（""）`作为条件时视为`false`
其余的（包括对象）作为条件时视为`true`

switch语句

```js
switch (expression) {
   case label_1:
      statements_1
      [break;]
   case label_2:
      statements_2
      [break;]
   ...
   default:
      statements_def
      [break;]
}
```

循环语句
-------------

for语句  

```js
for ([initialExpression]; [condition]; [incrementExpression])
  statement
  //和C语言类似
```

do-while语句  

```js
do
  statement
while (condition);
```

while语句  

```js
while (condition)
  statement
```

[label语句](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Loops_and_iteration#label_%E8%AF%AD%E5%8F%A5 "循环与迭代 - JavaScript | MDN")  

```js
name:
    statement
    break [name];
    statement
    continue [name];
```

for...in 语句  

```js
for (variable in object) {
  statements
}
```

```js
function dump_props(obj, obj_name) {
  var result = "";
  for (var i in obj) {
    result += obj_name + "." + i + " = " + obj[i] + "<br>";
  }
  result += "<hr>";
  return result;
}
```

for...of 语句  

```js
for (variable of object) {
  statement
}
```

for...in 循环遍历的结果是数组元素的下标，而 for...of 遍历的结果是元素的值：

```js
let arr = [3, 5, 7];
arr.foo = "hello";

for (let i in arr) {
   console.log(i); // 输出 "0", "1", "2", "foo"
}

   for (let i of arr) {
   console.log(i); // 输出 "3", "5", "7"
}

// 注意 for...of 的输出没有出现 "hello"
// 译者：官方文档不知为何在此使用三个空格来缩进…
```

[函数定义](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Functions)
---------------

```js
//方法一
function square(number) {
  return number * number;
}

//方法二
const square = function(number) { return number * number; };
var x = square(4); // x gets the value 16

//匿名函数
var a = [
  "Hydrogen",
  "Helium",
  "Lithium",
  "Beryllium"
];
var a2 = a.map(function(s){ return s.length });
console.log(a2); // [ 8, 6, 7, 9 ]

//箭头函数
var a3 = a.map( s => s.length );
console.log(a3); // logs [ 8, 6, 7, 9 ]
```

[运算符](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Expressions_and_Operators)  
---------------

[^1]:JavaScript中的“对象”就是一个键值对列表  
[^2]:属性名  