#include <stdio.h>
#define NAME 10
#define LEN 100
struct student{
	int id;
	char name[NAME];
	int score[3];
};
typedef struct student STUD;
int in_data(STUD stu[],int j);
int main()
{
	int i,n;
	FILE *fp;
	STUD stu[LEN];
	in_data(stu,n);
	if((fp=fopen("dataset.txt","a+"))==NULL)
		fprintf(stderr,"error:cannot open file!");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"ID:%d NAME:%s\nSCORE: math:%d english:%d major:%d\n",
		        stu[i].id,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	}
	if(fclose(fp)!=0)
		fprintf(stderr,"error: cannot close the file!");
	return 0; 
 } 
 int in_data(STUD stu[],int j)
 {
 	j=0;
 	printf("please input student's information \n");
 	while(1)
	 {
 		printf("input ID and NAME:\n");
 		if(scanf("%d %s",&stu[j].id,stu[j].name)==0)
 			return 0;
 		printf("\ninput score (math english major):\n");
 		scanf("%d %d %d",&stu[j].score[0],&stu[j].score[1],&stu[j].score[2]);
 		j++;
	 }
	 while(getchar()!='\n');
 }
