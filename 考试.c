#include<stdio.h>

#define N 100

#include<string.h>

void encoded(char str[])

{
	int a=0,b=0,c=0,d=0,k,i;
	char encode[N];
	for(i=0;str[i]!='\0';)
	{
		switch(str[i])
		{
			case 'A': k=i;
					for(a=0;str[k]=='A';a++)
					{
						k++;
					}
					if(a==1) printf("A");
					else printf("%dA",a); 
					break;
			case 'C': k=i;
					for(b=0;str[k]=='C';b++)
					{
						k++;
					}
					if(b==1) printf("C");
					else printf("%dC",b);
					break;
			case 'T': k=i;
					for(c=0;str[k]=='T';c++)
					{
						k++;
					}
					if(c==1) printf("T");
					else printf("%dT",c);
					break;
			case 'G': k=i;
					for(d=0;str[k]=='G';d++)
					{
						k++;
					}
					if(d==1) printf("G");
					else printf("%dG",d);
					break;
		}
		i=k;
	}

}

int main(void)

{

 char str[N];

 gets(str);

 encoded(str);

}


