#include "led.h"

void led_yellow_task(void* args) {
	pinMode(YELLOW, OUTPUT);

	for (int i = 0; i < (int)args; i++) {
		digitalWrite(YELLOW, HIGH);
		printf("YELLOW TURN ON\n");
		sleep(3);
		digitalWrite(YELLOW, LOW);
		printf("YELLOW TURN OFF\n");
		sleep(3);
	}
}