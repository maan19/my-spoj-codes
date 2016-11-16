#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

char rock[210];
int memo[210][210];
int f(int s,int e);


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				memo[i][j]=-1;

		scanf("%s",rock);

		printf("%d\n",f(0,n-1));

	}

}

int f(int s,int e)
{
	if(s>e)
		return 0;

	if(memo[s][e]!=-1)
		return memo[s][e];

	int mx2=0,c,k,flag=0;

	
	for(int i=s;i<=e;i++)
	{
		k=0;c=0,flag=0;
		for(int j=i;j<=e;j++)
		{
			c = rock[j]=='1'?c+1:c-1;
			if(c>0)
			{
					k=j;
					flag=1;
			}
		}
		if(flag)
			mx2 = max(f(s,i-1) + f(k+1,e) + k-i+1,mx2);  
	}

	return (memo[s][e]=mx2);
}
