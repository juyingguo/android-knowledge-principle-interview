#!/bin/bash
echo "###### 开始配置ffmpeg_android 经过裁剪的编解码器 ######"
echo "###### 编译环境：NDK-r15c，ffmpeg3.1.1 ######"
NDK=/home/eink/soft_tools/ndk/android-ndk-r15c
#注意，android-ndk-r15c环境下，SYSROOT路径要选android-21以上平台
SYSROOT=$NDK/platforms/android-21/arch-arm/
TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
CPU=arm
PREFIX=/home/eink/testproject/ffmpeg/ffmpeg_android_out/$CPU #配置输出目录

cd /home/eink/testproject/ffmpeg/ffmpeg-3.1.11

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
    --disable-programs                 \
--disable-encoders           \
    --enable-encoder=mjpeg       \
    --enable-encoder=gif         \
        --disable-decoders	 \
	--enable-decoder=mjpeg \
	--enable-decoder=h264 \
        --enable-decoder=mpeg4   \
      --disable-muxers         \
      --enable-muxer=gif       \
      --enable-muxer=mjpeg     \
      --enable-muxer=image2     \
    --disable-demuxers           \
    --enable-demuxer=mpegvideo   \
    --enable-demuxer=image2   \
    --enable-demuxer=mjpeg   \
    --enable-demuxer=h264 	\
    --enable-demuxer=mov 	\
        --disable-parsers        \
        --enable-parser=mjpeg       \
        --enable-parser=mpegvideo   \
	--enable-parser=h264 	\
    --extra-cflags="-Os -fpic " 
echo "###### ffmpeg_android配置完成,开始 make ######"
make clean
make -j4
make install
