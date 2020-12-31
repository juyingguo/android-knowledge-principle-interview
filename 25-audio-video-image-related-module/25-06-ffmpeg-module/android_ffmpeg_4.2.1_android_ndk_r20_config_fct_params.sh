#!/bin/bash
NDK=/home/eink/soft_tools/ndk/android-ndk-r20/android-ndk-r20

function build_android
{

TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64
API=21
ARCH=$1 #param 1
CPU=$2 #param 2

CC=$TOOLCHAIN/bin/armv7a-linux-androideabi$API-clang
CXX=$TOOLCHAIN/bin/armv7a-linux-androideabi$API-clang++
SYSROOT=$NDK/toolchains/llvm/prebuilt/linux-x86_64/sysroot
CROSS_PREFIX=$TOOLCHAIN/bin/arm-linux-androideabi-
PREFIX=$(pwd)/android/$CPU #自己指定一个输出目录
OPTIMIZE_CFLAGS="-mfloat-abi=softfp -mfpu=vfp -marm -march=$CPU "
rm -rf $(pwd)/android/$CPU

echo "Compiling FFmpeg for $CPU"
./configure \
    --prefix=$PREFIX \
    --disable-neon \
    --disable-hwaccels \
    --disable-gpl \
    --disable-postproc \
    --enable-shared \
    --enable-jni \
    --disable-mediacodec \
    --disable-decoder=h264_mediacodec \
    --disable-static \
    --disable-doc \
    --disable-ffmpeg \
    --disable-ffplay \
    --disable-ffprobe \
    --disable-avdevice \
    --disable-doc \
    --disable-symver \
    --cross-prefix=$CROSS_PREFIX \
    --target-os=android \
    --arch=$ARCH \
    --cpu=$CPU \
    --cc=$CC \
    --cxx=$CXX \
    --enable-cross-compile \
    --sysroot=$SYSROOT \
    --extra-cflags="-Os -fpic $OPTIMIZE_CFLAGS" \
    --extra-ldflags="$ADDI_LDFLAGS" \
    $ADDITIONAL_CONFIGURE_FLAG

}

#armv7-a
ARCH=arm
CPU=armv7-a

build_android arm arm-v7a

make clean
make -j 2
make install
echo "The Compilation of FFmpeg for $CPU is completed"
