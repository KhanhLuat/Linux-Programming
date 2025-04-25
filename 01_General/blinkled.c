////////////////////////////////////////
//	blinkLED.c
//      Blinks the USR3 LED.
//	Wiring:	None
//	Setup:	
//	See:	
////////////////////////////////////////
#include <stdio.h>
//#include <unistd.h>

int main() {
	FILE * trigger[4] = {fopen("/sys/class/leds/beaglebone:green:usr3/trigger", "w"), fopen("/sys/class/leds/beaglebone:green:usr2/trigger", "w"),
						fopen("/sys/class/leds/beaglebone:green:usr1/trigger", "w"), fopen("/sys/class/leds/beaglebone:green:usr0/trigger", "w")};
	FILE * brightness[4] = {fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w"),fopen("/sys/class/leds/beaglebone:green:usr2/brightness", "w"),
							fopen("/sys/class/leds/beaglebone:green:usr1/brightness", "w"),fopen("/sys/class/leds/beaglebone:green:usr0/brightness", "w"),};
	int on = 0;
	for(int i =0; i < 4; i++){
		fprintf(trigger[0], "none\n");
		fprintf(trigger[1], "none\n");
		fprintf(trigger[2], "none\n");
		fprintf(trigger[3], "none\n");
	}
	while(1) {
		for ( int i = 0; i < 4; i++){
			fprintf(brightness[i], "%d\n", on);
			fflush(brightness[i]);
		}
		if(!on) 
			on = 1;
		else 
			on = 0;
			usleep(50000);
	}
}
