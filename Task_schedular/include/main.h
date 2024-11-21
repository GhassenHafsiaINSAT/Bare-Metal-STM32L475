#include <stdint.h>

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
#define MAX_TASK                            4

#define TICK_HZ                             1000U
#define HSI_CLOCK                           160000000U
#define SYSTICK_TIM_CLK                     HSI_CLOCK

#define DUMMY_XPSR 0X00100000U

