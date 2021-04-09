#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define U 1
#define D 2
#define L 3
#define R 4

typedef struct SNAKE{
	int x;
	int y;
	struct SNAKE *next;
}snake;

int score=0,add=10;
int state,sleeptime=200,gameover=0;
snake *head,*food;
snake *q;
char o=22;
char c='*';
char b=7;
void endgame();

void pos(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void ti(int x,int y)
{
	char h='*';
	pos(x,y);
	putchar(o);
}

void title()
{
	int i;
	//“贪” 
	ti(2,5);
	ti(4,4);
	ti(6,3);
	ti(8,2);
	ti(10,3);
	ti(12,4);
	ti(14,5);
	ti(8,4);
	ti(6,5);
	ti(8,5);
	ti(10,5);
	ti(8,6);
	ti(6,7);
	ti(4,8);
	ti(6,8);
	ti(8,8);
	ti(10,8);
	ti(12,8);
	ti(4,9);
	ti(4,10);
	ti(4,11);
	ti(4,13);
	ti(6,12);
	ti(8,9);
	ti(8,10);
	ti(8,11);
	ti(10,12);
	ti(12,9);
	ti(12,10);
	ti(12,11);
	ti(12,13);
	//“吃”
	ti(20,7);
	ti(20,8);
	ti(20,9);
	ti(20,10);
	ti(22,7);
	ti(22,10);
	ti(24,7);
	ti(24,8);
	ti(24,9);
	ti(24,10);
	ti(26,11);
	ti(26,12);
	ti(26,6);
	ti(28,5);
	ti(28,10);
	ti(28,12);
	ti(30,2);
	ti(30,3);
	ti(30,4);
	ti(30,6);
	ti(30,9);
	ti(30,12);
	ti(32,4);
	ti(32,6);
	ti(32,8);
	ti(32,12);
	ti(34,4);
	ti(34,6);
	ti(34,7);
	ti(34,12);
	ti(36,10);
	ti(36,11);
	ti(36,12);
	//snake
	ti(42,6);
	ti(42,7);
	ti(42,8);
	ti(42,9);
	ti(42,12);
	for(i=3;i<13;i++)
		ti(44,i);
	ti(46,6);
	ti(46,7);
	ti(46,8);
	ti(46,9);
	ti(46,12);
	ti(48,4);
	ti(48,5);
	for(i=3;i<13;i++)
		ti(50,i);
	ti(52,3);
	ti(52,4);
	ti(52,10);
	ti(52,12);
	ti(54,3);
	ti(54,4);
	ti(54,9);
	ti(54,12);
	ti(56,4);
	ti(56,8);
	ti(56,12);
	ti(58,4);
	ti(58,5);
	ti(58,11);
	ti(58,12);
	pos(20,15);
	puts("PRESS EHTER START");  
	pos(46,16);
	puts("BY--MR.YUCHANG");
}

void TheBackground()
{
	int i;
	for(i=0;i<60;i+=2)
	{
		pos(i,0);
		putchar(o);
		pos(i,30);
		putchar(o);
	}	
	for(i=1;i<30;i++)
	{
		pos(0,i);
		putchar(o);
		pos(58,i);
		putchar(o);
	}
	if((food=(snake *)malloc(sizeof(snake)))==NULL)
	{
		fprintf(stderr,"error in malloc!");
		exit(1);
	}
	srand((unsigned)time(NULL));
	food->x=50;
	food->y=20;
	pos(food->x,food->y);
	printf("%c",c);
	pos(0,0);
}

void inisnake()
{
	snake *tail;
	int i;
	if((tail=(snake *)malloc(sizeof(snake)))==NULL)
	{
		fprintf(stderr,"error in malloc!");
		exit(1);
	}
	tail->x=24;
	tail->y=20;
	tail->next=NULL;
	for(i=1;i<4;i++)
	{
		if((head=(snake *)malloc(sizeof(snake)))==NULL)
		{
			fprintf(stderr,"error in malloc!");
			exit(1);
		}
		head->next=tail;
		head->x=24+2*i;
		head->y=20;
		tail=head;
	 } 
	 while(tail!=NULL)
	 {
	 	pos(tail->x,tail->y);
	 	putchar(o);
	 	tail=tail->next;
	 }
	 pos(0,0);
}

void Biteself()
{
	snake *self=NULL;
	self=head->next;
	while(self!=NULL)
	{
		if(self->x==head->x&&self->y==head->y)
		{
			gameover=1;
			endgame();
		}
		self=self->next;
	}
 } 
 
void TheWall()
{
	q=head;
	if(head->x==0||head->x==58||head->y==0||head->y==30)
	{
		gameover=2;
		endgame();
	}
 } 
 
 void pause()
 {
 	while(1)
 	{
 		Sleep(300);
 		if(GetAsyncKeyState(VK_SPACE))
 			break;
	 }
 }
 
void TheKey(snake **nexttail)
{
	TheWall();
    if(food->x==(*nexttail)->x&&food->y==(*nexttail)->y)//判断食物是否被吃 
	{
		while((*nexttail)->next!=NULL)
		{
			if((*nexttail)==head)
			{
				pos((*nexttail)->x,(*nexttail)->y);
				printf("*");
				pos(0,0);
			}
			else
			{
				pos((*nexttail)->x,(*nexttail)->y);
				printf("%c",o);
			}
			(*nexttail)=(*nexttail)->next;
		}
		pos(0,0);
		score+=add;
		srand((unsigned)time(NULL));
		while(1)
		{
			int flag=1;
			while((food->x=rand()%54+2)%2!=0);
			food->y=rand()%28+1;
			q=head;
			while(q->next!=NULL)
			{
				if(food->x==q->x&&food->y==head->y)
				{
					flag=0;
					break;
				}
				q=q->next;
			} 
			if(flag)
			{
				pos(food->x,food->y);
				printf("%c",o);
				pos(0,0);
				break;
			}
		}
	}
	else
	{
		while((*nexttail)->next->next!=NULL)
		{
			if((*nexttail)==head)
			{
				pos((*nexttail)->x,(*nexttail)->y);
				putchar('*');
				pos(0,0);
			}
			else
			{
				pos((*nexttail)->x,(*nexttail)->y);
				printf("%c",o);
			}
			(*nexttail)=(*nexttail)->next;
		}
		pos((*nexttail)->next->x,(*nexttail)->next->y);
		printf("  ");
		pos(0,0);
		free((*nexttail)->next);
		(*nexttail)->next=NULL;
	}
	Biteself();
}
 
void snakemove()
{
	snake *nexttail;
	if((nexttail=(snake *)malloc(sizeof(snake)))==NULL)
	{
		fprintf(stderr,"error in malloc!");
		exit(1);
	}
	if(state==U)
	{
		nexttail->next=head;
		nexttail->x=head->x;
		nexttail->y=head->y-1;
		head=nexttail;
		TheKey(&nexttail);
	}
	if(state==D)
	{
		nexttail->next=head;
		nexttail->x=head->x;
		nexttail->y=head->y+1;
		head=nexttail;
		TheKey(&nexttail);
	}
	if(state==L)
	{
		nexttail->next=head;
		nexttail->y=head->y;
		nexttail->x=head->x-2;
		head=nexttail;
		TheKey(&nexttail);
	}
	if(state==R)
	{
		nexttail->next=head;
		nexttail->y=head->y;
		nexttail->x=head->x+2;
		head=nexttail;
		TheKey(&nexttail);
	}
 } 
 
void RunGame()
{
	pos(64,4);
	puts("欢迎来到MR.YUCHANG为您打造的贪吃蛇游戏");
	pos(64,5);
	puts("现在是初代版本，敬请期待下一个版本！");
	pos(64,6); 
	puts("游戏正在进行中");
	pos(64,7);
	puts("上，下，左，右操纵方向！");
	pos(64,8);
	puts("撞到墙你会死的!不要吃自己！");
	state=U;
	while(1)
	{
		pos(64,9);
		puts("得分板");
		pos(64,10);
		printf("score = %d add = %d",score,add);
 		if(GetAsyncKeyState(VK_UP)&&state!=D)
 			state=U;
		if(GetAsyncKeyState(VK_DOWN)&&state!=U)
			state=D;
		if(GetAsyncKeyState(VK_LEFT)&&state!=R)
			state=L;
		if(GetAsyncKeyState(VK_RIGHT)&&state!=L)
			state=R;
		if(GetAsyncKeyState(VK_SPACE))
			pause();
		if(GetAsyncKeyState(VK_F1))
		{
			if(sleeptime>50)
			{
				sleeptime-=30;
				add+=10;
			}
			if(sleeptime==320)
			{
				add=2;
			}
		}
		if(GetAsyncKeyState(VK_F2))
		{
			if(sleeptime<350)
			{
				sleeptime-=30;
				add-=10; 
			 } 
			if(sleeptime==350)
			{
				add=1;
			}
	 	}
	 	Sleep(sleeptime);
	 	snakemove(); 
	} 
 } 
 
void endgame()
{
	char ch;
	system("cls");
	if(gameover==1)
	{
		pos(20,6);
		puts("你咬到了自己！GAMEOVER");
	}
	if(gameover==2)
	{
		pos(20,6);
		puts("你撞到了墙！GAMEOVER");
	}
	pos(20,8);
	printf("总分为“ %d ”",score);
	while(getchar()!='y')
	{
		printf("clean?");
	}
	return;
}

int main()
{
	int k,gameover=0;
	//SetConsoleOutputCP(437);
	title();
	system("pause");
	system("cls");
	pos(28,8);
	puts("欢迎您！游戏即将开始！");
	puts("使用方向键来操控！\n不能撞到墙！\n或吃掉自己！");
	system("pause");
	system("cls");
	pos(28,10);
	puts("游戏将在5秒后开始");
	for(k=0;k<5;k++)
	{
		Sleep(1000);
		printf("%d ",k);
	 }
st:	system("cls");
	TheBackground();
	inisnake();
	RunGame();
	endgame();
	fflush(stdin);
	printf("是否重新开始？（N/Y) ");
	if(getchar()=='n')
		exit(0);
	else
	{
		goto st;
	 } 
	printf("again");
	
	system("pause");
	return 0;
}
