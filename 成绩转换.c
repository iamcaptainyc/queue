#include<stdio.h>
int main()
{
	int score,code;
	char a;
	
	printf("please input grade:");
    scanf("%d",&score);
	code=score>=0&&score<=100?score/10:-1;
	switch(code)
	{
		case 10:
		case 9:printf("%d--A\n",score);
		       break;
	    case 8:printf("%d--B\n",score);
	               break;
	    case 7:printf("%d--C\n",score);
               break;
        case 6:printf("%d--D\n",score);
               break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:printf("%d--E\n",score);
               break;
	    default:printf("Input error!\n"); 
    }
    return 0;
}
