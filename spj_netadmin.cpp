#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
#define E 260000
int n,m,k,src,sink,nedge;
int c[510];
int cap[510][510];
int to[E],nxt[E],fin[510],lvl[510],work[510];
vector<pair<int,int> > s;

void add_edge(int u,int v,int cp);
bool bfs(int src);
int dfs(int src,int f);
int dinitz();

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d""%d""%d",&n,&m,&k);
		nedge=0;
		src =1,sink=n+1;
		for(int i=0;i<=sink;i++)
			fin[i]=-1;
		for(int i=1;i<=k;i++)
		{
				scanf("%d",&c[i]);
				to[nedge]=sink,nxt[nedge]=fin[c[i]],fin[c[i]]=nedge++;
		}
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d""%d",&u,&v);
			s.push_back(make_pair(u,v));
			add_edge(u,v,0);
		}
		int lo=1,hi=k,mid;
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
			/*for(int i=0;i<=sink;i++)
				for(int j=0;j<=sink;j++)
					cap[i][j]=0;*/
			for(int i=0;i<s.size();i++)
			{
				cap[s[i].first][s[i].second]=mid;
				cap[s[i].second][s[i].first]=mid;
			}
			for(int i=1;i<=k;i++)
			{
					cap[c[i]][sink]=1;
					cap[sink][c[i]]=0;
			}
			if(dinitz()==k)
				hi=mid;                                  //loop and cleanup
			else
				lo=mid+1;
		}
		printf("%d\n",lo);
		s.clear();
	}
}
void add_edge(int u,int v,int cp)
{
	to[nedge]=v,nxt[nedge]=fin[u],fin[u]=nedge++;
	to[nedge]=u,nxt[nedge]=fin[v],fin[v]=nedge++;
}
bool bfs(int src)
{
	for(int i=1;i<=sink;i++)
		lvl[i]=-1;
	int que[510];
	int f=0,e=0;
	que[1]=src;f=e=1;
	lvl[src]=0;
	while(f<=e)
	{
		int s = que[f++];
		for(int i=fin[s];i>=0;i=nxt[i])
		{
			int v=to[i];
			if(( cap[s][v] > 0) && (lvl[v]==-1))
			{
				que[++e]=v;
				lvl[v]=lvl[s]+1;
			}
		}
	}
	return (lvl[sink]>0);
}
 int dfs(int src,int f)
{
	if(src==sink)
		return f;
	for(int i=work[src];i>=0;i=nxt[i],work[src]=i)
	{
		int v = to[i];
		if(cap[src][v]>0 && (lvl[v] == (lvl[src]+1)))
		{
			int d = dfs(v,min(f,cap[src][v]));
			if(d>0)
			{
				cap[src][v]-=d;
				cap[v][src]+=d;
				return d;
			}
		}
	}
	return 0;
}

 int dinitz()
{
    int maxf=0,fl=0;
	while(bfs(1))
	{
		for(int i=1;i<=sink;i++)
			work[i]=fin[i];
		while(1)
		{
			fl=dfs(1,10000);
			if(fl==0)
				break;
			maxf+=fl;
			
		}
	}
	return maxf;
}
/*int ford_fulkerson(int src,int sink)
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
	bool visited[510];
	int parent[510];
	for(int i=0;i<=sink;i++)
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
	int path_capacity=1,to=sink,from;
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
}*/