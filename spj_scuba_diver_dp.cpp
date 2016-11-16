#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 1000000
int cyl[1003][3];
int dp[25][83][1009];
int o,n,c;
int f(int o,int n,int c);

int main()
{
	int t;
	scanf("%d",&t);

	for(int i=0;i<10009;i++)
		dp[0][0][i]=0;

	for(int i=1;i<25;i++)
		for(int j=1;j<83;j++)
			dp[i][j][0]=INF;

	for(int i=1;i<25;i++)
		dp[i][0][0]=INF;

	for(int j=1;j<83;j++)
		dp[0][j][0]=INF;



	while(t--)
	{
		
		scanf("%d""%d""%d",&o,&n,&c);

		
	

		for(int i=1;i<=c;i++)
		{
			for(int j=0;j<3;j++)
				scanf("%d",&cyl[i][j]);
		}

		printf("%d\n",f(o,n,c));
	}
}

int f(int o,int n,int c)
{
	for(int i=1;i<=o;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=c;k++)
				dp[i][j][k] = (dp[i-cyl[k][0]<0?0:i-cyl[k][0]][j-cyl[k][1]<0?0:j-cyl[k][1]][k-1] + cyl[k][3])<dp[i][j][k-1]?dp[i-cyl[k][0]<0?0:i-cyl[k][0]][j-cyl[k][1]<0?0:j-cyl[k][1]][k-1] + cyl[k][3]:dp[i][j][k-1];
	return dp[o][n][c];

}
