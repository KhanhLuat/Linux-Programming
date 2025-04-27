////////////////////////////////////////
//	blinkLED.c
//      Blinks the USR3 LED.
//	Wiring:	None
//	Setup:	
//	See:	
////////////////////////////////////////
#include <stdio.h>
#include "CheckFolderBrightness.h"
#include "CheckFolderTrigger.h"
int main() {
	FILE * trigger[3] = {fopen("/sys/class/leds/beaglebone:green:usr3/trigger", "w"), fopen("/sys/class/leds/beaglebone:green:usr2/trigger", "w"),
						fopen("/sys/class/leds/beaglebone:green:usr1/trigger", "w")};
	FILE * brightness[3] = {fopen("/sys/class/leds/beaglebone:green:usr3/brightness", "w"),fopen("/sys/class/leds/beaglebone:green:usr2/brightness", "w"),
							fopen("/sys/class/leds/beaglebone:green:usr1/brightness", "w")};
	int on = 0;
	for(int i =0; i < 3; i++){
		if(CheckFolderTrigger(trigger[i]) == 1){
			fprintf(trigger[i], "none\n");
		}else{
			;	
		}
	}
	while(1) {
		for ( int i = 0; i < 3; i++){
			if(CheckFolderBrightness(brightness[i]) == 1){
				fprintf(brightness[i], "%d\n", on);
				fflush(brightness[i]);
			}else{
				;	
			}
		}
		if(!on) 
			on = 1;
		else 
			on = 0;
			usleep(50000);
	}
}
