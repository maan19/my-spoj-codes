#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

char rock[204];
int memo[210][210];
int max_seg(int s,int e);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				memo[i][j]=-1;

		scanf("%s",rock);
		printf("%d\n",max_seg(0,strlen(rock)-1));

	}
}


int max_seg(int s,int e)
{
	if(s>e)
		return 0;

	if(memo[s][e]!=-1)
		return memo[s][e];

	int mx1=0,mx2=0,c=0;

	for(int i=s;i<=e;i++)
	{
		mx1=0,c=0;

		for(int j=i;j<=e;j++)
		{
			c = (rock[j]=='1')?(c+1):(c-1);
			if(c>0)
				mx1= max(max_seg(s,i-1) + max_seg(j+1,e) + j-i+1 ,mx1);
		}

		mx2 = max(mx1,mx2);
		//cout<<"max for " << i << " is " << mx1<< endl;
		//cout<< " max till now is " << mx2<<endl;
	}

	return (memo[s][e] =mx2);
}




