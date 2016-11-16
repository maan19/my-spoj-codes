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
		printf("%d\n",f(n));

	}
}

int f(int n)
{
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;

		for(int j=0;j<i;j++)
		{
			int x=0;
			if(d[i].s>=d[j].e)
				x = dp[j] + d[i].t;
			
			dp[i] = max(dp[i],max(dp[j],x));

		
		}
	}

	return dp[n];
}



