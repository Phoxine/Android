�Ӹ�Ƨ��]�tHAL��@�{���X

�H�U�����U�{���X�ƶ��H�νsĶ���]���O


1.HAL��Ƨ�:

helloworld.h ��� /hardware/libhardware/include/hardware

helloworld folder ��� /hardware/libhardware/modules

�^��ڥؿ��A����mmm /hardware/libhardware/modules/helloworld �sĶ�Ҳ�
�ð���make snod���s���]


2.JNI��Ƨ�:

CPP�� ��� /framework/base/service/jni

�t�~�A�P���|�U��Android.mk�Bonload.cpp�ݭn���ק�

makefile�O�bLOCAL_SRC_FILES�s�WHelloWorldSevice.cpp

onload�h�O��t�ε��U�۩w�q���A��

�ԲӽаѦ�JNI��Ƨ��U��onload.cpp��Android.mk�ɮ�

�ק粒����A�^��ڥؿ��A����mmm /framework/base/service/jni �sĶ
�ð���make snod���s���]


3.Service��Ƨ�:

IHelloWorldService.aidl ��� /framework/base/core/java/android/os

HelloWorldService.java ��� /framework/base/services/java/com/android/server

java�ɦP���|�U��SystemService.java�H��/framework/base�U��Android.mk

��Ӥ��ݭn���ק�

makefile�O�s�Waidl����T

SystemService�h�O�K�[add Service��k

�ԲӽаѦҸ�Ƨ������A�ϥ�Ctrl + F�j�MHelloWorldService�d�ݬ����{���X

�sĶ�����A�^��ڥؿ��A����mmm /framework/base�A�H��make snod���s���]�C
