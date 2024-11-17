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
	.file	"main.c"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #16
	add	r7, sp, #0
	movs	r3, #3
	str	r3, [r7, #12]
	movs	r3, #4
	str	r3, [r7, #8]
	ldr	r1, [r7, #8]
	ldr	r0, [r7, #12]
	bl	add
	str	r0, [r7, #4]
	movs	r3, #0
	mov	r0, r3
	adds	r7, r7, #16
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
