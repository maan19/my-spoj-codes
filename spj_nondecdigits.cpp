#include<stdio.h>
#include<iostream>
using namespace std;

long long f(int n ,int k);
long long memo[70][15];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int p,n;
		scanf("%d""%d",&p,&n);

		for(int i=0;i<=66;i++)
			for(int j=0;j<=10;j++)
				memo[i][j]=-1;

		printf("%d %lld\n",p,f(n,9));
	}
}


long long f(int n,int k)
{
	if(n==1)
		return k+1;

	if(memo[n][k]!=-1)
		return memo[n][k];

	long long sum = 0;

	for(int i=0;i<=k;i++)
		sum = sum + f(n-1,i);

	return memo[n][k]=sum;
}

