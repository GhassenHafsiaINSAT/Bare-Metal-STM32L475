## Linker and locator  

- **Linker** is used to merge similar sections of different object files and to resolve all undefined symbols of different objects 

- **Locator** is part of linker, and takes the help of the linker script to understand how you wish merge different sections and assign mentionned addresses to different sections  

- Linker scripts are written using the **GNU linker command language** 

- GNU linker script has the file extension `.ld`

- You can supply linker script at the linking phase using `-T` option 


## Linker scripts commands 

- **ENTRY**:
    - This is the entry point address of the elf file
    - The debugger uses this information to locate the first function to execute 
    - In out case, "Reset_handler" is the entry point of the application
    ```ld
    ENTRY(Reset_handler)
    ```

- **MEMORY**:
    - It allows you to describe the different memories present in the target and their start address and size information 
    - The linker uses information mentioned in this command to assign addresses to merged sections 
    ```ld
    MEMORY 
    {
        name(attr) : ORIGIN = origin, LENGTH = length
    }
    ```

- **SECTIONS**: 
    - Create different output sections in the final executable 
    ```ld
    SECTIONS
    {
        .text: 
        {

        } >(vma) AT>(lma)

        .data: 
        {

        } >(vma) AT>(lma)
    }
- **KEEP**

- **ALIGN**

- **AT>**

## Linker script symbols 
- `.` : the current symbol counter 


- To analyze an `.elf` file, you can use tools like `arm-none-eabi-readelf` or `arm-none-eabi-objdump`, but there is a better solution is to instruct linker to create a **map file** 

    ```
    arm-none-eabi-gcc -nostdlib -T linker_script.ld -Wl,-Map = final.map -o final.elf *.o 
    ```

    - Here as you can see, we used `-nostdlib` to not include standaard library, `-T` to provide the linker with our personnal linker script and finally `-Map` to generate a map file. Adding `-Wl,` is just to make sure to the linker that `-Map=final.map` is a linker argument 

-  
