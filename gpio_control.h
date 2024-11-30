#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

#define GPIO_BASE 0xFE200000
#define BLOCK_SIZE 0xA0
#define INP_GPIO(g) *(gpio + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))
#define OUT_GPIO(g) *(gpio + ((g) / 10)) |= (1 << (((g) % 10) * 3))
#define GPIO_SET *(gpio + 7)
#define GPIO_CLR *(gpio + 10)

#define DEV_MEM_OPEN_ERROR "Failed to open '/dev/mem'. Are you running as root?"
#define MAP_ERROR "mmap error."

void setupGPIO();
void setPinOutput(int pin);
void setPinHigh(int pin);
void setPinLow(int pin);

#endif