#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;


char in[6200];
char rev[6200];
int dp[6200][6200];

int LCS(int m,int n);


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",in);
		int i,j;
		for( i=0, j=strlen(in)-1;j>=0;i++,j--)
		{
			rev[i] = in[j];
		}
		rev[i] = NULL;

		printf("%d\n",strlen(in)-LCS(strlen(in),strlen(rev)));

	}
}

int LCS(int m,int n)
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				dp[i][j] = 0;

			else if(in[i-1] == rev[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];

			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[m][n];



}


	