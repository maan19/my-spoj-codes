#include<iostream>
#include<stdio.h>
#include<algorithm>
int data[100009];
int dp[1000009];
using namespace std;
int f(int n);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	printf("%d\n",f(n));
}

int f(int n)
{
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if((data[i]-data[j])==1)
				dp[i]=max(dp[j]+1,dp[i]);
	int mx=-1;
	for(int i=1;i<=n;i++)
		mx = max(mx,dp[i]);
	return mx;
}


