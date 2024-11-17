	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"stm32_startup.c"
	.text
	.global	vectors
	.section	.vector_table,"aw"
	.align	2
	.type	vectors, %object
	.size	vectors, 380
vectors:
	.word	536969216
	.word	Reset_handler
	.word	NMI_handler
	.word	HardFault_handler
	.word	MemManage_handler
	.word	BusFault_handler
	.word	UsageFault_handler
	.word	0
	.word	SVCall_handler
	.word	Debug_handler
	.word	0
	.word	PendSV_handler
	.word	SysTick_handler
	.word	WWDG_handler
	.word	PVD_PVM_handler
	.word	RTC_TAMP_STAMP_handler
	.word	RTC_WKUP_handler
	.word	FLASH_handler
	.word	RCC_handler
	.word	EXTI0_handler
	.word	EXTI1_handler
	.word	EXTI2_handler
	.word	EXTI3_handler
	.word	EXTI4_handler
	.word	DMA1_CH1_handler
	.word	DMA1_CH2_handler
	.word	DMA1_CH3_handler
	.word	DMA1_CH4_handler
	.word	DMA1_CH5_handler
	.word	DMA1_CH6_handler
	.word	DMA1_CH7_handler
	.word	ADC1_2_handler
	.word	CAN1_TX_handler
	.word	CAN1_RX0_handler
	.word	CAN1_RX1_handler
	.word	CAN1_RX1_handler
	.word	CAN1_SCE_handler
	.word	EXTI9_5_handler
	.word	TIM1_BRK_handler
	.word	TIM1_UP_handler
	.word	TIM1_TRG_COM_handler
	.word	TIM1_CC_handler
	.word	TIM2_handler
	.word	TIM3_handler
	.word	TIM4_handler
	.word	I2C1_EV_handler
	.word	I2C1_ER_handler
	.word	I2C2_EV_handler
	.word	I2C2_ER_handler
	.word	SPI1_handler
	.word	SPI2_handler
	.word	USART1_handler
	.word	USART2_handler
	.word	USART3_handler
	.word	EXTI15_10_handler
	.word	RTC_ALARM_handler
	.word	DFSDM1_FLT3_handler
	.word	TIM8_BRK_handler
	.word	TIM8_UP_handler
	.word	TIM8_TRG_COM_handler
	.word	TIM8_CC_handler
	.word	ADC3_handler
	.word	FMC_handler
	.word	SDMMC1_handler
	.word	TIM5_handler
	.word	SPI3_handler
	.word	UART4_handler
	.word	UART5_handler
	.word	TIM6_DACUNDER_handler
	.word	TIM7_handler
	.word	DMA2_CH1_handler
	.word	DMA2_CH2_handler
	.word	DMA2_CH3_handler
	.word	DMA2_CH4_handler
	.word	DMA2_CH5_handler
	.word	DFSDM1_FLT0_handler
	.word	DFSDM1_FLT1_handler
	.word	DFSDM1_FLT2_handler
	.word	COMP_handler
	.word	LPTIM1_handler
	.word	LPTIM2_handler
	.word	OTG_FS_handler
	.word	DMA2_CH6_handler
	.word	DMA2_CH7_handler
	.word	LPUART1_handler
	.word	QUADSPI_handler
	.word	I2C3_EV_handler
	.word	I2C3_ER_handler
	.word	SAI2_handler
	.word	TSC_handler
	.word	LCD_handler
	.word	AES_handler
	.word	RNG_and_HASH_handler
	.word	FPU_handler
	.word	HASH_and_CRS_handler
	.text
	.align	1
	.global	Reset_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	Reset_handler, %function
Reset_handler:
	@ args = 0, pretend = 0, frame = 32
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #32
	add	r7, sp, #0
	ldr	r2, .L6
	ldr	r3, .L6+4
	subs	r3, r2, r3
	asrs	r3, r3, #2
	str	r3, [r7, #8]
	ldr	r3, .L6+4
	str	r3, [r7, #28]
	ldr	r3, .L6+8
	str	r3, [r7, #24]
	movs	r3, #0
	str	r3, [r7, #20]
	b	.L2
.L3:
	ldr	r2, [r7, #24]
	adds	r3, r2, #1
	str	r3, [r7, #24]
	ldr	r3, [r7, #28]
	adds	r1, r3, #1
	str	r1, [r7, #28]
	ldrb	r2, [r2]	@ zero_extendqisi2
	strb	r2, [r3]
	ldr	r3, [r7, #20]
	adds	r3, r3, #1
	str	r3, [r7, #20]
.L2:
	ldr	r2, [r7, #20]
	ldr	r3, [r7, #8]
	cmp	r2, r3
	bcc	.L3
	ldr	r2, .L6+12
	ldr	r3, .L6+16
	subs	r3, r2, r3
	asrs	r3, r3, #2
	str	r3, [r7, #4]
	ldr	r3, .L6+16
	str	r3, [r7, #16]
	movs	r3, #0
	str	r3, [r7, #12]
	b	.L4
.L5:
	ldr	r3, [r7, #16]
	adds	r2, r3, #1
	str	r2, [r7, #16]
	movs	r2, #0
	strb	r2, [r3]
	ldr	r3, [r7, #12]
	adds	r3, r3, #1
	str	r3, [r7, #12]
.L4:
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L5
	bl	main
	nop
	adds	r7, r7, #32
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L7:
	.align	2
.L6:
	.word	_edata
	.word	_sdata
	.word	_etext
	.word	_ebss
	.word	_sbss
	.size	Reset_handler, .-Reset_handler
	.align	1
	.global	Default_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	Default_handler, %function
Default_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
.L9:
	b	.L9
	.size	Default_handler, .-Default_handler
	.weak	HASH_and_CRS_handler
	.thumb_set HASH_and_CRS_handler,Default_handler
	.weak	FPU_handler
	.thumb_set FPU_handler,Default_handler
	.weak	RNG_and_HASH_handler
	.thumb_set RNG_and_HASH_handler,Default_handler
	.weak	AES_handler
	.thumb_set AES_handler,Default_handler
	.weak	LCD_handler
	.thumb_set LCD_handler,Default_handler
	.weak	TSC_handler
	.thumb_set TSC_handler,Default_handler
	.weak	SWPMI1_handler
	.thumb_set SWPMI1_handler,Default_handler
	.weak	SAI2_handler
	.thumb_set SAI2_handler,Default_handler
	.weak	SAI1_handler
	.thumb_set SAI1_handler,Default_handler
	.weak	I2C3_ER_handler
	.thumb_set I2C3_ER_handler,Default_handler
	.weak	I2C3_EV_handler
	.thumb_set I2C3_EV_handler,Default_handler
	.weak	QUADSPI_handler
	.thumb_set QUADSPI_handler,Default_handler
	.weak	LPUART1_handler
	.thumb_set LPUART1_handler,Default_handler
	.weak	DMA2_CH7_handler
	.thumb_set DMA2_CH7_handler,Default_handler
	.weak	DMA2_CH6_handler
	.thumb_set DMA2_CH6_handler,Default_handler
	.weak	OTG_FS_handler
	.thumb_set OTG_FS_handler,Default_handler
	.weak	LPTIM2_handler
	.thumb_set LPTIM2_handler,Default_handler
	.weak	LPTIM1_handler
	.thumb_set LPTIM1_handler,Default_handler
	.weak	COMP_handler
	.thumb_set COMP_handler,Default_handler
	.weak	DFSDM1_FLT2_handler
	.thumb_set DFSDM1_FLT2_handler,Default_handler
	.weak	DFSDM1_FLT1_handler
	.thumb_set DFSDM1_FLT1_handler,Default_handler
	.weak	DFSDM1_FLT0_handler
	.thumb_set DFSDM1_FLT0_handler,Default_handler
	.weak	DMA2_CH5_handler
	.thumb_set DMA2_CH5_handler,Default_handler
	.weak	DMA2_CH4_handler
	.thumb_set DMA2_CH4_handler,Default_handler
	.weak	DMA2_CH3_handler
	.thumb_set DMA2_CH3_handler,Default_handler
	.weak	DMA2_CH2_handler
	.thumb_set DMA2_CH2_handler,Default_handler
	.weak	DMA2_CH1_handler
	.thumb_set DMA2_CH1_handler,Default_handler
	.weak	TIM7_handler
	.thumb_set TIM7_handler,Default_handler
	.weak	TIM6_DACUNDER_handler
	.thumb_set TIM6_DACUNDER_handler,Default_handler
	.weak	UART5_handler
	.thumb_set UART5_handler,Default_handler
	.weak	UART4_handler
	.thumb_set UART4_handler,Default_handler
	.weak	SPI3_handler
	.thumb_set SPI3_handler,Default_handler
	.weak	TIM5_handler
	.thumb_set TIM5_handler,Default_handler
	.weak	SDMMC1_handler
	.thumb_set SDMMC1_handler,Default_handler
	.weak	FMC_handler
	.thumb_set FMC_handler,Default_handler
	.weak	ADC3_handler
	.thumb_set ADC3_handler,Default_handler
	.weak	TIM8_CC_handler
	.thumb_set TIM8_CC_handler,Default_handler
	.weak	TIM8_TRG_COM_handler
	.thumb_set TIM8_TRG_COM_handler,Default_handler
	.weak	TIM8_UP_handler
	.thumb_set TIM8_UP_handler,Default_handler
	.weak	TIM8_BRK_handler
	.thumb_set TIM8_BRK_handler,Default_handler
	.weak	DFSDM1_FLT3_handler
	.thumb_set DFSDM1_FLT3_handler,Default_handler
	.weak	RTC_ALARM_handler
	.thumb_set RTC_ALARM_handler,Default_handler
	.weak	EXTI15_10_handler
	.thumb_set EXTI15_10_handler,Default_handler
	.weak	USART3_handler
	.thumb_set USART3_handler,Default_handler
	.weak	USART2_handler
	.thumb_set USART2_handler,Default_handler
	.weak	USART1_handler
	.thumb_set USART1_handler,Default_handler
	.weak	SPI2_handler
	.thumb_set SPI2_handler,Default_handler
	.weak	SPI1_handler
	.thumb_set SPI1_handler,Default_handler
	.weak	I2C2_ER_handler
	.thumb_set I2C2_ER_handler,Default_handler
	.weak	I2C2_EV_handler
	.thumb_set I2C2_EV_handler,Default_handler
	.weak	I2C1_ER_handler
	.thumb_set I2C1_ER_handler,Default_handler
	.weak	I2C1_EV_handler
	.thumb_set I2C1_EV_handler,Default_handler
	.weak	TIM4_handler
	.thumb_set TIM4_handler,Default_handler
	.weak	TIM3_handler
	.thumb_set TIM3_handler,Default_handler
	.weak	TIM2_handler
	.thumb_set TIM2_handler,Default_handler
	.weak	TIM1_CC_handler
	.thumb_set TIM1_CC_handler,Default_handler
	.weak	TIM1_TRG_COM_handler
	.thumb_set TIM1_TRG_COM_handler,Default_handler
	.weak	TIM1_UP_handler
	.thumb_set TIM1_UP_handler,Default_handler
	.weak	TIM1_BRK_handler
	.thumb_set TIM1_BRK_handler,Default_handler
	.weak	EXTI9_5_handler
	.thumb_set EXTI9_5_handler,Default_handler
	.weak	CAN1_SCE_handler
	.thumb_set CAN1_SCE_handler,Default_handler
	.weak	CAN1_RX1_handler
	.thumb_set CAN1_RX1_handler,Default_handler
	.weak	CAN1_RX0_handler
	.thumb_set CAN1_RX0_handler,Default_handler
	.weak	CAN1_TX_handler
	.thumb_set CAN1_TX_handler,Default_handler
	.weak	ADC1_2_handler
	.thumb_set ADC1_2_handler,Default_handler
	.weak	DMA1_CH7_handler
	.thumb_set DMA1_CH7_handler,Default_handler
	.weak	DMA1_CH6_handler
	.thumb_set DMA1_CH6_handler,Default_handler
	.weak	DMA1_CH5_handler
	.thumb_set DMA1_CH5_handler,Default_handler
	.weak	DMA1_CH4_handler
	.thumb_set DMA1_CH4_handler,Default_handler
	.weak	DMA1_CH3_handler
	.thumb_set DMA1_CH3_handler,Default_handler
	.weak	DMA1_CH2_handler
	.thumb_set DMA1_CH2_handler,Default_handler
	.weak	DMA1_CH1_handler
	.thumb_set DMA1_CH1_handler,Default_handler
	.weak	EXTI4_handler
	.thumb_set EXTI4_handler,Default_handler
	.weak	EXTI3_handler
	.thumb_set EXTI3_handler,Default_handler
	.weak	EXTI2_handler
	.thumb_set EXTI2_handler,Default_handler
	.weak	EXTI1_handler
	.thumb_set EXTI1_handler,Default_handler
	.weak	EXTI0_handler
	.thumb_set EXTI0_handler,Default_handler
	.weak	RCC_handler
	.thumb_set RCC_handler,Default_handler
	.weak	FLASH_handler
	.thumb_set FLASH_handler,Default_handler
	.weak	RTC_WKUP_handler
	.thumb_set RTC_WKUP_handler,Default_handler
	.weak	RTC_TAMP_STAMP_handler
	.thumb_set RTC_TAMP_STAMP_handler,Default_handler
	.weak	PVD_PVM_handler
	.thumb_set PVD_PVM_handler,Default_handler
	.weak	WWDG_handler
	.thumb_set WWDG_handler,Default_handler
	.weak	SysTick_handler
	.thumb_set SysTick_handler,Default_handler
	.weak	PendSV_handler
	.thumb_set PendSV_handler,Default_handler
	.weak	Debug_handler
	.thumb_set Debug_handler,Default_handler
	.weak	SVCall_handler
	.thumb_set SVCall_handler,Default_handler
	.weak	UsageFault_handler
	.thumb_set UsageFault_handler,Default_handler
	.weak	BusFault_handler
	.thumb_set BusFault_handler,Default_handler
	.weak	MemManage_handler
	.thumb_set MemManage_handler,Default_handler
	.weak	HardFault_handler
	.thumb_set HardFault_handler,Default_handler
	.weak	NMI_handler
	.thumb_set NMI_handler,Default_handler
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
