#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int data[20];
int dp[20];
int f();
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	printf("%d\n",f());
}
int f()
{
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(data[i]>data[j])
				dp[i]=max(dp[i],dp[j]+1);
	int mx=-1;
	for(int i=1;i<=n;i++)
		mx=max(mx,dp[i]);
	return mx;

}