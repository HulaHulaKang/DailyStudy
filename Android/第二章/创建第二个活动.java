//创建Activity文件（手动创建，自动填充，不要勾选自动生成layout）
//添加：
setContentView(R.layout.layout文件名);

//创建layout文件（手动创建，自动填充）

//AndroidManifest.xml中（自动注册）
//作如下修改：
<activity android:name=".新活动名">
    <intent-filter>
        <action android:name="action名"/>
        <category android:name="android.intent.category.DEFAULT"/>
    </intent-filter>
</activity>
