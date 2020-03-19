#include "wiringPi.h"
#include "stdio.h"
#include "stdlib.h"


void moveforwards();
void movebackwards();
void stop();
void left();
void right();

int main(int argc, char * argv[])
{
	int i, cnt;
	
	wiringPiSetupGpio ();   // use BCM GPIO mapping
	
	pinMode (26, OUTPUT);
	
	pinMode (20, OUTPUT);
	
	pinMode (19, OUTPUT);
	
	pinMode (16, OUTPUT);

		
if((* argv[1]) == '0')
{
stop();
}
else if((* argv[1]) == '1')
	
	{
		moveforwards();
	}
else if((* argv[1]) == '2')
{
	movebackwards();
}
else if((* argv[1]) == '3')
{
	left();
}
else if((* argv[1]) == '4')
{
	right();
}
			



}

void moveforwards()
{
	digitalWrite(26, HIGH);
	digitalWrite(20, LOW);	
	digitalWrite(19, HIGH);
	digitalWrite(16, LOW);	
}

void movebackwards()
{

	digitalWrite(20, HIGH);
	digitalWrite(26, LOW);	
	digitalWrite(16, HIGH);
	digitalWrite(19, LOW);
	
}

void stop()
{
	digitalWrite(26, LOW);
	digitalWrite(20, LOW);	
	digitalWrite(19, LOW);
	digitalWrite(16, LOW);	
}

void left()
{
	digitalWrite(26, HIGH);
	digitalWrite(20, LOW);	
	digitalWrite(16, HIGH);
	digitalWrite(19, LOW);	
}

void right()
{
	digitalWrite(20, HIGH);
	digitalWrite(26, LOW);	
	digitalWrite(19, HIGH);
	digitalWrite(16, LOW);	
}


