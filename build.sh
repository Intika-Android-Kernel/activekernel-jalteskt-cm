#!/bin/sh
########################################
# Samsung Exynos5 Active Kernel Source #             
#              bestmjh47               #
########################################
rm -rf .version
rm -rf *.img
rm -rf *.zip
rm -rf ramdisk/*.gz
rm -rf ramdisk/*.img
rm -rf ramdisk/*.zip
TOOLCHAINPATH=/$HOME/toolchain/arm-eabi-4.7/bin
export ARCH=arm
export CROSS_COMPILE=$TOOLCHAINPATH/arm-eabi-
make cyanogenmod_jalteskt_defconfig
echo #############################
echo #       Now Starting...     #
echo #############################
make -j25
cp arch/arm/boot/zImage zImage
echo Striping Modules...
rm -rf Modules
mkdir Modules
find -name '*.ko' -exec cp -av {} Modules \;
        for i in Modules/*; do $TOOLCHAINPATH/arm-eabi-strip --strip-unneeded $i;done;\
#rm -rf ramdisk/ramdisk-common/lib/modules/dhd.ko
#cp Modules/dhd.ko ramdisk/ramdisk-common/lib/modules/dhd.ko
cd ramdisk/ramdisk-common
find . | fakeroot cpio -H newc -o | lzma -e -9 > ../boot.img-ramdisk.cpio.lzma
cd ../../
mkbootimg --base 0x10000000 --pagesize 2048 --kernel zImage --ramdisk ramdisk/boot.img-ramdisk.cpio.lzma -o ramdisk/boot.img
cd ramdisk
zip -r Multiboot-E300S-bestmjh47_kernel_CM.zip META-INF boot.img
mv -v Multiboot-E300S-bestmjh47_kernel_CM.zip ../
cd ../
echo ""
echo done! 

