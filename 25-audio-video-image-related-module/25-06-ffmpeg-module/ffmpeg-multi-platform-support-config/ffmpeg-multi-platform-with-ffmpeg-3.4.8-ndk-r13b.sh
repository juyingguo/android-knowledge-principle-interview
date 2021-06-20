#!/bin/sh

MY_LIBS_NAME=ffmpeg-3.4.8
MY_DIR=ffmpeg-3.4.8
NDK_VERSION=r13b
# cd ./${MY_DIR}

#编译的过程中产生的中间件的存放目录，为了区分编译目录，源码目录，install目录
MY_BUILD_DIR=binary


NDK_PATH=/home/eink/soft_tools/ndk/android-ndk-r13b
BUILD_PLATFORM=linux-x86_64
TOOLCHAIN_VERSION=4.9
ANDROID_VERSION=24

#ANDROID_ARMV5_CFLAGS="-march=armv5te"
ANDROID_ARMV7_CFLAGS="-march=armv7-a -fPIC -DANDROID -mfpu=vfp -mfloat-abi=softfp"  #-mfloat-abi=hard -mfpu=vfpv3-d16 #-mfloat-abi=hard -mfpu=vfp ; -mfpu=neon
ANDROID_ARMV8_CFLAGS="-march=armv8-a -fPIC -DANDROID -mfpu=vfp -mfloat-abi=softfp"
ANDROID_X86_CFLAGS="-march=i686 -fPIC -DANDROID -mtune=intel -mssse3 -mfpmath=sse -m32"
ANDROID_X86_64_CFLAGS="-march=x86-64 -msse4.2 -mpopcnt -m64 -mtune=intel"

#export TMPDIR=$(pwd)/ffmpeg-3.4.8/android_export #
# params($1:arch,$2:arch_abi,$3:host,$4:cross_prefix,$5:cflags)
#--cc=$TOOLCHAIN/bin/arm-linux-androideabi-gcc #不指定，也会自动找到该编译器
build_bin() {

	echo "-------------------star build $2-------------------------"
	
	
	ARCH=$1			# arm arm64 x86 x86_64
	ANDROID_ARCH_ABI=$2 # armeabi armeabi-v7a x86 mips
	HOST=$3
	SINGLE_CROSS_PREFIX_NAME=$4 # 跨平台前缀名称  arm-linux-androideabi arm-linux-androideabi aarch64-linux-android i686-linux-android x86_64-linux-android
	CFALGS=$5
	CPU=$6
	PREFIX=$(pwd)/dist/${MY_LIBS_NAME}-ndk-${NDK_VERSION}/android-${ANDROID_VERSION}/${ANDROID_ARCH_ABI}/	
	SYSROOT=${NDK_PATH}/platforms/android-${ANDROID_VERSION}/arch-${ARCH}	
	TOOLCHAIN=${NDK_PATH}/toolchains/${HOST}-${TOOLCHAIN_VERSION}/prebuilt/${BUILD_PLATFORM}
	CROSS_PREFIX=${TOOLCHAIN}/bin/${SINGLE_CROSS_PREFIX_NAME}-
	
	
	# build 中间件
    BUILD_DIR=./${MY_BUILD_DIR}/${ANDROID_ARCH_ABI}

	echo "pwd=$(pwd)"
	echo "ARCH=${ARCH}"
	echo "PREFIX=${PREFIX}"
	echo "HOST=${HOST}"
	echo "SYSROOT=${SYSROOT}"
	echo "CFALGS=$5"
	echo "TOOLCHAIN=${TOOLCHAIN}"
	echo "CROSS_PREFIX=${CROSS_PREFIX}"

	#echo "-------------------------按任意键继续---------------------"
	#read -n 1
	#echo "-------------------------继续执行-------------------------"
	mkdir -p ${BUILD_DIR}   #创建当前arch_abi的编译目录,比如:binary/armeabi-v7a
    cd ${BUILD_DIR}         #此处 进了当前arch_abi的2级编译目录
	sh ../../${MY_DIR}/configure \
		--prefix=${PREFIX} \
		--target-os=android \
		--arch=${ARCH} \
		--cpu=${CPU}  \
		--sysroot=$SYSROOT \
		--cross-prefix=${CROSS_PREFIX} \
		--extra-cflags="-I$SYSROOT/usr/include ${CFALGS}" \
		--cc=$TOOLCHAIN/bin/${SINGLE_CROSS_PREFIX_NAME}-gcc \
		--nm=$TOOLCHAIN/bin/${SINGLE_CROSS_PREFIX_NAME}-nm \
		--disable-asm \
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
		--disable-ffserver \
		--disable-postproc \
		--disable-avdevice \
		--disable-symver \
		--disable-stripping
		
	make clean
	make -j3
	make install

	#从当前arch_abi编译目录跳出，对应上面的cd ${BUILD_DIR},以便function多次执行
    cd ../../

	echo "-------------------$2 build end-------------------------"
}


#build armeabi
#build_bin arm armeabi arm-linux-androideabi arm-linux-androideabi "$ANDROID_ARMV5_CFLAGS" armv5te

#build armeabi-v7a
#build_bin arm armeabi-v7a arm-linux-androideabi arm-linux-androideabi "$ANDROID_ARMV7_CFLAGS" armv7-a
#build arm64-v8a
#build_bin arm64 arm64-v8a aarch64-linux-android aarch64-linux-android "$ANDROID_ARMV8_CFLAGS" armv8-a

#build x86
#build_bin x86 x86 x86 i686-linux-android "$ANDROID_X86_CFLAGS" i686

#build x86_64
build_bin x86_64 x86_64 x86_64 x86_64-linux-android "$ANDROID_X86_64_CFLAGS" x86-64

