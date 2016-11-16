#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int data[1008];
int dp[1008][1008];
int dp_max(int s,int e);

int main()
{
	int n,t=1;
	scanf("%d",&n);




	while(n!=0)
	{
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
			sum = sum + data[i];
		}

		int k=dp_max(0,n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t++,k-(sum-k));
		scanf("%d",&n);

	}
}

int dp_max(int s,int e)
{
	for(int i=e;i>=0;i--)
	{
		for(int j=e;j>=0;j--)
		{
			if(i>=j)
			{
				dp[i][j]=0;
				continue;
			}

			int x = data[i+1]>=data[j]?dp[i+2][j]:dp[i+1][j-1];
			int y = data[i]>=data[j-1]?dp[i+1][j-1]:dp[i][j-2];

			dp[i][j] = max(data[i]+x,data[j]+y);
		}
	}

	return dp[s][e];
}


	

