## Compilation and Toolchain

- Compilation is converting a high level file (C, C++, Python ..) into an executable 

- An executable is embedded target specific machine code 

- Cross Compilation is a process in which a cross toolchain that runs on host/local machine (your computer) and geenrates executables that run on target machine with different architecture (MCU)

- Toolchain or Cross toolchain is a collection of binaries which allows you to compile, assemble and link your applications 

## Cross toolchain important binaries 

```bash 
arm-none-eabi-gcc       # compiler, linker and assembler 

arm-none-eabi-as        # assembler 

arm-none-eabi-ld        # linker

arm-none-eabi-objcopy   # format converter 

arm-none-eabi-readelf   # ELF file analyzer
```

## Build Process 

1.  **Pre-Process stage ( .c -> .i )**:  
    - All pre-processed directives will be resolved 

2.  **Code generation stage( .i -> .s )**: 
    - Translating a source file into assembly language, Higher level language code statements will be converted into processor architectural level mnemonics

3.  **Assembler stage ( .s -> .o )**: 
    - Assembly level mnemonics are converted into opcodes (machines codes for instructions)
    - It converts assembler to relocatable object file with no absolute addresses of the program memory, they carry an address that can be relocatable

4.  **Linking stage (*.o, *.a ->  .elf )**: 
- All executable object files are merged together to create one executable file (.elf)

## Compilation arguments 

- To compile a source file into an object file :
    ```bash 
    arm-none-eabi-gcc source_file.c
    ```

- You can add `-c` to tell the compiler juste compile and assemble (without linking): 
    ```bash 
    arm-none-eabi-gcc -c source_file.c
    ```
- You can add `-S` to tell the compiler juste compile (without assembling and linking): 
    ```bash 
    arm-none-eabi-gcc -S source_file.c -o main.s
    ```
- You can add `-o` to specify output file: 
    ```bash 
    arm-none-eabi-gcc -o output_file.o source_file.c
    ```

- You can add `-mcpu` to specify the target cpu: 
    ```bash 
    arm-none-eabi-gcc -mcpu=cortex-m4 source_file.c
    ```

- You can add `-march` to clarify the architecture of your target 
    ```bash
    arm-none-eabi-gcc -march=armv7-m source_file.c
    ```

- Add `-mthumb` to switch to Thumb mode, generating 16-bit instructions instead of the default 32-bit instructions
    ```bash 
    arm-none-eabi-gcc -mthumb source_file.c
    ```

## Relocatable object file 
- `main.o` is relocatable object file, it contains only machine code file, and doesn't contain absolute addresses for data and code 

- To check the content of the object file you can use: 
```bash 
arm-none-eabi-objdump -h main.o 
```
- `-h` argument is to check the different arguments 