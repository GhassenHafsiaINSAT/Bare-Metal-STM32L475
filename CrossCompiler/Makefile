CC = arm-none-eabi-gcc
MACHINE = cortex-m4
CFLAGS = -c -mthumb -mcpu=$(MACHINE) -save-temps
LFLAGS = -nostdlib -T stm32L47x.ld 


main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

linker: *.o
	$(CC) $(LFLAGS) $^ -o final.elf

clean: 
	rm -r *.o 