#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int cap[130][130];
vector<char> g[130];

int ford_fulkerson(int src,int sink);
int bfs(int src,int sink);

int main()
{
	int n;char t;
	scanf("%d",&n);scanf("%c",&t);
	for(int i=1;i<=n;i++)
	{
		char u,v;int cp;
		scanf("%c",&u);scanf("%c",&t);scanf("%c",&v);
		scanf("%d",&cp);
		scanf("%c",&t);
		g[u].push_back(v);
		g[v].push_back(u);
		cap[u][v]+=cp;             //multiedges bidirectional??
	}
	printf("%d\n",ford_fulkerson('A','Z'));
}
int ford_fulkerson(int src,int sink)
{
	int maxflow=0,x=0;
	while(1)
	{
	x=bfs(src,sink);
	if(x)
		maxflow+=x;
	else
		return maxflow;
	}
}

int bfs(int src,int sink)
{
	bool visited[130];
	int parent[130];
	for(int i=0;i<130;i++)
		visited[i]=false,parent[i]=-1;
	queue<int> q;
	q.push(src);
	visited[src]=true;
	bool flag =true;
	while(!q.empty() && flag)
	{
		int s=q.front();
		q.pop();
		for(int i=0;i<g[s].size() && flag;i++)     //finding an augment path
		{
			int v=g[s][i];
			if(visited[v]==false && cap[s][v]>0)
			{
				visited[v]=true;
				parent[v]=s;
				q.push(v);
				if(v==sink)
					flag=false;
			}
		}
	}
	if(flag)
		return 0;
	int path_capacity=100000000,to=sink,from;
	while(to!=src)
	{
		from=parent[to];
		path_capacity=min(path_capacity,cap[from][to]);  //finding min path capacity
		to=from;
	}
	to=sink;
	while(to!=src)
	{
		from=parent[to];
		cap[from][to]-=path_capacity;
		cap[to][from]+=path_capacity;
		to=from;
	}
	return path_capacity;
}
