cd ramdisk/ramdisk-common
find . | fakeroot cpio -H newc -o | lzma -e -9 > ../boot.img-ramdisk.cpio.lzma
cd ../../
mkbootimg --base 0x10000000 --pagesize 2048 --kernel zImage --ramdisk ramdisk/boot.img-ramdisk.cpio.lzma -o ramdisk/data/media/cm.img
cp -f $HOME/kernel/activekernel-jalteskt/stock/ramdisk/data/media/stock.img ramdisk/data/media/stock.img
cp -f $HOME/kernel/activekernel-jalteskt/stock/ramdisk/data/media/stock.img ramdisk/data/media/boot.img
cd ramdisk
zip -r Multiboot_kernel_e300_v5.0.zip META-INF data boot.img
mv -v Multiboot_kernel_e300_v5.0.zip ../
cd ../
rm -rf $HOME/kernel/activekernel-jalteskt/stock/ramdisk/data/media/cm.img
cp -f ramdisk/data/media/cm.img $HOME/kernel/activekernel-jalteskt/stock/ramdisk/data/media/cm.img
