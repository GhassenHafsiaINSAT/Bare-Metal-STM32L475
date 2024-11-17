CC = arm-none-eabi-gcc
MACHINE = cortex-m4
CFLAGS = -c -mthumb -mcpu=$(MACHINE) -save-temps
LFLAGS = -nostdlib -T stm32L47x.ld -Wl,-Map=final.map

all: main.o add.o startup.o final.elf

main.o: main.c main.h
	$(CC) $(CFLAGS) main.c -o $@

add.o: add.c add.h
	$(CC) $(CFLAGS) add.c -o $@

startup.o: stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o add.o startup.o 
	$(CC) $(LFLAGS) $^ -o $@

clean: 
	rm -f *.o *.elf *.map *.bin *.s *.i 
