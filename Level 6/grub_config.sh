#!/bin/bash

mkdir -p isodir

mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp Trican.bin isodir/boot/Trican.bin
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "Trican" {
	multiboot /boot/Trican.bin
	boot
}
EOF
