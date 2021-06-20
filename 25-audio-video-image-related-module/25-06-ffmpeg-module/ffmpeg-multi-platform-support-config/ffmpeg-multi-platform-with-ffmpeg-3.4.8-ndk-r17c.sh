#!/bin/sh

MY_LIBS_NAME=ffmpeg-3.4.8
MY_DIR=ffmpeg-3.4.8

# cd ./${MY_DIR}

#����Ĺ����в������м���Ĵ��Ŀ¼��Ϊ�����ֱ���Ŀ¼��Դ��Ŀ¼��installĿ¼
MY_BUILD_DIR=binary


NDK_PATH=/home/eink/soft_tools/ndk/android-ndk-r17c
BUILD_PLATFORM=linux-x86_64
TOOLCHAIN_VERSION=4.9
ANDROID_VERSION=21

#ANDROID_ARMV5_CFLAGS="-march=armv5te"
ANDROID_ARMV7_CFLAGS="-march=armv7-a -mfloat-abi=softfp -fPIC -DANDROID -mfpu=vfp"  #-mfloat-abi=hard -mfpu=vfpv3-d16 #-mfloat-abi=hard -mfpu=vfp ; -mfpu=neon
#ANDROID_ARMV8_CFLAGS="-march=armv8-a"
#ANDROID_X86_CFLAGS="-march=i686 -mtune=intel -mssse3 -mfpmath=sse -m32"
#ANDROID_X86_64_CFLAGS="-march=x86-64 -msse4.2 -mpopcnt -m64 -mtune=intel"

#export TMPDIR=$(pwd)/ffmpeg-3.4.8/android_export #
# params($1:arch,$2:arch_abi,$3:host,$4:cross_prefix,$5:cflags)
#--cc=$TOOLCHAIN/bin/arm-linux-androideabi-gcc #��ָ����Ҳ���Զ��ҵ��ñ�����
build_bin() {

	echo "-------------------star build $2-------------------------"
	
	ARCH=$1			# arm arm64 x86 x86_64
	ANDROID_ARCH_ABI=$2 	# armeabi armeabi-v7a x86 mips
	PREFIX=$(pwd)/dist/${MY_LIBS_NAME}/${ANDROID_ARCH_ABI}/
	HOST=$3
	SYSROOT=${NDK_PATH}/platforms/android-${ANDROID_VERSION}/arch-${ARCH}
	CFALGS=$5
	TOOLCHAIN=${NDK_PATH}/toolchains/${HOST}-${TOOLCHAIN_VERSION}/prebuilt/${BUILD_PLATFORM}
	CROSS_PREFIX=${TOOLCHAIN}/bin/$4-
	
	# build �м��
    BUILD_DIR=./${MY_BUILD_DIR}/${ANDROID_ARCH_ABI}

	echo "pwd==$(pwd)"
	echo "ARCH==${ARCH}"
	echo "PREFIX==${PREFIX}"
	echo "HOST==${HOST}"
	echo "SYSROOT=${SYSROOT}"
	echo "CFALGS=$5"
	echo "CFALGS=${CFALGS}"
	echo "TOOLCHAIN==${TOOLCHAIN}"
	echo "CROSS_PREFIX=${CROSS_PREFIX}"

	#echo "-------------------------�����������---------------------"
	#read -n 1
	#echo "-------------------------����ִ��-------------------------"
	mkdir -p ${BUILD_DIR}   #������ǰarch_abi�ı���Ŀ¼,����:binary/armeabi-v7a
    cd ${BUILD_DIR}         #�˴� ���˵�ǰarch_abi��2������Ŀ¼
	sh ../../${MY_DIR}/configure \
		--prefix=${PREFIX} \
		--target-os=android \
		--arch=${ARCH} \
		--sysroot=$SYSROOT \
		--enable-cross-compile \
		--cross-prefix=${CROSS_PREFIX} \
		--extra-cflags="$CFALGS -Os -fPIC -DANDROID -Wfatal-errors -Wno-deprecated -isysroot ${NDK_PATH}/sysroot -I${NDK_PATH}/sysroot/usr/include -I${NDK_PATH}/sysroot/usr/include/$4" \
		--extra-cxxflags="-D__thumb__ -fexceptions -frtti" \
		--extra-ldflags="-L${SYSROOT}/usr/lib -fPIC" \
		--nm=$TOOLCHAIN/bin/arm-linux-androideabi-nm \
		--enable-shared \
		--enable-runtime-cpudetect \
		--enable-gpl \
		--disable-doc \
		--disable-ffmpeg \
		--disable-ffplay \
		--disable-ffprobe \
		--disable-symver \
		--disable-debug \
		--disable-static \
		--enable-small \
		--disable-stripping \
		--disable-postproc \
		--disable-avdevice


	make clean
	make
	make install

	#�ӵ�ǰarch_abi����Ŀ¼��������Ӧ�����cd ${BUILD_DIR},�Ա�function���ִ��
    	cd ../../

	echo "-------------------$2 build end-------------------------"
}


# build armeabi
#build_bin arm armeabi arm-linux-androideabi arm-linux-androideabi "$ANDROID_ARMV5_CFLAGS"

#build armeabi-v7a
build_bin arm armeabi-v7a arm-linux-androideabi arm-linux-androideabi "$ANDROID_ARMV7_CFLAGS"

#build arm64-v8a
#build_bin arm64 arm64-v8a aarch64-linux-android aarch64-linux-android "$ANDROID_ARMV8_CFLAGS"

#build x86
#build_bin x86 x86 x86 i686-linux-android "$ANDROID_X86_CFLAGS"

#build x86_64
#build_bin x86_64 x86_64 x86_64 x86_64-linux-android "$ANDROID_X86_64_CFLAGS"
