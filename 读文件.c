#include <stdio.h>
#define LEN 100
#define NAME 10
struct student{
	int id;
	char name[NAME];
	int score[3];
};
typedef struct student STUD;
void show_data(STUD stu[],int i);
int main()
{
	int i=0;
	STUD stu[LEN];
	FILE *fp;
	if((fp=fopen("dataset.txt","r"))==NULL)
		fprintf(stderr,"error : cannot open the file!");
	while(fscanf(fp,"ID:%d NAME:%s\nSCORE: math:%d english:%d major:%d\n",
		        &stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2])!=EOF)
	{
		i++;
	}
	show_data(stu,i);
	return 0;
}
void show_data(STUD stu[],int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		printf("ID:%d NAME:%s\nSCORE: math:%d english:%d major:%d\n",
		        stu[j].id,stu[j].name,stu[j].score[0],stu[j].score[1],stu[j].score[2]);
	}
	printf("that's all!");
}
