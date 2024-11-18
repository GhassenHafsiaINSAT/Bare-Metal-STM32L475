## Sytem Control Block 
- The system control Block is a hardware component integrated within the Cortex-M4 processor core itself

- It is part of core peripherals, which are mapped into the processor's **system control block** in the memory address space 

- The **SCB** registers are located in the memory region starting at `0xE000ED00`

- The **SCB** manages and reports System exceptions, it helps configuring exception handling and providing status information about faults

## SCB registers for fault handling 

1. **SHCSR (System Handling Control and State Regiters)** : It enables status of fault exceptions 
    - bit 18: enables **Usage Fault**
    - bit 17: enables **Bus Fault**
    - bit 16: enabmes **Memory Management Fault

2. **CFSR (Configurable Fault Status Register)**: It reports the cause of the fault 
    - **UFSR** : Reports Usage fault conditions  
    - **BFSR** : Rports Bus fault conditions 
    - **MMFSR** reports Memory Management Fault

3. **HFSR (Hard Fault Stauts Register)**
    - **Hard Fault** is a type of exception that occures when a fault condition is not handled by the other fault handlers such as Memory Management fault, Bus fault or Usage fault 
    - **HFSR**: provides details on **Hard Fault**, if it is escalated from other types of faults 

4. **MMFAR (Memory Mangement Fault Address Register)**
    - Stores the address where the Memory Manegement Fault occured 

5. **BFAR (Bus Fault Address Register)**
    - Stores the address where the Bus Fault occured   



## Mmoery fault exception 
Bit 0: Memory management fault on unaligned access
Bit 1: Memory management fault on non-executable access
Bit 2: Prohibited memory access (e.g., trying to write to a read-only section)
Bit 3: Fault on stacking for exception entry

## Bus fault exception 
Bit 8: BusFault on an instruction fetch (an invalid instruction fetch occurred)
Bit 9: BusFault on data read (an invalid data read)
Bit 10: BusFault on data write (an invalid data write)
Bits 11-12: Additional bus fault information related to faulting behavior


## Usage fault exception 
Bit 16: Divide-by-zero error
Bit 17: Invalid instruction (undefined instruction)
Bit 18: Invalid state (e.g., using a floating-point operation when FPU is not enabled)
Bit 19: Reserved for future usage
Bit 20-23: Additional faults that the architecture may define.