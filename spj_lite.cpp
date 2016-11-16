#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
#define MAX ((2*131072)-1)

int tree[MAX];
int lazy[MAX];

int query(int id,int a,int b,int i,int j);
void update(int id,int a,int b,int i ,int j);

int main()
{
	int n,m;
	scanf("%d""%d",&n,&m);

	for(int i=1;i<=MAX;i++)
	{
		tree[i]=0;
		lazy[i]=0;
	}
	
	int k,p,q;

	for(int i=1;i<=m;i++)
	{
		scanf("%d""%d""%d",&k,&p,&q);
		
		if(k)
			printf("%d\n",query(1,1,n,p,q));
		else
		update(1,1,n,p,q);
	}
	
}


void update(int id,int a,int b,int i ,int j)
{
	if(lazy[id])
	{
		tree[id] = (b-a+1)-tree[id];
		if(a!=b)
		{
			lazy[2*id] = !lazy[2*id];
			lazy[2*id+1] = !lazy[2*id+1];
		}

		lazy[id] = 0;
	}

	if(a > b || a > j || b < i)
		return;

	if(a>=i && b<=j)
	{
		tree[id] = (b-a+1) - tree[id];
		if(a!=b)
		{
			lazy[2*id] = !lazy[2*id];
			lazy[2*id+1] = !lazy[2*id+1];
		}

		return;
	}

	int mid = (a+b)/2;

	update(2*id,a,mid,i,j);
	update(2*id+1,mid+1,b,i,j);

	tree[id] = tree[2*id] + tree[2*id+1];
}

int query(int id,int a,int b,int i,int j)
{
	if(a >b || a > j || b < i)
		return 0;

	if(lazy[id])
	{
		tree[id] = (b-a+1)-tree[id];
		if(a!=b)
		{
			lazy[2*id] = !lazy[2*id];
			lazy[2*id+1] = !lazy[2*id+1];
		}

		lazy[id] = 0;
	}

	if(a>=i && b <= j)
		return tree[id];

	int mid = (a+b)/2;

	int ret1,ret2;

	ret1 = query(2*id,a,mid,i,j);
	ret2 = query(2*id+1,mid+1,b,i,j);

	return ret1+ret2;
}













