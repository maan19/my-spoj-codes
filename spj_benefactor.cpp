#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define m 50009
using namespace std;

vector<pair<int,int> > g[m];
bool visited[m];
int parent[m];
int n;
int bfs(int src);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d""%d""%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}
		int src = bfs(1);
		printf("src %d\n",src);
		int d=bfs(src);
		printf("%d\n",d);
		int dist=0;
		while(d!=src)
		{
			dist+=g[parent[d]][d].second;
			d=parent[d];
		}
		printf("%d\n",dist);
		for(int i=0;i<=n;i++)
			g[i].clear();
	}
}

int bfs(int src)
{
	for(int i=0;i<=n;i++)
		visited[i]=false,parent[i]=-1;
	queue<int > q;
	q.push(src);
	visited[src]=true;
	int last;
	while(!q.empty())
	{
		int u =q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			if(visited[v]==false)
			{
				visited[v]=true;
				q.push(v);
				parent[v]=u;
				last = v;
			}
		}
	}
	return last;
}


