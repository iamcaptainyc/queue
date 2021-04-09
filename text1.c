#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,x,y,z;
    printf("input x:\n");
    scanf("%d",&a);
    a=fabs(a);
    x=a%10;
    y=(a/10)%10;
    z=a/100;
    b=x*100+y*10+z;
    printf("y=%d\n",b);
    return 0;
}
    
