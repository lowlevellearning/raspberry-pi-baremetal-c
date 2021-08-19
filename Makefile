default:
	arm-none-eabi-as -o start.o start.s
	arm-none-eabi-gcc -c -o main.o main.c -I ./include
	arm-none-eabi-gcc -T linker.ld -o kernel7.elf start.o main.o -ffreestanding -O2 -nostdlib -lgcc
	arm-none-eabi-objcopy kernel7.elf -O binary kernel7.img