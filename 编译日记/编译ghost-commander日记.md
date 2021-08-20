# 编译日记

## 一

遇到错误：plugin with id 'com.android.application' not found  
参考：  
<https://stackoverflow.com/questions/24795079/error1-0-plugin-with-id-com-android-application-not-found>  
<https://blog.csdn.net/qq_26819733/article/details/50935632>  
解决：  
在build.gradle中加入如下内容：  

```gradle
buildscript {
    repositories {
        google() // For Gradle 4.0+
        maven { url 'https://maven.google.com' } // For Gradle < 4.0
    }

    dependencies {
        classpath 'com.android.tools.build:gradle:4.1.0'
    }
}
```

完成后点击`sync poject with gradle files`按钮刷新  
结果：仍然失败  

## 二

修改以上添加的内容为

```gradle
buildscript {
    repositories {
        maven { url 'http://maven.aliyun.com/nexus/content/repositories/google' }
        maven { url 'http://maven.aliyun.com/nexus/content/repositories/jcenter'}
    }

    dependencies {
        classpath 'com.android.tools.build:gradle:4.1.0'
    }
}

allprojects {
    repositories {
//    google()
//    jcenter()
        maven { url 'http://maven.aliyun.com/nexus/content/repositories/google' }
        maven { url 'http://maven.aliyun.com/nexus/content/repositories/jcenter'}
    }
}
```  

完成后点击`sync poject with gradle files`按钮刷新  
结果：运行图标点亮，点击成功运行  

## 完
