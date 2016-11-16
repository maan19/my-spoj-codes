#include<stdio.h>
#include<iostream>

#include<algorithm>

using namespace std;

char rock[210];
int dp[210];
int f(int n);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		scanf("%s",rock+1);

		printf("%d\n",f(n));

	}
}

int f(int n)
{
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0,c=0,add=0;
		mx = dp[i-1];

		for(int j=i;j>=1;j--)
		{
			c  = rock[j]=='1'?c+1:c-1;
			if(c>0)
			{
				add = i-j+1 + dp[j-1];
				mx = max(mx,add);
			}
		}

		dp[i]=mx;
	}

	return dp[n];
}

