# JavaScript中的Array对象

创建数组

```JS
var fruits = ['Apple', 'Banana'];
```  

函数  
length() —— 返回数组长度

```JS
var last = fruits[fruits.length - 1];
// Banana
```  

forEach —— 遍历数组

```JS
fruits.forEach(function (item, index, array) {
    //要对元素做的操作
    console.log(item, index);
});
// Apple 0
// Banana 1
```  

unshift —— 添加元素（在头部）
push —— 添加元素（在末尾）

```JS
var newLength = fruits.unshift('Strawberry') // add to the front
var newLength = fruits.push('Orange');
```  

pop —— 删除元素（在末尾）
shift —— 删除元素（在头部）  

```JS
var last = fruits.pop(); // remove Orange from the end
var first = fruits.shift(); // remove Apple from the front
```  

indexOf —— 返回某个元素在数组中的索引

```JS
var pos = fruits.indexOf('Banana');
// 1
```

splice —— 通过索引删除某个或某些元素  

```JS
var removedItem = fruits.splice(pos, 1); 
//第一个参数是开始位置的索引
//第二个参数是要删除的元素的个数
```  

slice —— 复制一个数组

```JS
var shallowCopy = fruits.slice(); // this is how to make a copy
// ["Strawberry", "Mango"]
```
