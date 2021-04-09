#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 10

 
int mycomp(const void *p1,const void *p2)
 {
 	const double *a1=(const double *)p1;
 	const double *a2=(const double *)p2;
 	if(*a1<*a2) return -1;
 	if(*a1==*a2) return 0;
 	else return 1;
 }
 
int main()
{
	FILE *fp;
	double data[MAX];
	int i,j;
	puts("please input 10 data to sort them");
	for(i=0;i<MAX;i++)
	{
		scanf("%lf",&data[i]);
	}
	qsort(data,MAX,sizeof(double),mycomp);
	if((fp=fopen("data_01.txt","a+"))==NULL)
		fprintf(stderr,"error in opening !");
	for(i=0;i<MAX;i++)
		fprintf(fp,"%d:%8.2lf\n",i+1,data[i]);
	fseek(fp,0L,SEEK_SET);
	fclose(fp);
	return 0;
 } 

