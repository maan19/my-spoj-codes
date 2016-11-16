#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct edge
{
	int s,e;
};
bool comp(edge a,edge b)
{
	if(a.s==b.s)
		return a.e<b.e;
	return a.s<b.s;
};
edge l[1000009];
int bit[1009];
int n,m,k;
void update(int i,int v);
long long int query(int i);
int main()
{
	int t,c=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d""%d""%d",&n,&m,&k);
		for(int i=0;i<k;i++)
			scanf("%d""%d",&l[i].s,&l[i].e);
		sort(l,l+k,comp);
		memset(bit,0,sizeof(bit));
		long long int sum=0;
		for(int i=0;i<k;i++)
		{
			sum +=(long long int)i-query(l[i].e);
			update(l[i].e,1);
		}
		printf("Test case %d: %lld\n",c++,sum);
	}
}
void update(int i,int v)
{
	while(i<=m)
	{
		bit[i]+=v;
		i += (i &(-i));
	}
}

long long int query(int i)
{
	long long int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}
		
		

