CC:=i686-elf-gcc
LD:=i686-elf-ld
NASM:=nasm

SOURCE:=Source
ASSEMBLY:=$(SOURCE)/ASM
KLIBRARY:=$(SOURCE)/KLibrary
INCLUDED:=-I$(KLIBRARY) -I$(SOURCE)

KERNEL:=$(SOURCE)/kernel.o

OBJ_DIR:=$(ASSEMBLY)
SRC_FILES := $(wildcard $(ASSEMBLY)/*.asm)
OBJ_FILES := $(patsubst $(ASSEMBLY)/%.asm,$(ASSEMBLY)/%.o,$(SRC_FILES))

FLAGS:= -O0 -ffreestanding -fbuiltin -Wall -Wextra -nostdlib -lgcc -fno-builtin -fno-stack-protector $(INCLUDED)

all: clean build-asm build-kernel

clean:
	rm -f build-kernel *.o */*.o */*/*.o
	rm -rfv objs
	rm -rfv isodir

build-asm: $(OBJ_FILES)

build-kernel: $(KERNEL) linker.ld
	$(LD) -T linker.ld -o $(OBJ_DIR)/Trican $(OBJ_FILES) $(KERNEL)
	cp $(OBJ_DIR)/Trican Trican.bin
	make clean
	echo -e "\n\n\n\n\tKernel Built Successfully! Run it using "make qemu". \n\tBe sure to modify it accordingly!!!"

build-iso:
	sh grub_config.sh
	grub-mkrescue -o Trican.iso --modules="multiboot normal ext2 part_msdos" isodir

build-assembly:
	$(CC) -T linker.ld $(FLAGS) -S -m32 $(SOURCE)/kernel.c

build-objdump:
	objdump -D -M intel Trican.bin > Trican.txt

qemu:
	qemu-system-i386 -smp 4 -m 4G -kernel Trican.bin -monitor stdio

%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS)

%.o: %.cpp
	$(CPP) -c $< -o $@ $(FLAGS)

%.o: %.asm
	$(NASM)	-f elf $< -o $@

%.o: %.S
	$(AS) $< -o $@
