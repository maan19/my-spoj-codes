#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

char a[5009];
char b[5009];
int dp[5009][5009];

using namespace std;
int f(int l,int m);

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	int m = strlen(a);
	int i,j;
	for( i=0,j=m-1;j>=0;i++,j--)
		b[i]=a[j];
	b[i]=NULL;
	//printf("a is %s b is %s\n",a,b);
	printf("%d\n",m-f(m,m));

}

int f(int l,int m)
{
	
	for(int i=0;i<=l;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
				continue;
			}
			if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[l][m];
}



