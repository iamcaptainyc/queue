#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int bird_x,bird_y;
int bar_x,bar_ytop,bar_ydown;
int score;

int high,width;

char wall_ver=222;
char wall_hor=220;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cuosor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cuosor_info);
} 

void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void map()
{
	int i;
	for(i=0;i<high+1;i++){
		gotoxy(width+1,i);
		printf("%c",wall_ver);
	}
	for(i=0;i<=width+1;i=i+2){
		gotoxy(i,high+1);
		printf("%c",wall_hor);
	}
	gotoxy(bird_x,bird_y);
	printf("@"); 
}

void startup()
{
	high=30;
	width=27;
	
	bird_x=width/2;
	bird_y=high/2;
	
	bar_x=width;
	bar_ydown=high/2;
	bar_ytop=bar_ydown+4;
	
	score=0;
	
	HideCursor();
}

void update()
{
	if(bird_x==bar_x-1){
		if(bird_y<bar_ytop&&bird_y>bar_ydown)
			score++;
		else{
			gotoxy(0,high+4);
			printf("the little bird is died!\n");
			exit(0);
		}
	}
	if(bar_x>0)
		bar_x--;
	else{
		bar_x=width;
		bar_ydown=rand()%(high-4);
		bar_ytop=bar_ydown+4;
	}
	if(bird_y<high+1)
		bird_y++;
	else{
		printf("the little bird is died!\n");
		exit(0);
	}
	Sleep(200);
}

void react()
{
	char input;
	
	if(kbhit())
	{
		if(getch()==' '&&bird_y>0)
		{
			bird_y=bird_y-2;
		}
		if()
	}
}
