// JAGDEEP MAAN

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
#define m 5000000
using namespace std;
int data[10008];
int dp[100009][55];
int bit1[100009];
int n,k,mx=INT_MIN;
int fun();
void update(int *b,int k,int v);
int query(int * b,int k);
int main()
{
	scanf("%d""%d",&n,&k);
	int p;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
		data[i]+=1;
		mx=data[i]>mx?data[i]:mx;
	}
	printf("%d\n",fun());
}

int fun()
{
	for(int j=1;j<=1;j++)
		for(int i=0;i<=n;i++)
			dp[i][j]=j;
	int sum=0;
	for(int j=2;j<=k;j++)
	{
		for(int i=j;i<=n;i++)  
		{
			update(bit1,data[i-1],dp[i-1][j-1]);
			sum=query(bit1,data[i]-1);
			dp[i][j]=sum;
		}
		memset(bit1,0,sizeof(bit1));
	}

    sum=0;
	for(int i=1;i<=n;i++)
	{sum=(sum+dp[i][k]);if(sum>=m) sum-=m;}
	return sum;
}

void update(int *b,int k,int v)
{
	int i=k;
	while(i<=mx)
	{
	b[i]+=v;
	if(b[i]>=m) b[i]-=m;
	i+=i&(-i);
	}
}
	
int query(int * b,int k)
{
	int i=k,sum=0;
	while(i>0)
	{
		sum+=b[i];
		if(sum>=m) sum-=m;
		i-=i&(-i);
	}
	return sum;
}
