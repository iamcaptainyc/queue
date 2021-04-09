#include<stdio.h>
//此题将id转化为数组的下标，减少大量数据存取，应该学习 
int main()
{
    //初始化Person数组，从0到99999
    int Person[100000]={0};
    int N,n,m;
    int K;
    int i,j;
    int sum=0;
 
    //输入组数
    scanf("%d",&N);
    //输入并处理各个朋友圈
    for(i=1;i<=N;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&m);
            //避免有些只有一个人的朋友圈重复添加产生的影响
            if(n!=1)
            Person[m]+=n;
        }
    }
 
    //输入需要排查的数据
    scanf("%d",&K);
    for(i=1;i<=K;i++)
    {
        scanf("%d",&m);
        //判断是否为没有开朋友圈或自恋狂
        if(Person[m]==0)
        {
            if(sum!=0)
                printf(" ");
            printf("%05d",m);
 
            //避免多次被检测
            Person[m]=-1;
            sum++;
        }
    }
 
    //没有开朋友圈的情况
    if(sum==0)
        printf("No one is handsome");
    printf("\n");
 
    return 0;
}
