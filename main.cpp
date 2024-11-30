#include "gpio_control.h"

#define GPIO_PIN 17

int main() {
    setupGPIO();
    setPinOutput(GPIO_PIN);

    for (int i = 0; i < 10; i++) {
        setPinHigh(GPIO_PIN);
	usleep(500000);
	setPinLow(GPIO_PIN);
	usleep(500000);
    }

    return 0;
}