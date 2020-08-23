#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include <pthread.h>

#define RED 1
#define GREEN 4
#define YELLOW 5

void led_green_task(void *args);
void led_yellow_task(void *args);