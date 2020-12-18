#!/bin/bash
make clean
#export NDK=/home/ndk_build/android-ndk-r14b
export NDK=/home/eink/soft_tools/ndk/android-ndk-r20/android-ndk-r20
#NDK=$ANDROID_NDK
export SYSROOT=$NDK/platforms/android-21/arch-arm/
export TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
export CPU=arm
export PREFIX=$(pwd)/android/$CPU
export ADDI_CFLAGS="-marm"
##--disable-ffserver ## for ffmpeg4.2.4 no --disable-ffserver 
./configure --target-os=linux \
--prefix=$PREFIX --arch=arm \
--disable-doc \
--enable-shared \
--disable-static \
--disable-yasm \
--disable-symver \
--enable-gpl \
--disable-ffmpeg \
--disable-ffplay \
--disable-ffprobe \
--disable-doc \
--disable-symver \
--cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
--enable-cross-compile \
--sysroot=$SYSROOT \
--extra-cflags="-Os -fpic $ADDI_CFLAGS" \
--extra-ldflags="$ADDI_LDFLAGS" \
$ADDITIONAL_CONFIGURE_FLAG
make clean
make
make install