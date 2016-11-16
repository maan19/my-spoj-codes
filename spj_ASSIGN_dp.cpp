#include<stdio.h>
#include<iostream>
using namespace std;

int data[22][22];
long long int dp[1<<20];


int main()
{
	int c,n;
	scanf("%d",&c);

	while(c--)
	{
		
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&data[i][j]);
	
		
	dp[0]=1;int j;

	for(int i=1;i<(1<<n);i++)
	{
		dp[i]=0;j=0;

		for(int k =i;k>0;k = k>>1)
			j = ((k & 1)==1)?j+1:j;

		for(int k=0;k<n;k++)
		{
			if(data[j-1][k]==1 &&  (i>>((n-1)-k) & 1))
				dp[i] = dp[i] + dp[i& (~(1<<((n-1)-k)))];
		}

	}

	printf("%lld\n",dp[(1<<n)-1]);
		
	}
}


