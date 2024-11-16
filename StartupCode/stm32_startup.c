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
void DMA1_CH1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH4_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH5_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH6_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA1_CH7_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void ADC1_2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_TX_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_RX0_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_RX1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void CAN1_SCE_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI9_5_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_BRK_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_UP_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_TRG_COM_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM1_CC_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM4_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C1_EV_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C1_ER_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C2_EV_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void I2C2_ER_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void USART3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void EXTI15_10_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void RTC_ALARM_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_BRK_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_UP_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_TRG_COM_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM8_CC_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void ADC3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void FMC_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SDMMC1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM5_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void SPI3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void UART4_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void UART5_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM6_DACUNDER_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void TIM7_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH3_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH4_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DMA2_CH5_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT0_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void DFSDM1_FLT2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void COMP_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void LPTIM1_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void LPTIM2_handler(void) __attribute__((weak, alias("Default_handler")));     // default handler for all interrupts 
void OTG_FS_handler(void) __attribute__((weak, alias("Default_handler"))); 
void DMA2_CH6_handler(void) __attribute__((weak, alias("Default_handler"))); 
void DMA2_CH7_handler(void) __attribute__((weak, alias("Default_handler"))); 
void LPUART1_handler(void) __attribute__((weak, alias("Default_handler"))); 
void QUADSPI_handler(void) __attribute__((weak, alias("Default_handler"))); 
void I2C3_EV_handler(void) __attribute__((weak, alias("Default_handler"))); 
void I2C3_ER_handler(void) __attribute__((weak, alias("Default_handler"))); 
void SAI1_handler(void) __attribute__((weak, alias("Default_handler"))); 
void SAI2_handler(void) __attribute__((weak, alias("Default_handler"))); 
void SWPMI1_handler(void) __attribute__((weak, alias("Default_handler"))); 
void TSC_handler(void) __attribute__((weak, alias("Default_handler"))); 
void LCD_handler(void) __attribute__((weak, alias("Default_handler"))); 
void AES_handler(void) __attribute__((weak, alias("Default_handler"))); 
void RNG_and_HASH_handler(void) __attribute__((weak, alias("Default_handler"))); 
void FPU_handler(void) __attribute__((weak, alias("Default_handler"))); 
void HASH_and_CRS_handler(void) __attribute__((weak, alias("Default_handler"))); 

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
    (uint32_t) &WWDG_handler,
    (uint32_t) &PVD_PVM_handler,
    (uint32_t) &RTC_TAMP_STAMP_handler,
    (uint32_t) &RTC_WKUP_handler,
    (uint32_t) &FLASH_handler,
    (uint32_t) &RCC_handler,
    (uint32_t) &EXTI0_handler,
    (uint32_t) &EXTI1_handler,
    (uint32_t) &EXTI2_handler,
    (uint32_t) &EXTI3_handler,
    (uint32_t) &EXTI4_handler,
    (uint32_t) &DMA1_CH1_handler,
    (uint32_t) &DMA1_CH2_handler,
    (uint32_t) &DMA1_CH3_handler,
    (uint32_t) &DMA1_CH4_handler,
    (uint32_t) &DMA1_CH5_handler,
    (uint32_t) &DMA1_CH6_handler,
    (uint32_t) &DMA1_CH7_handler,
    (uint32_t) &ADC1_2_handler,
    (uint32_t) &CAN1_TX_handler,
    (uint32_t) &CAN1_RX0_handler,
    (uint32_t) &CAN1_RX1_handler,
    (uint32_t) &CAN1_RX1_handler,     
    (uint32_t) &CAN1_SCE_handler,
    (uint32_t) &EXTI9_5_handler,
    (uint32_t) &TIM1_BRK_handler,
    (uint32_t) &TIM1_UP_handler, 
    (uint32_t) &TIM1_TRG_COM_handler,
    (uint32_t) &TIM1_CC_handler, 
    (uint32_t) &TIM2_handler,
    (uint32_t) &TIM3_handler,
    (uint32_t) &TIM4_handler,
    (uint32_t) &I2C1_EV_handler,
    (uint32_t) &I2C1_ER_handler, 
    (uint32_t) &I2C2_EV_handler,
    (uint32_t) &I2C2_ER_handler, 
    (uint32_t) &SPI1_handler,
    (uint32_t) &SPI2_handler,
    (uint32_t) &USART1_handler,
    (uint32_t) &USART2_handler,
    (uint32_t) &USART3_handler, 
    (uint32_t) &EXTI15_10_handler, 
    (uint32_t) &RTC_ALARM_handler,
    (uint32_t) &DFSDM1_FLT3_handler,
    (uint32_t) &TIM8_BRK_handler,
    (uint32_t) &TIM8_UP_handler, 
    (uint32_t) &TIM8_TRG_COM_handler, 
    (uint32_t) &TIM8_CC_handler,
    (uint32_t) &ADC3_handler,
    (uint32_t) &FMC_handler,
    (uint32_t) &SDMMC1_handler,
    (uint32_t) &TIM5_handler, 
    (uint32_t) &SPI3_handler, 
    (uint32_t) &UART4_handler,
    (uint32_t) &UART5_handler,
    (uint32_t) &TIM6_DACUNDER_handler,
    (uint32_t) &TIM7_handler,
    (uint32_t) &DMA2_CH1_handler,
    (uint32_t) &DMA2_CH2_handler,
    (uint32_t) &DMA2_CH3_handler,
    (uint32_t) &DMA2_CH4_handler,
    (uint32_t) &DMA2_CH5_handler,
    (uint32_t) &DFSDM1_FLT0_handler,
    (uint32_t) &DFSDM1_FLT1_handler,
    (uint32_t) &DFSDM1_FLT2_handler, 
    (uint32_t) &COMP_handler,
    (uint32_t) &LPTIM1_handler,
    (uint32_t) &LPTIM2_handler,
    (uint32_t) &OTG_FS_handler,
    (uint32_t) &DMA2_CH6_handler,
    (uint32_t) &DMA2_CH7_handler,
    (uint32_t) &LPUART1_handler,
    (uint32_t) &QUADSPI_handler, 
    (uint32_t) &I2C3_EV_handler,
    (uint32_t) &I2C3_ER_handler,
    (uint32_t) &SAI2_handler,
    (uint32_t) &TSC_handler,
    (uint32_t) &LCD_handler,
    (uint32_t) &AES_handler,
    (uint32_t) &RNG_and_HASH_handler, 
    (uint32_t) &FPU_handler,
    (uint32_t) &HASH_and_CRS_handler
};

void Reset_handler(void){
    while(1);
}

void Default_handler(void){    // default handler for all interrupts 
    while(1); 
}

void NMI_handler(void){
    while(1);
} 
void HardFault_handler(void){
    while(1);
} 
void MemManage_handler(void){
    while(1);
}
void BusFault_handler(void){
    while(1);
}
void UsageFault_handler(void) {
    while(1);
}
void SVCall_handler(void) {
    while(1);
} 
void Debug_handler(void) {
    while(1);
} 
void PendSV_handler(void) {
    while(1);
} 
void SysTick_handler(void){
    while(1);
}
void WWDG_handler(void){
    while(1);
} 
void PVD_PVM_handler(void){
    while(1);
}
void RTC_TAMP_STAMP_handler(void) {
    while(1);
} 
void RTC_WKUP_handler(void) {
    while(1);
}
void FLASH_handler(void) {
    while(1);
}
void RCC_handler(void) {
    while(1);
} 
void EXTI0_handler(void) {
    while(1);
}bute__((weak, alias("Default_handler"))); 

void SWPMI1_handler(void){
    while(1);
}
void TSC_handler(void){
    while(1);
}
void LCD_handler(void){
    while(1);
}
void AES_handler(void){
    while(1);
}
void RNG_and_HASH_handler(void){
    while(1);
}
void FPU_handler(void){
    while(1);
}
void HASH_and_CRS_handler(void){
    while(1);
}