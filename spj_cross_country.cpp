#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int a[2005];
int b[2005];
int memo[2005][2005];
int lcs(int m,int n);

int main()
{
	int t;
	scanf("%d",&t);
	int end;
	int i=0,j=0;

	while(t--)
	{
	i=0,j=0;
	int mx = INT_MIN;
	while(1)
	{
		scanf("%d",&end);
		if(end==0)
			break;
		a[i++] = end;
	}

	while(1)
	{
		int end1;
		scanf("%d",&end1);
		if(end1==0)
			break;
		b[0]=end1;
		j=1;
		while(1)
		{
			scanf("%d",&end);
			if(end==0)
				break;
			b[j++]=end;
		}

		for(int g=0;g<=i;g++)
		{
			for(int h=0;h<=j;h++)
				memo[g][h]=-1;
		}

		mx = max(mx,lcs(i,j));
	}

	printf("%d\n",mx);
	}
}

int lcs(int m,int n)
{
	if(m==0||n==0)
		return 0;
	if(memo[m][n]!=-1)
		return memo[m][n];
	if(a[m-1]==b[n-1])
		return (memo[m][n]=(1 + lcs(m-1,n-1)));
	return (memo[m][n]=max(lcs(m,n-1),lcs(m-1,n)));
}
	