#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>
#define mx 1000008*4
using namespace std;
long long int seg[mx];
long long int query(int i,int l,int h,int ql,int qh);
void update(int i,int l,int h,int v);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long int sum=0;
		memset(seg,0,sizeof(seg));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			sum+=query(1,1,1000000,1,a-1);
			update(1,1,1000000,a);
		}
		printf("%lld\n",sum);
	}
}

long long int query(int i,int l,int h,int ql,int qh)
{
	if(h<ql || l>qh)
		return 0;
	if(l>=ql && h<=qh)
		return seg[i];
	int mid = (l+h)/2;
	return (query(2*i,l,mid,ql,qh) + query(2*i+1,mid+1,h,ql,qh));
}

void update(int i,int l,int h,int v)
{
	if(v<l||v>h)
		return;
	if(l==h)
	{
		seg[i]+=v;
		return;
	}
	int mid = (l+h)/2;
	update(2*i,l,mid,v);
	update(2*i+1,mid+1,h,v);
	seg[i]=seg[2*i]+seg[2*i+1];  
}


