#include<stdio.h>
int dp[15][100];

int main()
{
	int t,n,k;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d""%d",&n,&k);


		for(int i=1;i<=n;i++)
			dp[i][0]=1;
		for(int i=0;i<=k;i++)
			dp[0][i]=0;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				dp[i][j]=0;
				for(int m = j;m>=0 && m>= j-i+1;m--)
					dp[i][j] = dp[i][j] + dp[i-1][m];
			}
		}

		printf("%d\n",dp[n][k]);
	}




	
}

