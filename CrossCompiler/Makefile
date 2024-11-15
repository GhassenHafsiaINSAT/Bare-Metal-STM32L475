CC = arm-none-eabi-gcc
MACHINE = cortex-m4
CFLAGS = -c -mthumb -mcpu=$(MACHINE) -save-temps


main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -r *.o 