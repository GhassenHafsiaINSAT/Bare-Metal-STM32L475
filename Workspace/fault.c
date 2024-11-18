#include <stdint.h>
#include <stdio.h>

int main(void){

/*
 - first, enabling all configurable registers like usage fault, memory manage fault and bus fault, 
 they are disabled by default by the CPU
 - SHCSR stands for system  handler and control block register
 and 0xE000ED24 is its own address
 */

uint32_t *pSHCSR = (uint32_t*)0xE000ED24; 

*pSHCSR |= (1<<16); // enable Mem manage
*pSHCSR |= (1<<17); // enable bus fault
*pSHCSR |= (1<<18); // enable usage fault

}

void HardFault_Handler(void){
    printf("Exception: HardFault\n"); 
    while (1); 
    
}
void MemManage_Handler(void){

    printf("Exception: MemManage\n"); 
    int32_t *pCFSR = (int32_t*)0xE000ED28; 

    int32_t CFSR_value = *pCFSR;

    if (CFSR_value &= (1<<0)) printf("Unaligned Memory Access\n"); 
    else if (CFSR_value &= (1<<1)) printf("NX Memory Region: CPU can not fetch instruction\n");
    else if (CFSR_value &= (1<<2)) printf("Prohibited memory access: load, store operations are impossible\n"); 
    else if (CFSR_value &= (1<<3)) printf("Unstacking for a return from exception\n");  


    int32_t *pMMFAR = (int32_t*)0xE000ED34; 
    printf("The address where the Memroy Management Fault occured: %lx\n", *pMMFAR); 


    while (1); 
}
void BusFault_Handler(void){
    
    printf("Exception: BusFault\n"); 
    int32_t *pCFSR = (int32_t*)0xE000ED28; 
    int32_t CFSR_value = *pCFSR;
    if (CFSR_value &= (1<<8)) printf("Invalid instruction fetch\n"); 
    else if (CFSR_value &= (1<<9)) printf("Invalid data read\n");
    else if (CFSR_value &= (1<<10)) printf("Invalid data write\n"); 

    int32_t *pBFAR = (int32_t*)0xE000ED38;
    printf("The address where the Bus Fault occured is %lx", *pBFAR);
    while (1); 
}
void UsageFault_Handler(void){
     
    printf("Exception: UsageFault\n"); 
    int32_t *pCFSR = (int32_t*)0xE000ED28; 
    int32_t CFSR_value = *pCFSR;
    if (CFSR_value &= (1<<16)) printf("Divide-by-zero error\n"); 
    else if (CFSR_value &= (1<<17)) printf("Invalid instruction / undefined instruction\n");
    else if (CFSR_value &= (1<<18)) printf("Invalid state\n");    
     
    while (1); 
}