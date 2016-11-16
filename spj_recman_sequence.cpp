#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[500005];
char map[500000000];


int main()
{
	dp[0]=0;
	map[0]='1';

	for(int i=1;i<5000000;i++)
		map[i] = '0';

	for(int i=1;i<=500000;i++)
	{
		dp[i] = dp[i-1] -i;

		
		if(dp[i]>=0 && map[dp[i]]=='1' || dp[i]<0)
			dp[i] = dp[i-1] + i;
		map[dp[i]]='1';
	}

	int x;
	scanf("%d",&x);

	while(x!=-1)
	{
		printf("%d\n",dp[x]);
		scanf("%d",&x);
	}

	return 0;
}

