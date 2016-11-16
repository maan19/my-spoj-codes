#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int rows;
int data [1000005][3];
int dp[1000005][3];
int dp_min();

int main()
{
	scanf("%d",&rows);
	int k=1;

	while(rows!=0)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<3;j++)
				scanf("%d",&data[i][j]);
		}

		printf("%d. %d\n",k++,dp_min());
		scanf("%d",&rows);

	}
}

int dp_min()
{
	dp[rows-1][1]=data[rows-1][1];
	dp[rows-1][2]=INT_MAX;
	dp[rows-1][0] = data[rows-1][0] + data[rows-1][1];

	for(int i=rows-2;i>=0;i--)
	{
		for(int j=2;j>=0;j--)
		{
			if(j==0)
			{
				dp[i][j] = data[i][j] + min(min(dp[i+1][0],dp[i+1][1]),dp[i][1]);
			}

			else if(j==1)
			{
				dp[i][j] = data[i][j] + min(min(dp[i+1][0],dp[i+1][1]),min(dp[i+1][2],dp[i][2]));
			}

			else
				dp[i][j] = data[i][j] + min(dp[i+1][2],dp[i+1][1]);
		}
	}

	return   dp[0][1];
}
