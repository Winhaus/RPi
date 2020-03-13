#include "wiringPi.h"
#include "stdio.h"
#include "stdlib.h"


int main(int argc, char * argv[])
{
	int i;
	
		int t, t_start,t_end;
	int Dist;
	
	
	//wiringPiSetupGpio ();
	
	wiringPiSetup ();
	
	pinMode (3, OUTPUT);
	
	pinMode (4, INPUT);
	
	if(argc != 2)
	{
		exit(-1);
	}
	else
	{
		
		if((* argv[1]) == '1')
		{
			
			digitalWrite(3, HIGH);
			delayMicroseconds(10);
			digitalWrite(3, LOW);	
            printf("Wave fire\n");	

	while(digitalRead (4) == LOW)
	{
      /* do nothing*/		
	}
	t_start = micros ();	
	
	printf("t_start: %d\n",t_start);	
	

	while(digitalRead (4) == HIGH)
	{
      /* do nothing*/		
	}
	t_end = micros ();
	
	printf("t_end: %d\n",t_end);
	
	t = t_end - t_start;
	
	Dist = (t*340*100)/2/1000000;
	
	printf("Distance: %d cm\n",Dist);		
			
			

		}			
	}
	
}




