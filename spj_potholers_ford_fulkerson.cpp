#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define max 100000000

vector<int>  g[205];
int cap[205][205];
int bfs(int src,int sink);
int ford_fulkerson(int src,int sink);
int n;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			cap[i][j]=0;
	for(int i=1;i<n;i++)
	{
		int v,k;
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&v);
			if(i==1||v==n)
				cap[i][v]=1,cap[v][i]=0;
			else
				cap[i][v]=max,cap[v][i]=0;
			g[i].push_back(v);
			g[v].push_back(i);
		}
	}
	printf("%d\n",ford_fulkerson(1,n));
	for(int i=0;i<=n;i++)
		g[i].clear();
	}
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
	bool visited[205];
	int parent[205];
	for(int i=0;i<=n;i++)
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


		


		




	


