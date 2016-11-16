#include<stdio.h>
#include<iostream>
#define INF 1000000
using namespace std;

int cyl[1003][3];
int memo[25][83][1009];
int o,n,c;
int f(int o,int n,int c);
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d""%d""%d",&o,&n,&c);

		for(int i=0;i<=o;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=c;k++)
					memo[i][j][k]=-1;

	

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
	if(n<=0 && o<=0)
		return 0;
	if(c==0)
		return INF;
	if((memo[o][n][c]!=-1))
	{
			//printf("memo\n");
			return memo[o][n][c];
	}

	int x,y,z;
	x =f(o-cyl[c][0]<0?0:o-cyl[c][0],n-cyl[c][1]<0?0:n-cyl[c][1],c-1) + cyl[c][2];
	y =f(o,n,c-1);

	return memo[o][n][c] = (x<y?x:y);
	
}

			


		