#include<stdio.h>
//���⽫idת��Ϊ������±꣬���ٴ������ݴ�ȡ��Ӧ��ѧϰ 
int main()
{
    //��ʼ��Person���飬��0��99999
    int Person[100000]={0};
    int N,n,m;
    int K;
    int i,j;
    int sum=0;
 
    //��������
    scanf("%d",&N);
    //���벢�����������Ȧ
    for(i=1;i<=N;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&m);
            //������Щֻ��һ���˵�����Ȧ�ظ���Ӳ�����Ӱ��
            if(n!=1)
            Person[m]+=n;
        }
    }
 
    //������Ҫ�Ų������
    scanf("%d",&K);
    for(i=1;i<=K;i++)
    {
        scanf("%d",&m);
        //�ж��Ƿ�Ϊû�п�����Ȧ��������
        if(Person[m]==0)
        {
            if(sum!=0)
                printf(" ");
            printf("%05d",m);
 
            //�����α����
            Person[m]=-1;
            sum++;
        }
    }
 
    //û�п�����Ȧ�����
    if(sum==0)
        printf("No one is handsome");
    printf("\n");
 
    return 0;
}
