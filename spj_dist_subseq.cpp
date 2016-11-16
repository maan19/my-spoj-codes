#include<stdio.h>
#include<iostream>
#include<string.h>
#define MOD 1000000007

using namespace std;
int lg[128];

 int dp[100009];
 int sm[100009];
char txt[100009];

int str_len();
int f();

int main()
{
	int t;
	scanf("%d",&t);

	
	
	while(t--)
	{
		for(int i=65;i<=90;i++)
		lg[i]=0;
		scanf("%s",txt+1);
		//printf("%c\n",txt[str_len()]);
		printf("%d\n",f());
	}
}


 int f()
{
	dp[1]=1;sm[1]=1;
	lg[txt[1]]=1;
	 int sum =1;
	int i,s=str_len();
	for(i=2;i<=s;i++)
	{
		dp[i]=0;
		if(lg[txt[i]]==0)
			dp[i] = (sm[i-1] +1)%MOD;
		else
		{
			dp[i] = (sm[i-1]%MOD-sm[lg[txt[i]]-1]%MOD + MOD)%MOD;
		}

		lg[txt[i]]=i;
		sm[i] = (sm[i-1]%MOD + dp[i]%MOD)%MOD;
		//printf("for i=%d dp is %lld and sum is %lld\n",i,dp[i],sum);
	}
	return sm[s]+1;
}

int str_len()
{
	int i=1;
	for(i=1;txt[i]!=NULL;i++)
	{}

	return i-1;
}



