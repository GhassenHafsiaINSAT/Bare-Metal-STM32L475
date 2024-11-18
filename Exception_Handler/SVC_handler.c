#include <stdint.h>
#include <stdio.h>


int main(void){
    __asm("SVC 0x08"); 
}


__attribute__ ((naked)) void SVC_Handler(void){
    __asm("MSR r0, MSP"); 
    __asm("B SVC_Handler_c"); 
}

void SVC_Handler_c (uint32_t *pMSP_address){
    printf("SVC Handler"); 
    uint8_t *pReturnAddress = (uint8_t*)pMSP_address[6]; 
    pReturnAddress -= 2; 
    uint8_t SVC_value = *pReturnAddress; 

    printf("The SVC number is %d\n", SVC_value); 
    while (1); 
     

}