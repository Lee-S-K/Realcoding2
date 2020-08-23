#include "led.h"

void led_green_task(void* args) {
	pinMode(GREEN, OUTPUT);

	for (int i = 0; i < (int)args; i++) {
		digitalWrite(GREEN, HIGH);
		printf("GREEN TURN ON\n");
		sleep(2);
		digitalWrite(GREEN, LOW);
		printf("GREEN TURN OFF\n");
		sleep(2);
	}
}