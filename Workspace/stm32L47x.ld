ENTRY(Reset_handler)    /* Use the Reset_handler as entry point */

MEMORY
{
    FLASH(rx):   ORIGIN = 0x08000000, LENGTH = 0x80000  /* 512 KB*/

    SRAM1(rwx):  ORIGIN = 0x20000000, LENGTH = 0x18000  /* 96 KB*/

    SRAM2(rwx):  ORIGIN = 0x20018000, LENGTH = 0x8000   /* 32 KB*/
}


SECTIONS
{
    .text : 
    {   
        KEEP(*(.vector_table)) 
        *(.text)        
        *(.rodata)      
        _etext = .; /* location counter always track vma */

    } > FLASH AT> FLASH

    .data : 
    {   
        _sdata = .; 
        *(.data)    
        _edata = .; 
    } > SRAM1 AT> FLASH

    .bss :
    {   
        _sbss  = .; 
        *(.bss)
        _ebss = .; 

    } > SRAM1
}