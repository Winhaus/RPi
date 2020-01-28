#include "wiringPi.h"
#include "stdio.h"

void EchoCac(void);

int main(int argc, char * argv[])
{
	wiringPiSetupGpio (void);
	
	pinMode (22, OUTPUT);
	
	pinMode (23, INPUT);
	
	if(argc != 2)
	{
		exit();
	}
	else
	{
		wiringPiISR (23, INT_EDGE_RISING, EchoCac);
		if((* argv[1]) == ‘1’)
		{
			digitalWrite(22, HIGH);
			delay(1);
			digitalWrite(22, LOW);			
		}			
	}
	
}

void EchoCac(void)
{
	int t, t_start,t_end;
	int Dist;
	
	t_start = millis();
	
	printf("Target detected!!!\n")
	
	while(digitalRead (23) == HIGH)
	{
      /* do nothing*/		
	}
	t_end = millis();
	
	t = t_end - t_start;
	
	Dist = (t*340)/2/1000;
	
	printf("Distance: %d\n",Dist);	

 
}


