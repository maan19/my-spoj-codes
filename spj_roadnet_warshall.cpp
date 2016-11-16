#include<stdio.h>
#include<iostream>
using namespace std;
int d[210][210];
int nbh[210][210];

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
				for(int j=1;j<=n;j++)
				{
					scanf("%d",&d[i][j]);
					nbh[i][j]=0;
				}
		}

		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
						d[i][j] = d[j][i] = d[i][k] + d[k][j]< d[i][j] ? d[i][k] + d[k][j] : d[i][j];


		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k;
				for( k=1;k<=n;k++)
				{
					if(k==i||k==j)
						continue;
					if(d[i][j]==d[i][k]+d[k][j])
						break;
				}
				nbh[i][j] = k==n+1?1:0;
			}
		}

		for(int i=1;i<=n;i++)
		{
				for(int j=1;j<=n;j++)
				{
				if(nbh[i][j])
					printf("%d %d\n",i,j);
			    }
		}

		printf("\n");
	}
}












																																													

		