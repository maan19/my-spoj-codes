#include<stdio.h>
#include<iostream>

using namespace std;
int a,N,k;
 int f(int pc,int i,int l);
int  memo[101][101][2];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		for(int i=0;i<101;i++)
			for(int j=0;j<101;j++)
				for(int s=0;s<2;s++)
					memo[i][j][s]=-1;


		
		scanf("%d""%d""%d",&a,&N,&k);
		printf("%d %d\n",a,f(0,N,0));
	}
}



 int f(int pc,int i,int l)
{
	if(i==0)
		return pc==k?1:0;

	if(memo[pc][i][l]!=-1)
		return memo[pc][i][l];

	return (memo[pc][i][l] = f(pc + l*1,i-1,1) + f(pc + l*0,i-1,0));
	

}
	

