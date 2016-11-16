#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int data[21][3];
int no;
int f(int n,int s);
int memo[21][4];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&no);
		for(int i=0;i<no;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&data[i][j]);
		memset(memo,-1,sizeof(memo));
		printf("%d\n",f(0,3));
	}
}

int f(int n,int s)
{
	if(n==no)
		return 0;
	if(memo[n][s]!=-1)
		return memo[n][s];
	int x,y,z;x=y=z=20000000;
	if(s!=0)
		x=data[n][0]+f(n+1,0);
	if(s!=1)
		y=data[n][1]+f(n+1,1);
	if(s!=2)
		z=data[n][2]+f(n+1,2);
	return min(z,min(x,y));
}
