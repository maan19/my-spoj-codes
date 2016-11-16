#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<limits.h>
using namespace std;
int n;
vector<pair<int,int> > g[50009];
int mx=INT_MIN;
int fv;
int dist[50009];
int visited[50009];
int  bfs(int src);
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
		mx=INT_MIN;
		int src=bfs(1);
		mx=INT_MIN;
		bfs(src);
		printf("%d\n",mx);
		
		for(int i=0;i<=n;i++)
			g[i].clear();
	}
}


int  bfs(int src)
{
	queue<int> q;
	memset(visited,0,sizeof(visited));
	q.push(src);
	visited[src]=1;
	memset(dist,0,sizeof(dist));
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].first;
			if(visited[v]==0)
			{
			q.push(v);
			dist[v]=dist[u]+g[u][i].second;
			visited[v]=1;
			if(dist[v]>mx)
				mx=dist[v],fv=v;
			}
		}
	}
	return fv;
}



		