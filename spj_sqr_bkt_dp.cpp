#include<stdio.h>
#include<unordered_set>
using namespace std;
int dp[40][40];
int fun(int n);
unordered_set<int> m;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,k;
		scanf("%d""%d",&n,&k);

		for(int i=0;i<k;i++)
		{
			int d;
			scanf("%d",&d);
			m.insert(d);
		}

		printf("%d\n",fun(2*n));
		m.clear();

		
	}
}


int fun(int n)
{
	for(int i=0;i<=n;i++)
		dp[0][i]=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j)
			{
				dp[i][j]=1;
				continue;
			}
			if((i%2==0 && j%2!=0) || (i%2!=0 && j%2==0))
			{
				dp[i][j]=0;
				continue;
			}


			if(m.find(i)!=m.end())
			{
				if(j==0)
					dp[i][j]=0;
				else
					dp[i][j]= dp[i-1][j-1];
			}

			else
			{
				if(j==0)
					dp[i][j] =dp[i-1][1];
				else
					dp[i][j] =dp[i-1][j+1] + dp[i-1][j-1];
			}
		}
	}

	return dp[n][0];
}




	


