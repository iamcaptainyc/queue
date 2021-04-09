#include <stdio.h>
#include <stdlib.h>
static int daytab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int DayofYear(int year,int month,int day);
int Monthday(int year,int *pyearday);
int main(void)
{
	int year,month,day,result,yearday;
	int a;
	printf("1.输入年月日转换为天数\n");
	printf("2.输入某年天数转换为月日\n");
	printf("3.退出程序\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:printf("input the year month days:\n");
		       scanf("%d.%d.%d",&year,&month,&day);
		       result=DayofYear(year,month,day);
		       printf("it is %dth day of %d year\n",result,year);
		       break;
	    case 2:printf("input the year and the day:\n");
	           scanf("%d,%d",&year,&yearday);
		       month=Monthday(year,&yearday);
	           printf("it is %d year %d month %d day\n",year,month,yearday);
	           break;
	    case 3:exit(0);
	    default:printf("input error!");
	}
	system("pause");
	return 0;
 } 
 int DayofYear(int year,int month,int day)	
 {
 	int i,leap=0,DayofYear=0;
 	leap=(year%4==0&&year%100!=0)||(year%400==0);
 	for(i=1;i<month;i++)
 	{
 		DayofYear+=daytab[leap][i];
	 }
	 DayofYear+=day;
	 return DayofYear;
 }
 int Monthday(int year,int *pyearday)
 {
 	int leap=0,i;
 	leap=(year%4==0&&year%100!=0)||(year%400==0);
 	for(i=1;*pyearday>=daytab[leap][i];i++)
 	{
 		*pyearday-=daytab[leap][i];
	 }
	 return i;
 }
 
