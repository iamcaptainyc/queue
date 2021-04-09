#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int high,width;
int bird_x,bird_y;
int bar_x,bar_ydown,bar_ytop;
int score;
char w=222;
char w_x=220;



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

void startup()
{
	high=18;
	width=26;
	bird_y=high/2;
	bird_x=width/2;
	
	bar_x=width;
	
	bar_ydown=high/2;
	bar_ytop=bar_ydown+4;
	
	score=0;
	
	HideCursor();
}

void show()
{
	gotoxy(0,0);
	int i,j;
	for(i=0;i<=high+1;i++)//high加1，判断小鸟是否落地 
	{
		for(j=0;j<=width;j++)
		{
				if(i==bird_y&&j==bird_x)
					printf("@");
				else if(i==high+1){
					printf("%c",w_x);
					j++;
				}
					
				else if(j==width)
					printf("%c",w);
				else if(j==bar_x&&(i<=bar_ydown||i>=bar_ytop))
					printf("%c",w);
				else
					printf(" ");
				//Sleep(20);
		}
		putchar('\n');
	}
	printf("The score is :%d\n",score);
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
	}
}

int main()
{
	SetConsoleOutputCP(437);
	startup();
	while(1)
	{
		show();
		update();
		react();
	}
}
