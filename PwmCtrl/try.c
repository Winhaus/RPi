#include "stdio.h"

int char2int(char *argv);

void main()
{
	
int i;

i = char2int("150");

printf("%d\n",i);

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
	printf("%d\n",cnt);
	
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