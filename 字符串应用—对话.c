#include <stdio.h>
#define MSG "You must have many talents,tell me some."
#define LTM 5
#define LINEMAX 81
int main()
{
	char talents[LINEMAX];
	char name[LINEMAX];
	int i;
	const char m1[40]="Limit yourself to one line's worth.";
	const char m2[]="if you can't think of any thing,fake it.";
	const char *m3="\nEnough about me---What's your name?"; 
	const char *mytal[LTM]={"Adding numbers swiftly","Multiply accurately","Stashing data",
	                        "Following instructions to the letter","Understand the c language"};
	printf("Hi,I'm Clyde the Computer.""I have many talents.\n");
	printf("Let me tell you something of them.\n");
	puts("What are they? Ah yes,here are the partical list.");
	for(i=0;i<LTM;i++)
	{
		puts(mytal[i]);
	}
	puts(m3);
	gets(name);
	printf("Well,%s,%s\n",name,MSG);
	printf("%s\n%s\n",m1,m2);
	gets(talents);
	puts("Let's see if I'get the message.");
	puts(talents);
	printf("Thanks for the information. %s\n",name);
	return 0;
 } 
