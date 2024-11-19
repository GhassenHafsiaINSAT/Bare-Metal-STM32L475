#include <stdio.h>
#include <stdint.h>


void task1_handler(void); 
void task2_handler(void); 
void task3_handler(void); 
void task4_handler(void); 

#define SIZE_TASK_STACK                     1024U
#define SIZE_SCHEDULAR_STACK                1024U

#define SRAM_START_ADDR                     0X20000000U
#define SIZE_SRAM                           ((128)*(1024))
#define SRAM_END_ADDR                       ((SRAM_START_ADDR) + (SIZE_SRAM))

#define T1_STACK_START                      SRAM_END_ADDR
#define T2_STACK_START                      ((SRAM_END_ADDR) - (SIZE_TASK_STACK))
#define T3_STACK_START                      ((SRAM_END_ADDR) - ((2) * (SIZE_TASK_STACK)))
#define T4_STACK_START                      ((SRAM_END_ADDR) - ((3) * (SIZE_TASK_STACK)))
#define SCHEDULAR_STACK_START               ((SRAM_END_ADDR) - ((4) * (SIZE_TASK_STACK)))

int main(void){
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
    while (1)
    {
        printf("this is task4");
    }
    
}