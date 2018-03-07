Welcome to the first Level. 
Here We start with the very basic 'Hello World' OS
The seed has been sown and a Directory Tree has started to germinate.

An OS is the most basic and low level program running on a computer
after BIOS. To code an OS is to write a program that can manipulate the
hardware directly, No working on abstraction layers; 
You don't have any Library to use! You dont have 'stdio.h' or 'stdlib.h'
or any header file you may wish to use. You have to MAKE your OWN Libraries,
Your OWN PRINTF function, Your own MALLOC, strlen, memcpy etc. 
In OS Development, Everything you are going to use (software), 
You have to make it first!

We have made a bootup Sequence to initialize the System and a VGA Driver
to enable us to display characters on the screen, and a basic 'C Library'
to provide functions like printf etc.

When the computer is switched ON, BIOS takes over the control and passes it 
onto a program called 'Bootloader' from any 'Bootable Disk' it finds attached
to the system. This Bootloader program then initializes and initiates the 
booting of rest of the system.
Bootloaders can either be an integral part of an OS, like in the case of Windows
and MAC OS, Or Can be a seperate program altogether like GRUB. 

We are going to use the GRUB2 Bootloader (Although You can write your own if you wish to).
GRUB2 is an Open Source and Powerfull General Bootloader, With a wide range of 
OSs having support/relying on it. It supports Multiboot too, Enabling the installation
of multiple OSs on the same disk.

The GRUB2 Bootloader searches for a specific sequence of numbers, called 'Magic Number'
in specific locations on the disk. When Found and verified for a supported OS,
It hands over the CPU to the OS Code. Look into the 'Boot.asm' File.
After initializing a working stack, We switch to our C Kernel,
Where we initialize the VGA Drivers and printing blank characters on the screen.
Look into the 'vga.c' file. 
printf function defined in stdio.c file is a high level abstraction over the basic
VGA handling functions.

Try to grasp the directory structure for the next levels are going to even more complex!

