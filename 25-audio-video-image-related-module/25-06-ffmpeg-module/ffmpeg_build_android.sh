# ! /bin/bash
make clean
export NDK=$ANDROID_NDK
export SYSROOT=$NDK/platforms/android-21/arch-arm/
export TOOLCHAIN=$NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64
export CPU=arm
export PREFIX=$(pwd)/android-static/$CPU
export ADDI_CFLAGS="-marm"
./configure --target-os=linux \
--prefix=$PREFIX --arch=arm \
--disable-doc \ 
--disable-shared \
--enable-static \
--disable-yasm \
--disable-symver \
--enable-gpl \
--disable-ffmpeg \
--disable-ffplay \
--disable-ffprobe \
--disable-ffserver \
--disable-doc \
--disable-symver \
--cross-prefix=$TOOLCHAIN/bin/arm-linux-androideabi- \
--enable-cross-compile \
--sysroot=$SYSROOT \
--extra-cflags="-Os -fpic $ADDI_CFLAGS" \
--extra-ldflags="$ADDI_LDFLAGS"\
$ADDITIONAL_CONFIGURE_FLAG
make clean
make -j 2
make install