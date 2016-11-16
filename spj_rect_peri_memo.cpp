#include<stdio.h>
#include<iostream>
using namespace std;
int d[1005][2];
int memo[1005][1005];
int f(int n,int p);
int a,b;


int main()
{

		int n;
		scanf("%d",&n);


		for(int i=1;i<=n;i++)
			scanf("%d""%d",&d[i][0],&d[i][1]);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=1002;j++)
				memo[i][j]=-1;

		f(n,d[n][0]);
		//printf("beforre %d\n",x);
		a = d[n][1]-d[n][0]>0?a-(d[n][1]-d[n][0]):a+(d[n][0]-d[n][1]);
		printf("%d\n",a>b?a:b);
		
	  
}

int f(int n,int p)
{
	if(n==0)
		return 0;

	if(memo[n][p]!=-1)
		return memo[n][p];
	
	int A,B;
	a = A = d[n][0] + f(n-1,d[n][1]) + (d[n][1]-p<0?p-d[n][1]:d[n][1]-p);
	b =B   = d[n][1] + f(n-1,d[n][0]) + (d[n][0]-p<0?p-d[n][0]:d[n][0]-p);

	return memo[n][p]=(A>B?A:B);
}
		
