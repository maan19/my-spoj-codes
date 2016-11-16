#include<stdio.h>
int memo[15][100];
int count(int n,int k);

int main()
{
	int t,n,k;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d" "%d",&n,&k);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				memo[i][j]=-1;
		printf("%d\n",count(n,k));
		
	}
}


int count(int n,int k)
{
	if(n==0)
		return 0;
	if(k==0)
		return 1;
	if(memo[n][k]!=-1)
		return memo[n][k];
	int sum =0;

	for(int i=k;i>=0 && i>=k-n+1;i--)
		sum = sum + count(n-1,i);
	return(memo[n][k]= sum);
}
		