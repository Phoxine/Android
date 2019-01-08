該資料夾包含HAL實作程式碼

以下說明各程式碼事項以及編譯打包指令


1.HAL資料夾:

helloworld.h 放到 /hardware/libhardware/include/hardware

helloworld folder 放到 /hardware/libhardware/modules

回到根目錄，執行mmm /hardware/libhardware/modules/helloworld 編譯模組
並執行make snod重新打包


2.JNI資料夾:

CPP檔 放到 /framework/base/service/jni

另外，同路徑下的Android.mk、onload.cpp需要做修改

makefile是在LOCAL_SRC_FILES新增HelloWorldSevice.cpp

onload則是對系統註冊自定義的服務

詳細請參考JNI資料夾下的onload.cpp及Android.mk檔案

修改完成後，回到根目錄，執行mmm /framework/base/service/jni 編譯
並執行make snod重新打包


3.Service資料夾:

IHelloWorldService.aidl 放到 /framework/base/core/java/android/os

HelloWorldService.java 放到 /framework/base/services/java/com/android/server

java檔同路徑下的SystemService.java以及/framework/base下的Android.mk

兩個文件需要做修改

makefile是新增aidl的資訊

SystemService則是添加add Service方法

詳細請參考資料夾內文件，使用Ctrl + F搜尋HelloWorldService查看相關程式碼

編譯部分，回到根目錄，執行mmm /framework/base，以及make snod重新打包。
