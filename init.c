#include "init.h"
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

void init_gpio() {
	// clock to GPIOC
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	// use from PC0 ~ PC13 for pins on our matrix
	GPIOC->MODER &= ~0b1111111111111111111111111111;	// clear
	GPIOC->MODER |= 0b0101010101010101010101010101;		// output mode

	//clock to GPIOA
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER &= ~0x30000;
	GPIOA->PUPDR &= ~0x30000;
	GPIOA->PUPDR |= 0x20000;
}

void nano_wait(unsigned int n) {
    asm(    "        mov r0,%0\n"
            "repeat: \n"
            "sub r0,#83\n"
            "        bgt repeat\n"
    : : "r"(n) : "r0", "cc");
}

void init_syscfg() {
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[2] = SYSCFG_EXTICR3_EXTI8_PA;

	EXTI->RTSR |= EXTI_RTSR_TR8;
	EXTI->IMR |= EXTI_IMR_MR8;

}
