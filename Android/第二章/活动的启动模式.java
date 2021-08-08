standard模式：
无论如何，启动一个新实例

singleTop模式：
如果在栈顶，则不启动新实例
如果在下层或栈中不存在，则启动新实例

singTask模式：
无论在栈顶还是下层，只要栈中存在，就不启动新实例，而是直接调用
不在栈中的，启动新实例

singleInstance模式：
无论如何，在一个新栈中启动实例

//设置活动的启动模式
<activity android:name="/*...*/"
  android:launchMode="启动模式">

