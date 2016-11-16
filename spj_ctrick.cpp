#include<stdio.h>
#include<iostream>
using namespace std;
int deck[20009];
pair<int,int> seg[4*20009];
int fs,cp;
int query(int i,int l,int h,int ql,int qh);
void update(int i,int l,int h,int k);
int qry(int i,int l,int h,int v);
void build(int i,int l,int h);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,z,k;
		scanf("%d",&n);
		build(1,1,n);
		fs=n;
		cp=0;
		for(int i=1;i<=n;i++)//++++
		{
			z=query(1,1,n,1,cp-1);
			//printf("z is %d\n",z);
			k=(z+i+1)%fs;
			//printf("k is %d\n",k);
			if(k==0)
				k=fs;
			cp=qry(1,1,n,k);
			deck[cp]=i;
			//printf("deck %d is %d\n",cp,deck[cp]);
			update(1,1,n,cp);
			fs--;
		}
		for(int i=1;i<=n;i++)
			printf("%d ",deck[i]);
		printf("\n");
	}
}

void build(int i,int l,int h)
{
	if(l==h)
		{seg[i].second =1;seg[i].first=l;return;}
	int mid = (l+h)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,h);
	seg[i].second = seg[2*i].second + seg[2*i+1].second;
}


void update(int i,int l,int h,int k)
{
	if(k<l || k >h)
		return;
	if(l==h)
	{seg[i].second=0;return;}
	int mid = (l+h)/2;
	update(2*i,l,mid,k);
	update(2*i+1,mid+1,h,k);
	seg[i].second=seg[2*i].second+seg[2*i+1].second;
}

int query(int i,int l,int h,int ql,int qh)
{
	if(ql>h || qh<l)
		return 0;
	if(l>= ql && h <=qh)
		return seg[i].second;
	int mid = (l+h)/2;
	return (query(2*i+1,mid+1,h,ql,qh) + query(2*i,l,mid,ql,qh));
}
int qry(int i,int l,int h,int v)
{
	if(l==h)
		return seg[i].first;
	int mid = (l+h)/2;
	if(seg[2*i].second<v)
		return qry(2*i+1,mid+1,h,v-seg[2*i].second);
	else
		return qry(2*i,l,mid,v);
}
