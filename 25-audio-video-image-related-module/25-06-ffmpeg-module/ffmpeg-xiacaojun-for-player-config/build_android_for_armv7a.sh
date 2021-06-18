#!/bin/bash
echo "进入编译ffmpeg脚本"
NDK=/home/eink/tools/ndk/android-ndk-r17c
#5.0
PLATFORM=$NDK/platforms/android-21/arch-arm
TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
CPU=armv7-a
#输出路径
PREFIX=./ffmpeg-build-out/$CPU

#--disable-ffserver:Unknown option "--disable-ffserver".
function buildFF
{
	echo "开始编译ffmpeg"
	./configure \
    --prefix=$PREFIX \
    --target-os=android \
    --cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
    --arch=arm \
    --cpu=$CPU  \
    --sysroot=$PLATFORM \
    --extra-cflags="$CFLAG" \
    --cc=$TOOLCHAIN/bin/arm-linux-androideabi-gcc \
    --nm=$TOOLCHAIN/bin/arm-linux-androideabi-nm \
    --enable-shared \
    --enable-runtime-cpudetect \
    --enable-gpl \
    --enable-small \
    --enable-cross-compile \
    --disable-debug \
    --disable-static \
    --disable-doc \
    --disable-ffmpeg \
    --disable-ffplay \
    --disable-ffprobe \
    --disable-postproc \
    --disable-avdevice \
    --disable-symver \
    --disable-stripping \
    $ADD 
	make clean
    make -j16
    make install
	echo "编译结束！"
}
###########################################################
#echo "编译支持neon和硬解码"
#CPU=armv7-a
#PREFIX=./ffmpeg-build-out/armv7-a-neon-hard
#CFLAG="-I$PLATFORM/usr/include -fPIC -DANDROID -mfpu=neon -mfloat-abi=softfp"
#ADD="--enable-asm \
#    --enable-neon \
#    --enable-jni \
#    --enable-mediacodec \
#    --enable-decoder=h264_mediacodec \
#    --enable-hwaccel=h264_mediacodec "
#buildFF

###########################################################
echo "编译不支持neon和硬解码"
CPU=armv7-a
PREFIX=./ffmpeg-build-out/$CPU
CFLAG="-march=armv7-a -fPIC -DANDROID -mfpu=vfp -mfloat-abi=softfp -isysroot ${NDK}/sysroot   -I${NDK}/sysroot/usr/include/arm-linux-androideabi"
ADD=
buildFF