#include "include/main.h"
#include <stdio.h>

void task1_handler(void); 
void task2_handler(void); 
void task3_handler(void); 
void task4_handler(void); 
void init_systick_timer(uint32_t tick_hz); 
void init_schedular_stack(uint32_t sched_start_addr); 
__attribute__ ((naked)) void init_schedular_stack(uint32_t sched_start_addr); 
void init_tasks_stack(void); 

uint32_t psp_value[MAX_TASK] = {T1_STACK_START, T2_STACK_START, T3_STACK_START, T4_STACK_START}; 

uint32_t task_handlers[MAX_TASK]; 

int main(void){
    task_handlers[0] = (uint32_t) task1_handler;
    task_handlers[1] = (uint32_t) task2_handler; 
    task_handlers[2] = (uint32_t) task3_handler;
    task_handlers[3] = (uint32_t) task4_handler;
   
    init_schedular_stack(SCHEDULAR_STACK_START); 
    init_systick_timer(TICK_HZ); 
    init_tasks_stack(); 

    return 0; 
}

void task1_handler(void){
    while(1){
        printf("This is task1"); 
    }
}

void task2_handler(void){
    while(1){
        printf("this is task2"); 
    }
}

void task3_handler(void){
    while (1)
    {
        printf("this is task3"); 
    }
    
}

void task4_handler(void){
    while (1) {
        printf("this is task4");
    }   
}


void init_systick_timer(uint32_t tick_hz){

    uint32_t count_value = (SYSTICK_TIM_CLK/tick_hz) - 1; 
    // we will search for reload value, or count value in the ARM generic user guide
    // The reload value in sistyck timer determines how many clock cycles elapse before the time generates an interrupt  
    uint32_t *pSRVR = (uint32_t*) 0xE000E014; 
    // Clear the value of SVR
    *pSRVR &= ~(0x00FFFFFFFF); 
    // load the value to SVR
    *pSRVR |= count_value; 

    uint32_t *pSRCR = (uint32_t*)0xE000E010; 
    // enable ssytick exception request 
    *pSRCR |= (1<<1); 
    // enbale clock source 
    *pSRCR |= (1<<2); 
    // enable the systick 
    *pSRCR |= (1<<0); 

}   

void Systick_Handler(void){

}

void init_tasks_stack(void){
    uint32_t *pPSP; 
    for(int i=0; i<MAX_TASK; i++){
        pPSP --; 
        *pPSP = DUMMY_XPSR;

        pPSP --; //pc
        *pPSP = task_handlers[i];

        pPSP --; //lr
        *pPSP = 0xFFFFFFFD;

        for(int i = 0; i<13; i++){
            pPSP--; 
            *pPSP = 0; 
        }

        psp_value[i] = (uint32_t)pPSP; 
        
    }
}

__attribute__ ((naked)) void init_schedular_stack(uint32_t sched_start_addr){
    __asm volatile ("MSR MSP,%0" : "r" (sched_start_addr) : ); 
    __asm volatile ("BX LR"); 
}

