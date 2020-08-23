#include "led.h"

void led_red_task(void) {
	pinMode(RED, OUTPUT);

	for (int i = 0; i < 10; i++) {
		digitalWrite(RED, HIGH);
		printf("RED TURN ON\n");
		sleep(1);
		digitalWrite(RED, LOW);
		printf("RED TURN OFF\n");
		sleep(1);
	}
}

int main(int argc, char* argv[]) {
	int gno;
	int time;


	wiringPiSetup();

	if (argc < 2) {
		led_red_task();
		return 0;
	}
	gno = atoi(argv[1]);
	time = atoi(argv[2]);


	pthread_t G;
	pthread_t Y;

	if (gno == 1) {
		if ((pthread_create(&G, NULL, led_green_task, (void*)time)) < 0) {
			perror("thread create error:");
			exit(0);
		}
	}
	else if (gno == 2) {
		if ((pthread_create(&Y, NULL, led_yellow_task, (void*)time)) < 0){
			perror("thread create error:");
			exit(0);
		}
    }
	else if (gno == 3) {
		if ((pthread_create(&G, NULL, led_green_task, (void*)time)) < 0) {
			perror("thread create error:");
			exit(0);
		}
        if ((pthread_create(&Y, NULL, led_yellow_task, (void*)time)) < 0){
			perror("thread create error:");
			exit(0);
		}
    }
	led_red_task();


	
	pthread_exit(NULL);
	return 0;
}