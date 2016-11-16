#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int data[100008];
int n,k;
struct node
{
	bool word;
	node * child;
	int c;
};
struct root
{
	node * chld[100005];
};
root r;
void xr();
void insert();
void free();
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(int i=0;i<n;i++)
			scanf("%d",&data[i]);
		insert();
		xr();
		free();
	}
}

void insert()
{
	
	for(int i=0,k=0;i<n;i++)
	{
		node * t;node * b;
		t =new node;
		r.chld[k++]=t;
		t->c=data[i];
		t->word=true;
		b=t;
		for(int j=i+1;j<n;j++)
		{
			t=new node;
			t->word=true;
			t->c=data[j];
			b->child=t;
			b=t;
		}
		b->child=NULL;
	}
}

void xr()
{
	node * t;int x;
	 int cnt=0;
	for(int i=0;i<n;i++)
	{
		t=r.chld[i];
		x=t->c;
		if(x<k) cnt++;
		while(t->child!=NULL)
		{
			t = t->child;
			x^=(t->c);
			if(x<k) cnt++;
		}
	}
	printf("%d\n",cnt);
}

void free()
{
	for(int i=0;i<n;i++)
	{
		node *p;node *t;
		p = t=r.chld[i];
		while(t!=NULL)
		{
			t = p->child;
			delete p;
			p = t;
		}
	}
}

			
			
