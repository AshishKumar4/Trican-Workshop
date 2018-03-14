Trican-Workshop

FOR ANY ASSIST, Refer to https://wiki.osdev.org/Main_Page

REQUIREMENTS:
1. (WINDOWS USERS) Install Cygwin and also install 'make, nasm' through the Cygwin Installer (Remember to click 'Keep' Radio button Instead of current, you would understand when you see it). https://www.cygwin.com/setup-x86.exe
2. (WINDOWS USERS) GCC Cross Compiler https://github.com/lordmilko/i686-elf-tools/releases (Copy the contents into the cygwin installation folder), Linux Users refer to https://wiki.osdev.org/GCC_Cross-Compiler; Alternative download : https://drive.google.com/open?id=0B9reqedTHQRTT3BZcml0T1JKV1E
3. Type in cygwin -> export PATH="/opt/cross/bin:$PATH"
4. QEMU https://www.qemu.org/download 
5. Visual Code Editor
7. Download this repo as 'Zip' and unzip the content to Cygwin/Home/<Whatever your username is, check your folder>
8. type "cd trican-workshop-master" or whatever you renamed it as, just CD to the folder.
9. type "cd <Whatever Level you wanna go>" and then type "make" to compile, "make qemu" to run.
10. Patience and a little grey matter.

If you got stuck, refer to https://wiki.osdev.org/GCC_Cross-Compiler.

Level 1 -> "Getting Started, Hello World program on bare metal"
Level 2 -> "Descriptor Tables, Make way to an OS"
Level 3 -> "Interrupts and PIC Chip"
Level 4 -> "PIT Timer"
Level 5 -> "A Simple Memory Allocation Algorithm"
Level 6 -> "Basic Keyboard driver"
Level 7 -> "Simple Premptive Multitasking System"
Trican (Level 8) -> "Our final kernel with a working Shell which runs as a process"
