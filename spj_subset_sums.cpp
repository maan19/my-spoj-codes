#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int data[109];
void subsum();
int dp[102][100000+3];
int n,sum=0,sum2=0;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		memset(dp,-1,sizeof(dp));
		sum2=sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&data[i]),sum+=data[i];
		subsum();
		for(int j=0;j<=sum;j++)
			if(dp[n][j])
				sum2+=j;
		printf("%d\n",sum2);
	}
}

void subsum()
{
	for(int i =0;i<=n;i++)
		dp[i][0]=true;
	for(int j=1;j<=sum;j++)
		dp[1][j]=(data[1]==j);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(data[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]||dp[i-1][j-data[i]];
		}
	}
}

