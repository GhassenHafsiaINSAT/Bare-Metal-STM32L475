## Different data of a program and related sections 

- Uninitialized global variables, are not important because they do not carry any valuable information, so we don't have to store it in flash memory and lose space

- initialized global variables carry important data so it will be stored in flash memory in data section 

- local uninitliazed and initalized data are created in stack and do not have any section because they are transient data, created and destroyed dynamically when program control enters function 

- local uninitliazed static data are private to a function, so they are treated like global variables and stored in .bss section 

- local initliazed static data are private to a function, so they are treated like global variables and stored in .data section 

## Startup file 

- The startup file is responsible for setting up the environment for the main user code to run, it calls `main()`

- Startup code takes care of vector table placement in code memory as required by the ARM cortex Mx processor 

- Startup code is reponsible of .data, .bss section initialization in main memory 

- Startup code can also take care of stack initialization  

## How to wrtie start-up file?

### Creating a vector table for your microcontroller 

- You have to create an array to hold MSP (main stack pointer) and handlers addresses 

- You have to instruct the compiler not to include the above array in .data section but in a different user defined section 

- so by checking the reference manual of your mcu, you can check the vector table section, and see the total number of IRQs, i am using stm32L47x so 83 



2. Write a start up code that initalizes .data and .bss sections in SRAM 

3. Call main()

