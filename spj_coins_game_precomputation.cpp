#include<stdio.h>
int dp[1000001];
int k,l;
void pre_comp();

int main()
{
	dp[0]=0;
	

	int m,coins;
	scanf("%d" "%d" "%d",&k,&l,&m);
	pre_comp();

	for(int i=0;i<m;i++)
	{
		scanf("%d",&coins);

		if(dp[coins]==1)
			printf("A");
		else
			printf("B");

	}

	printf("\n");



}

void pre_comp()
{
	for(int i=1;i<=1000000;i++)
	{
		int x,y,z;
		x = dp[i-1];
		if(i>=k)
			y = dp[i-k];
		if(i>=l)
			z = dp[i-l];
		if(x==0||y==0||z==0)
			dp[i]=1;
		else
			dp[i]=0;
	}
}

