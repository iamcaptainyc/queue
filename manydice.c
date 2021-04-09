#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "D:\CWORKS\MY PROJECT\diroll.h"

int main(void)
{
	int roll,sides,dice;
	
	srand((unsigned int)time(NULL));
	printf("please input the sides\n");
	while(scanf("%d",&sides)==1&&sides>0)
	{
		printf("how many dice?\n");
		scanf("%d",&dice);
		roll=roll_n_dice(dice,sides);
		printf("you have rolled a %d using %d %d-sides dice\n",roll,dice,sides);
		printf("how many side? enter 0 to stop :");
	}
	printf("the rollem founction was called %d times",roll_count);
	return 0;
}
