#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int s,e,t;
};

bool mycmp(const node &a,const node & b)
{
	return a.e < b.e;
}

bool cmp(const node & a,int val)
{
	return a.e < val;
}

node d[10009];
int dp[10009];
int f(int n);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
		{
				scanf("%d""%d""%d",&d[i].s,&d[i].e,&d[i].t);
				d[i].e = d[i].s + d[i].e;
		}
		d[0].e=0;

		sort(d+1,d+n+1,mycmp);
	}
}

int f(int n)
{
	dp[0]=0;

	for(int i=1;i<=n;i++)
	{
		if(!lower_bound(d+1,d+i,d[i].s,cmp))
			dp[i]=dp[i-
