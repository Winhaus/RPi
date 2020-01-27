#include "wiringPi.h"
#include "stdio.h"

void pwm_init();

int char2int(char *argv);

int main(int argc, char * argv[])
{

	int i;
	int Mode_inc;

	pwm_init();
    delay(1000);

	i = 100;
	Mode_inc = 1;

	if(argc == 1)
	{
		while(1)
		{
			if((i < 200) && (Mode_inc == 1))
			{
				pwmWrite(1,i);
			    delay(50);
			    i = i+1;
	        }
			else
			{
				Mode_inc = 0;
			}
		    
			if(Mode_inc == 0)
	         {
			    pwmWrite(1,i);
			    delay(50);
			    i = i-1;
			    if(i < 101)
				{
					Mode_inc = 1;
			    }
	        }

	    }
	}

	if(argc == 2)
	{
        i = char2int(argv[1]);
		printf("%d\n", i);	
		pwmWrite(1,i);
	}


	
}

void pwm_init()
{
	wiringPiSetup();

	pinMode(1,PWM_OUTPUT);	//only wiringPi pin 1 (BCM_GPIO 18) supports PWM

	pwmSetMode(PWM_MODE_MS); // Set to mode: mark:space

    pwmSetClock(192); //PWM clock: 19.2MHz, divisor 192:100KHz

	pwmSetRange(2000); //period 20ms
	
    pwmWrite(1,100);//go default position
}

int char2int(char *argv)
{
	char * a;
	char * b;
	int cnt, cnt_tmp, i;
	
	a = argv;
    b = argv;
	cnt = 0;
	i = 0;
	
	while(*a != '\0')
	{
		a++;
		cnt++;	
	}
	//printf("%d\n",cnt);
	
	for(int j = cnt; j > 0; j--)
	{
		cnt_tmp = 1;
		
	    for(int k = 0;k < (j-1); k++)
		{
			cnt_tmp = 10 * cnt_tmp;
		}
			 
		i = i + (*b - '0') * cnt_tmp;
		b++;	
	}

	
	return i;
}
