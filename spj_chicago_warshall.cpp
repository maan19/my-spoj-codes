#include<stdio.h>
#include<iostream>
using namespace std;

double d[110][110];


int main()
{
	int n,m;
	scanf("%d",&n);

	while(n)
	{
		scanf("%d",&m);

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=-1.0;

		for(int i=1;i<=m;i++)
		{
			int u,v;double w;
			scanf("%d""%d""%lf",&u,&v,&w);

			d[u][v] = w/(100.0);
			d[v][u] = w/(100.0);
		}

		for(int k=1;k<=n;k++)
		{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(d[i][k] >-1.0 && d[k][j]>-1.0)
							d[i][j]= d[j][i] = d[i][j] < d[i][k]*d[k][j]?d[i][k]*d[k][j]:d[i][j];
					}
				}
		}

		printf("%.6lf percent\n",d[1][n]*(100.0));
		scanf("%d",&n);
	}
}





	