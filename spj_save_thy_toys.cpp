#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int toy[1000000];
long long int memo[1000000];
long long int f(int s);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(memo,-1,sizeof(memo));
		for(int i=1;i<=n;i++)
			scanf("%d",&toy[i]);
		printf("%lld\n",f(1));
	}
}
long long int f(int s)
{
	if(s==n+1)
		return 0;
	if(memo[s]!=-1)
		return memo[s];
	long long int x=0,y=0,z=0;
	if(s<=n)
		x = toy[s] + f(s+2);
	if(s<=n-1)
		y = toy[s]+toy[s+1]+f(s+4);
	if(s<=n-2)
		z=toy[s]+toy[s+1] + toy[s+2] + f(s+6);
	return(memo[s]= max(max(x,y),z));
}

	