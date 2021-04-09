#include <stdio.h>
#include <stdlib.h>
#include "diroll.h"

int roll_count;
static int rallem(int sides)
{
	int roll;
	roll=rand()%sides+1;
	roll_count++;
	return roll;
 } 
 
int roll_n_dice(int dice,int sides)
{
	int i,total=0;
	if(sides<2){
		printf("need at least 2 sides");
		return -2;
	}
	if(dice<1){
		printf("need at least 1 dice");
		return -1;
	}
	for(i=1;i<=dice;i++)
	{
		total+=rallem(sides);
	}
	return total;
}
 
