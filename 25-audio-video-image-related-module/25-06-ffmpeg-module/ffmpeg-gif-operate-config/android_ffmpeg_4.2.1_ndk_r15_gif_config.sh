#!/bin/bash  
NDK=/home/eink/soft_tools/ndk/android-ndk-r15c
SYSROOT=$NDK/platforms/android-14/arch-arm/
TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64

CPU=arm
PREFIX=$(pwd)/Android/$CPU
MP3LAME=/home/eink/testproject/lame_3.99.5_libmp3lame

./configure \
    --prefix=$PREFIX \          #规定编译文件在哪里生成
    --enable-cross-compile \    #启用交叉编译方式
    --cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \  #交叉编译链
    --target-os=linux \         #目标系统
    --arch=arm \                #目标平台架构
    --sysroot=$SYSROOT \        #交叉编译环境
    --extra-cflags="-I${MP3LAME}" \                 #额外需要的头文件
    --extra-ldflags="-L${MP3LAME}/lib" \                    #额外需要的库                 
    --enable-shared \           #生成动态库（共享库）
    --disable-static \          #禁止生成静态库
    --disable-doc \             #禁用不需要的功能，下同
    --disable-parsers \
    --disable-protocols \
    --disable-indevs \
    --disable-bsfs \
    --disable-muxers \
    --disable-demuxers \
    --disable-hwaccels \
    --disable-decoders \
    --disable-encoders \
    --enable-parser=mpegaudio \ #启用需要的功能，下同
    --enable-protocol=http \
    --enable-protocol=file \
    --enable-libmp3lame \
    --enable-encoder=libmp3lame \
    --enable-encoder=png \
    --enable-demuxer=mp3 \
    --enable-muxer=mp3 \
    --enable-decoder=mjpeg \
    --enable-decoder=mp3