adb push %~dp0/libs/armeabi-v7a/ssh /system/xbin

adb shell chmod 777 /system/xbin/ssh

adb push %~dp0/libs/armeabi-v7a/dropbear /system/xbin

adb shell chmod 777 /system/xbin/dropbear

adb push %~dp0/libs/armeabi-v7a/dropbearkey /system/xbin

adb shell chmod 777 /system/xbin/dropbearkey
