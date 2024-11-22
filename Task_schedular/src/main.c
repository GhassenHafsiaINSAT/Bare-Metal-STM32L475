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
void enable_processor_fault(void); 
__attribute__ ((naked)) void switch_sp_to_psp(void); 

uint32_t psp_value[MAX_TASK] = {T1_STACK_START, T2_STACK_START, T3_STACK_START, T4_STACK_START}; 

uint32_t task_handlers[MAX_TASK]; 

uint8_t current_task = 0; 

int main(void){

    enable_processor_fault(); 

    init_schedular_stack(SCHEDULAR_STACK_START); 

    task_handlers[0] = (uint32_t) task1_handler;
    task_handlers[1] = (uint32_t) task2_handler; 
    task_handlers[2] = (uint32_t) task3_handler;
    task_handlers[3] = (uint32_t) task4_handler;
    
    init_tasks_stack(); 
    init_systick_timer(TICK_HZ); 
    switch_sp_to_psp(); 

    task1_handler(); 
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

void save_psp_value (uint32_t current_task_value){
    psp_value[current_task] = current_task_value; 
}

void update_task (void){
    current_task ++; 
    current_task  %= MAX_TASK; 
}

void Systick_Handler(void){
    /*  save the context of the current task*/
        
    // get current running task's psp value
    __asm volatile ("MRS R0, PSP"); 
    // using psp save the second stack frame because the first frame is already saved by the compiler 
    __asm volatile ("STMDB RO!, {R4-R11}"); 
    // save the current value of psp   
    __asm volatile ("BL save_psp_value"); 


    /*Retrieve the context of next task*/
    //1. Decide next stack to run 
    __asm volatile ("BL update_task"); 
    // get its psp value
    __asm volatile ("BL get_psp_value");
    // using psp value, retrieve sf2 
    __asm volatile ("LDMIA R0!, {R4-R11}"); 
    // update psp and exit 
    __asm volatile ("MSR PSP, R0"); 


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

void enable_processor_fault(void){
    uint32_t *pSHCSR = (uint32_t*)0xE000ED24; 

    *pSHCSR |= (1<<16); // enable Mem manage
    *pSHCSR |= (1<<17); // enable bus fault
    *pSHCSR |= (1<<18); // enable usage fault
} 

uint32_t get_psp_value(void){
    return psp_value[current_task]; 
}


__attribute__ ((naked)) void switch_sp_to_psp(void){
    // initialize the psp with task1 stack start
    __asm volatile ("PUSH {LR}"); 
    __asm volatile ("BL get_psp_value"); 
    __asm volatile ("MSR PSP, R0"); 
    __asm volatile ("POP {LR}"); 

    // change sp to psp using control register  
    __asm volatile ("MOV R0, #0x02"); 
    __asm volatile ("MSR CONTROL, R0"); 
    __asm volatile ("BX LR");
}   

