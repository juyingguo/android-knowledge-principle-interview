#!/bin/bash
#NDK=/home/ndk/android-ndk-r19c
NDK=$ANDROID_NDK
ADDI_LDFLAGS="-fPIE -pie"
ADDI_CFLAGS="-fPIE -pie -march=armv7-a -mfloat-abi=softfp -mfpu=neon"
CPU=armv7-a
ARCH=arm
HOST=arm-linux
SYSROOT=$NDK/toolchains/llvm/prebuilt/linux-x86_64/sysroot
TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
PREFIX=$(pwd)/android/$CPU
x264=$(pwd)/x264/android/$CPU
export PATH=$x264/bin:$PATH
export PATH=$x264/include:$PATH
export PATH=$x264/lib:$PATH
export PKG_CONFIG_PATH=$x264/lib/pkgconfig:$PKG_CONFIG_PATH
configure()
{
    ./configure \
    --prefix=$PREFIX \
	--toolchain=clang-usan \
    --enable-cross-compile \
    --target-os=android \
    --arch=$ARCH \
    --sysroot=$SYSROOT \
	--cc=$TOOLCHAIN/armv7a-linux-androideabi21-clang \
	--cxx=$TOOLCHAIN/armv7a-linux-androideabi21-clang++ \
    --strip=$TOOLCHAIN/arm-linux-androideabi-strip \
    --extra-cflags="$ADDI_CFLAGS" \
    --extra-ldflags="$ADDI_LDFLAGS" \
    --disable-encoders \
    --disable-decoders \
    --disable-avdevice \
    --disable-static \
    --disable-doc \
    --disable-ffplay \
    --disable-network \
    --disable-doc \
    --disable-symver \
	--disable-ffprobe \
	--enable-neon \
    --enable-shared \
    --enable-libx264 \
    --enable-gpl \
    --enable-pic \
    --enable-jni \
    --enable-pthreads \
    --enable-mediacodec \
    --enable-encoder=aac \
    --enable-encoder=gif \
    --enable-encoder=libopenjpeg \
    --enable-encoder=libmp3lame \
    --enable-encoder=libwavpack \
    --enable-encoder=libx264 \
    --enable-encoder=mpeg4 \
    --enable-encoder=pcm_s16le \
    --enable-encoder=png \
    --enable-encoder=mjpeg \
    --enable-encoder=srt \
    --enable-encoder=subrip \
    --enable-encoder=yuv4 \
    --enable-encoder=text \
    --enable-decoder=aac \
    --enable-decoder=aac_latm \
    --enable-decoder=libopenjpeg \
    --enable-decoder=mp3 \
    --enable-decoder=mpeg4_mediacodec \
    --enable-decoder=pcm_s16le \
    --enable-decoder=flac \
    --enable-decoder=flv \
    --enable-decoder=gif \
    --enable-decoder=png \
    --enable-decoder=srt \
    --enable-decoder=xsub \
    --enable-decoder=yuv4 \
    --enable-decoder=vp8_mediacodec \
    --enable-decoder=h264_mediacodec \
    --enable-decoder=hevc_mediacodec \
    --enable-bsf=aac_adtstoasc \
    --enable-bsf=h264_mp4toannexb \
    --enable-bsf=hevc_mp4toannexb \
    --enable-bsf=mpeg4_unpack_bframes

}

build()
{
    configure
    make clean
    make -j4
    make install
}

build