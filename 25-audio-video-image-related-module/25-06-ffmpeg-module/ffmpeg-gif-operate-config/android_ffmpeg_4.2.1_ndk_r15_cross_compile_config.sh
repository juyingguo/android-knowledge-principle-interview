#!/bin/bash
echo "###### 开始配置ffmpeg_android 包含全部编解码器 ######"
NDK=/home/eink/soft_tools/ndk/android-ndk-r15c
SYSROOT=$NDK/platforms/android-15/arch-arm/
TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
CPU=arm
PREFIX=$(pwd)/Android/$CPU
./configure \
    --prefix=$PREFIX \
    --enable-cross-compile \
    --cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
    --target-os=linux \
    --arch=arm \
    --sysroot=$SYSROOT \
    --enable-shared \
    --disable-static \
    --disable-doc \
    --disable-ffmpeg  \
    --disable-ffplay  \
    --disable-ffprobe \
    --extra-cflags="-Os -fpic " 

echo "###### ffmpeg_android配置完成,开始 make ######"
