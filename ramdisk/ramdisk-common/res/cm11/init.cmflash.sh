#!/sbin/busybox sh
cd /
dd if=/data/media/cm.img of=/dev/block/mmcblk0p9 
reboot
