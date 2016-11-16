#include<stdio.h>
#include<iostream>
using namespace std;

int dp[1008];
int sieve[100000000];
void make_sieve();

#define M 3000

int main()
{
	int t;
	scanf("%d",&t);
	make_sieve();
	dp[1]=30;
	dp[2]=42;
	
	int x=2,c,cnt;
	
	while(t--)
	{
		int n;
		scanf("%d",&n);

		

		if(n<=x)
			printf("%d\n",dp[n]);
		else
		{
			c=x;
			for(int j = dp[x] +1; c!=n;j++)
			{
				cnt=0;
				for(int i =2 ;i<=j/2&& cnt!=3;i++)
				{
					if(j%i==0 && sieve[i]==0)
						cnt++;
				}
				if(sieve[j]==0)
					cnt++;
				if(cnt>=3)
					dp[++c]=j;
			}

		printf("%d\n",dp[n]);
		x=n;
		}

		
	}
}
				




		



void make_sieve()
{
	sieve[0] = sieve[1] =1;
	for(int i=2;i<M;i++)
		sieve[i]=0;

	for(int i=2;i<M;i++)
	{
		if(sieve[i]==0)
		{
			for(int j=i*2;j<M;j=j+i)
				sieve[j]=1;
		}
		//cout<<i<<endl;
	}

	//cout<<"sieve made\n";
}
