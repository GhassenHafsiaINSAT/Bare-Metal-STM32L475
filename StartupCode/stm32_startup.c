#include <stdint.h>


#define SRAM_START 0x20000000U
#define SRAM_SIZE (96 * 1024)   // 96 KB
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

void Reset_handler(void); 

void NMI_handler(void) __attribute__((weak, alias("Default_handler"))); 
void HardFault_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void MemManage_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void BusFault_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void UsageFault_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SVCall_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void Debug_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void PendSV_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SysTick_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 

void WWDG_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void PVD_PVM_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void RTC_TAMP_STAMP_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void RTC_WKUP_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void FLASH_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void RCC_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI0_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI4_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH4(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH5(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH6(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH7(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void ADC1_2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_TX(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_RX0(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_RX1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_SCE(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI9_5(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_BRK(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_UP(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_TRG_COM(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_CC(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM4(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C1_EV(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C1_ER(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C2_EV(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C2_ER(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI15_10(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void RTC_ALARM(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_BRK(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_UP(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_TRG_COM(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_CC(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void ADC3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void FMC(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SDMMC1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM5(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void UART4(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void UART5(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM6_DACUNDER(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM7(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH3(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH4(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH5(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT0(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void COMP(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void LPTIM1(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void LPTIM2(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void OTG_FS(void) __attribute__((weak, alias("Default_handler"))); 
void DMA2_CH6(void) __attribute__((weak, alias("Default_handler"))); 
void DMA2_CH7(void) __attribute__((weak, alias("Default_handler"))); 
void LPUART1(void) __attribute__((weak, alias("Default_handler"))); 
void QUADSPI(void) __attribute__((weak, alias("Default_handler"))); 
void I2C3_EV(void) __attribute__((weak, alias("Default_handler"))); 
void I2C3_ER(void) __attribute__((weak, alias("Default_handler"))); 
void SAI1(void) __attribute__((weak, alias("Default_handler"))); 
void SAI2(void) __attribute__((weak, alias("Default_handler"))); 
void SWPMI1(void) __attribute__((weak, alias("Default_handler"))); 
void TSC(void) __attribute__((weak, alias("Default_handler"))); 
void LCD(void) __attribute__((weak, alias("Default_handler"))); 
void AES(void) __attribute__((weak, alias("Default_handler"))); 
void RNG_and_HASH(void) __attribute__((weak, alias("Default_handler"))); 
void FPU(void) __attribute__((weak, alias("Default_handler"))); 
void HASH_and_CRS(void) __attribute__((weak, alias("Default_handler"))); 

uint32_t vectors[] __attribute__ ((section(".vector_table"))) = {
    STACK_START, 
    (uint32_t) &Reset_handler, 
    (uint32_t) &NMI_handler, 
    (uint32_t) &HardFault_handler, 
    (uint32_t) &MemManage_handler,
    (uint32_t) &BusFault_handler, 
    (uint32_t) &UsageFault_handler, 
    0, 
    (uint32_t) &SVCall_handler, 
    (uint32_t) &Debug_handler,  
    0,
    (uint32_t) &PendSV_handler, 
    (uint32_t) &SysTick_handler, 




};

void Reset_handler(void){
    
}

void Default_handler(void){    // default handler for all interrupts 
    while(1); 
}