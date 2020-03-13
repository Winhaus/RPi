#include "wiringPi.h"
#include "stdio.h"
#include "stdlib.h"

void EchoCac(void);


int t, t_start,t_end;
int Dist;
	

int main(int argc, char * argv[])
{
	int i, cnt;
	
	wiringPiSetupGpio ();   // use BCM GPIO mapping
	
	pinMode (26, OUTPUT);
	
	pinMode (20, OUTPUT);

		

			

	while(1)
	{
	digitalWrite(26, HIGH);
	digitalWrite(20, LOW);	
	
	delay(2000);
	
	digitalWrite(20, HIGH);
	digitalWrite(26, LOW);	
	}

}




