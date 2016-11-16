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

int f(int n,int s);
int memo[10004][10004];

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
		d[n+1].s=10000000;

		sort(d+1,d+n+1,mycmp);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n+1;j++)
				memo[i][j]=-1;

		//printf("hello\n");

		/*for(int i=1;i<=n;i++)
			printf("%d %d %d\n",d[i].s,d[i].e,d[i].t);*/

		printf("%d\n",f(n,n+1));

	}
}

int f(int n,int s)
{
	if(n==0)
		return 0;

	if(memo[n][s]!=-1)
		return memo[n][s];

	int a=0,b=0;

	if(d[n].e <=d[s].s)
		a = f(n-1,n) + d[n].t;
	b= f(n-1,s);

	return memo[n][s]=a>b?a:b;
}
	