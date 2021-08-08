//AndroidManifest.xml:---------------------------------------
<activity android:name=".主活动名"
          android:label="应用名称">
    <intent-filter>
        <action android:name="android.intent.action.MAIN" />
        <category android:name="android.intent.category.LAUNCHER" />
    </intent-filter>
</activity>
//主活动.java:-----------------------------------------------------
setContentView(R.layout.layout文件名);
//layout文件.xml---------------------------------------------------
只新建，不用改