#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define N 100009

using namespace std;



vector<int> adj[N];
vector<int> base_array[N];

int pos_base_array[N];
int parent[N];
int subtree[N];
int chainhead[N];
int chainid[N];


int n,q,chainno,ptr=0;


void dfs(int cur,int prnt);
void hld(int cur,int prev);

int main()
{
	scanf("%d""%d",&n,&q);

	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d""%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1;i<=q;i++)
	{
	}
}

void dfs(int cur,int prnt)
{
	subtree[cur]=1;
	parent[cur]=prnt;

	for(int i = 0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prnt)
		{
			dfs(adj[cur][i],cur);
			subtree[cur] += subtree[adj[cur][i]];
		}
	}
}

void hld(int cur,int prev)
{
	if(chainhead[chainno]==-1)
		chainhead[chainno]=cur;

	chainid[cur] = chainno;
	base_array[chainno].push_back(cur);
	pos_base_array[cur] = ptr++;

	int id=-1,mx=-1;
	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && subtree[cur]>mx)
		{
			mx = subtree[cur];
			id = adj[cur][i];
		}
	}

	if(id==-1)
		return;

	hld(id,cur);

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && adj[cur][i] != id)
		{
			chainno++;
			ptr=0;
			hld(adj[cur][i],cur);
		}
	}
}






