#include <iostream>

using namespace std;

int judge(int n,int a[])
{
	for(int i=0;i<n;i++){
		if(a[n]==a[i]) return 1;
	}
	return 0;
}

int fun(int n)
{
	double m1,m2;
	int i[10];
	for(i[0]=0;i[0]<=9;i[0]++){
		for(i[1]=0;i[1]<=9;i[1]++){
			if(judge(1,i)) continue;
			for(i[2]=0;i[2]<=9;i[2]++){
				if(judge(2,i)) continue;
				for(i[3]=0;i[3]<=9;i[3]++){
					if(judge(3,i)) continue;
					for(i[4]=0;i[4]<=9;i[4]++){
						if(judge(4,i)) continue;
						for(i[5]=0;i[5]<=9;i[5]++){
							if(judge(5,i)) continue;
							for(i[6]=0;i[6]<=9;i[6]++){
								if(judge(6,i)) continue;
								for(i[7]=0;i[7]<=9;i[7]++){
									if(judge(7,i)) continue;
									for(i[8]=0;i[8]<=9;i[8]++){
										if(judge(8,i)) continue;
										for(i[9]=0;i[9]<=9;i[9]++){
											if(judge(9,i)) continue;
											m1=i[0]*10000+i[1]*1000+i[2]*100+i[3]*10+i[4];
											m2=i[5]*10000+i[6]*1000+i[7]*100+i[8]*10+i[9];
									
											if(m1/m2==(double)n){
												cout<<i[0]<<i[1]<<i[2]<<i[3]<<i[4]<<" / "<<i[5]<<i[6]<<i[7]<<i[8]<<i[9]<<" = ";
												cout<<n<<'\n';
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	int n;
	while(cin>>n){
		fun(n);
	}
	return 0;
}
