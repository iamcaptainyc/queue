#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int high,width;
int bird_x,bird_y;
int bar_x,bar_yd,bar_yt;

void startup()
{
	high=15;
	width=30;
	bird_y=0;
	bird_x=width/3;
	bar_x=width*2/3;
	bar_yd=rand()%9+1;
	bar_yt=10-bar_yd;
}

void show()
{
	int i,j;
	gotoxy(bird_x,bird_y);
	
	for(i=0;i<high)
	{
		for
	}
}
