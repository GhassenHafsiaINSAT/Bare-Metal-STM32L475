## Linker and locator  

- **Linker** is used to merge similar sections of different object files and to resolve all undefined symbols of different objects 

- **Locator** is part of linker, and takes the help of the linker script to understand how you wish merge different sections and assign mentionned addresses to different sections  

- Linker scripts are written using the **GNU linker command language** 

- GNU linker script has the file extension `.ld`

- You can supply linker script at the linking phase using `-T` option 


## Linker scripts commands 

- **ENTRY**

- **MEMORY**

- **SECTIONS**

- **KEEP**

- **ALIGN**

- **AT>**