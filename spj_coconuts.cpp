#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int b[310];
vector<int> g[310];

int n,m,src,sink;
int ford_fulkerson(int src,int sink);
int bfs(int src,int sink);
int cap[305][305];
int main()
{
	while(1)
	{
	scanf("%d""%d",&n,&m);
	if(n==0)
		break;
	src=0,sink=n+1;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			cap[i][j]=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(b[i])
			g[i].push_back(sink),cap[i][sink]=1;
		else
			g[src].push_back(i),cap[src][i]=1;
	}

	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d""%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		cap[u][v]=1;
		cap[v][u]=1;
	}
	printf("%d\n",ford_fulkerson(src,sink));
	for(int i=0;i<=n+1;i++)
		g[i].clear();
	}
	return 0;
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
	bool visited[305];
	int parent[305];
	for(int i=0;i<=n+1;i++)
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
			if(visited[v]==false && (cap[s][v])>0)
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
		cap[to][from]=+path_capacity;
		to=from;
	}
	return path_capacity;
}


		
