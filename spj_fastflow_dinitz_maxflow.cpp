#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define mx 30005
#define nx 5006
#define M 1000000089
using namespace std;

int n,m,nedge,src,sink,flag=0;
int to[mx*2],nxt[mx*2],fin[nx],lvl[nx],work[nx];
long long int cp[nx][nx];

void add_edge(int u,int v,int cp);
bool bfs(int src);
long long int dfs(int src,long long int f);
long long int dinitz();

int main()
{
	scanf("%d""%d",&n,&m);
	src =1,sink=n;
	for(int i=1;i<=n;i++)
		fin[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d""%d""%d",&u,&v,&c);
		if(u==v) continue;
		add_edge(u,v,c);                //adj list graph,add edge to list of node u,v
		cp[u][v]+=c;
		cp[v][u]+=c;                    //residual graph
	}
	printf("%lld\n",dinitz());
}
void add_edge(int u,int v,int cp)
{
	to[nedge]=v,nxt[nedge]=fin[u],fin[u]=nedge++;
	to[nedge]=u,nxt[nedge]=fin[v],fin[v]=nedge++;
}
bool bfs(int src)
{
	for(int i=1;i<=n;i++)
		lvl[i]=-1;
	int que[nx];
	int f=0,e=0;
	que[1]=src;f=e=1;
	lvl[src]=0;
	while(f<=e)
	{
		int s = que[f++];
		for(int i=fin[s];i>=0;i=nxt[i])
		{
			int v=to[i];
			if(( cp[s][v] > 0) && (lvl[v]==-1))
			{
				que[++e]=v;
				lvl[v]=lvl[s]+1;
			}
		}
	}
	return (lvl[sink]>0);
}
long long int dfs(int src,long long int f)
{
	if(src==sink)
		return f;
	for(int i=work[src];i>=0;i=nxt[i],work[src]=i)
	{
		int v = to[i];
		if(cp[src][v]>0 && (lvl[v] == (lvl[src]+1)))
		{
			long long int d = dfs(v,min(f,cp[src][v]));
			if(d>0)
			{
				cp[src][v]-=d;
				cp[v][src]+=d;
				return d;
			}
		}
	}
	return 0;
}

long long int dinitz()
{
	long long int maxf=0,fl=0;
	while(bfs(1))
	{
		for(int i=1;i<=n;i++)
			work[i]=fin[i];
		while(1)
		{
			fl=(long long int)dfs(1,M);
			if(fl==0)
				break;
			maxf+=fl;
			
		}
	}
	return maxf;
}
	


			





  