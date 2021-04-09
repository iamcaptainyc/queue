#include <stdio.h>
#include <string.h>
#define SIZE 100
typedef struct student
{
	char name[20];
	int score[4];
}STUDENT;
typedef enum section
{
	failure=2,pass,satisfactory,good,excellent
}SECTION;
int accept_data(STUDENT stu[],int grade[]);
int subsect(int score,int grade[]);
void show_data(STUDENT stu[],int grade[],int sum);
void search(STUDENT stu[],int sum);
int main()
{
	STUDENT stu[SIZE];
	int sum,grade[7]={0};
	sum=accept_data(stu,grade);
	show_data(stu,grade,sum);
	search(stu,sum);
	return 0;
}
int accept_data(STUDENT stu[],int grade[])
{
	int sum=0,i=0,flag=0;
	while(i<SIZE)
	{
		printf("input data(name):\n");
		scanf("%s",stu[i].name);
		if(strcmp(stu[i].name,"***")==0)
		{
			sum=i;
			break;
		}
		printf("input experience and exam data:\n");
		flag=0;
		while(flag==0)
		{
			scanf("%d%d",&stu[i].score[0],&stu[i].score[1]);
			if(stu[i].score[0]<=100&&stu[i].score[0]>=0&&stu[i].score[1]<=100&&stu[i].score[1]>=0)
			{
				flag=1;
			}
			else
			{
				printf("input error! reinput!\n");
			}
		}
		stu[i].score[2]=(int)(stu[i].score[0]*0.3+stu[i].score[1]*0.7);
		stu[i].score[3]=subsect(stu[i].score[2],grade);
		i++;
	}
	return sum;
}
int subsect(int score,int grade[])
{
	int s;
	SECTION se;
	s=score/10;
	switch(s)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:se=failure;
		       grade[2]+=1;
		       break;
		case 6:se=pass;
		       grade[3]+=1;
		       break;
		case 7:se=satisfactory;
		       grade[4]+=1;
		       break;
		case 8:se=good;
		       grade[5]+=1;
		       break;
		case 9:
		case 10:se=excellent;
		        grade[6]+=1;
		        break;
	}
	return se;
}
void show_data(STUDENT stu[],int grade[],int sum)
{
	int i=0;
	char *sec[]={"","","failure","pass","satisfactory","good","excellent"};
	for(i=0;i<sum;i++)
	{
		printf("NAME:%10s \nexperience=%4d exam=%4d sum=%4d \n",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
		printf("%15s\n",*(sec+stu[i].score[3]));
	}
	for(i=2;i<7;i++)
	{
		printf("there are %d people in %15s\n",grade[i],sec[i]);
	}
}
void search(STUDENT stu[],int sum)
{
	int i;
	char a[20];
	char *sec[]={"","","failure","pass","satisfactory","good","excellent"};
	printf("please input name to search:\n");
	scanf("%s",a);
	for(i=0;i<sum;i++)
	{
		if(strcmp(stu[i].name,a)==0)
		{
			printf("NAME:%10s \nexperience=%3d exam=%3d sum=%3d",stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
			printf("%15s\n",*(sec+stu[i].score[3]));
			break;
		}
	}
	if(i==sum)
	{
		printf("not found!\n");
	}
}
  
