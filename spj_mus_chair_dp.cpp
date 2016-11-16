#include<stdio.h>
using namespace std;
int dp[1000007];
int fun(int n,int k);



int main()
{
	int n,d;
	scanf("%d""%d",&n,&d);

	while(!(n==0 && d==0))
	{
		printf("%d %d %d\n",n,d,fun(n,d));
		scanf("%d""%d",&n,&d);
	}
}


int fun(int n,int k)
{
	
	dp[1] =1;

	for(int i=2;i<=n;i++)
	{
		dp[i] = (dp[i-1] + (k-1))%i +1;
	}

	return dp[n];
}


