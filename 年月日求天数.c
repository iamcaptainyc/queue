#include <stdio.h>

static int daytab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
                          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int DayofYear(int year,int month,int day);

int main(void)
{
	int year,month,day,result,yearday;
	scanf("%d%d%d",&year,&month,&day);
	result=DayofYear(year,month,day);
	printf("%d",result);
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
 
