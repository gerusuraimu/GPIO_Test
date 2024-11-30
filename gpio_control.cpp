#include "gpio_control.h"

volatile unsigned *gpio;

void setupGPIO() {
    int memoryField = open("/dev/mem", O_RDWR | O_SYNC);

    if (memoryField < 0) {
        std::cerr << DEV_MEM_OPEN_ERROR << std::endl;
	exit(EXIT_FAILURE);
    }

    void *gpioMap = mmap(nullptr,
		         BLOCK_SIZE,
			 PROT_READ | PROT_WRITE,
			 MAP_SHARED,
			 memoryField,
			 GPIO_BASE);

    close(memoryField);

    if (gpioMap == MAP_FAILED) {
        std::cerr << MAP_ERROR << std::endl;
	exit(EXIT_FAILURE);
    }

    gpio = (volatile unsigned *)gpioMap;
}

void setPinOutput(int pin) {
    INP_GPIO(pin);
    OUT_GPIO(pin);
}

void setPinHigh(int pin) {
    GPIO_SET = (1 << pin);
}

void setPinLow(int pin) {
    GPIO_CLR = (1 << pin);
}