
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;


#define sid(n) scanf("%d",&n)
#define dout(n) printf("%d",n)
#define sil(n) scanf("%lld",&n)
#define lout(n) printf("%lld",n)
#define FOR(n) for(int i=1;i<=n;i++)

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int,int> PII;


struct node
{
	int prefix;
	node * child[10];
};

void initialise(node  * p)
{
	for(int i=0;i<10;i++)
		p->child[i]=NULL;
	p->prefix=0;
}

void insert(char * s,node * p)
{
	if(*s==NULL)
	{
		p->prefix++;
		return;
	}
	p->prefix++;
	if(p->child[*s-'0']==NULL)
	{
		p->child[*s-'0']=new node;
		initialise(p->child[*s-'0']);
	}
	insert(s+1,p->child[*s-'0']);
}

int count_prefix(char * s,node *p)
{
	if(*s==NULL)
		return p->prefix;
	node * t;
	t = p->child[*s-'0'];
	if(t==NULL)
		return 0;
	return count_prefix(s+1,t);
}

char data[10004][15];

int main()
{
	int t;
	sid(t);

	while(t--)
	{
		{
		int n;
		node root;
		initialise(&root);
		sid(n);
		FOR(n)
		{
			scanf("%s",data[i]);
			insert(data[i],&root);
		}
		int i;
		for(i=1;i<=n;i++)
		{
			int cnt =count_prefix(data[i],&root);
			if(cnt>1)
				break;
		}
		if(i==n+1)
			printf("YES\n");
		else
			printf("NO\n");
		}
	}
}




