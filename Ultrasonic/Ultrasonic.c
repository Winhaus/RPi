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
	
	pinMode (22, OUTPUT);
	
	pinMode (23, INPUT);
	
    i = wiringPiISR (23, INT_EDGE_BOTH, &EchoCac);
				
	digitalWrite(22, HIGH);
	delayMicroseconds(10);
	digitalWrite(22, LOW);	
    printf("Ultrasonic Wave fire out!!!\n");	
			

	while(1)
	{
	    cnt++;
	}

}

void EchoCac(void)
{
	
	if(digitalRead (23) == HIGH)
	{
	
	t_start = micros();
	
	printf("Wave start：%d us\n",t_start);
	
	}	
	
	if(digitalRead (23) == LOW)
	{
	t_end = micros();
	
	printf("Echo got：%d us\n",t_end);
	
	t = t_end - t_start;
	
	Dist = (t*100*340)/2/1000000;
	
	printf("Target distance: %d cm\n",Dist);	
	
	exit(-1);
	
	}	
	
 
}


