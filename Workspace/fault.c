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

*pSHCSR |= (1<<16); // Mem manage
*pSHCSR |= (1<<17); // bus fault
*pSHCSR |= (1<<18); // usage fault



}

void HardFault_Handler(void){
    printf("Exception: HardFault\n"); 
    while (1); 
    
}
void MemManage_Handler(void){
    printf("Exception: MemManage\n"); 
    while (1); 
}
void BusFault_Handler(void){
    printf("Exception: BusFault\n"); 
    while (1); 
}
void UsageFault_Handler(void){
    volatile uint32_t *pUFSR = (uint32_t*)0xE000ED2A; //Since UFSR is hardware register, we use volatile to prevent compiler from optimizing its access usage fault status register
    printf("Exception: UsageFault\n"); 
    printf("UFSR = %lx\n", (*pUFSR) & 0xFFFF); 
    while (1); 
}