#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define mx 50009                                                                                                                                                                                                                                                                          
using namespace std;
vector<pair<int,int> > g[mx];
bool visited[mx];
int D[mx]; // long long?
int n,m=-1;
void dijkstra(int src);
struct cmp
{
	bool operator()(pair<int,int> & a,pair<int,int> & b)
	{
		return a.second > b.second;
	}
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m=-1;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d""%d""%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}
		for(int i=1;i<=n;i++)
			dijkstra(i);
		printf("%d\n",m);
		for(int i=0;i<=n;i++)
			g[i].clear();
	}
}

void dijkstra(int src)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q;
	for(int i=1;i<=n;i++)
		D[i]=-1,visited[i]=false;
	D[src]=0;
	pair<int ,int > t;
	t.first=src;t.second=0;
	q.push(t);
	while(!q.empty())
	{
		int u =q.top().first;
		int d= q.top().second;
		q.pop();
		if(visited[u])
			continue;
		m = d>m?d:m;
		for(int i =0;i<g[u].size();i++)
		{
			int v = g[u][i].first,w=g[u][i].second;
			if(visited[v]==false && (d+w) > D[v])
			{
					D[v]=d+w;
					t.first=v,t.second=D[v];
					q.push(t);
			}
		}
		visited[u]=true;
	}
}

