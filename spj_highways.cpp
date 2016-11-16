#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#define INF 1000000000
using namespace std;




struct cmp
{
	bool operator()(pair<int,int> &a,pair<int,int> &b)
	{
		return a.second>b.second;
	}
};

vector<vector<pair<int,int>>> g(100005);

int D[100005];
int visited[100007];
int n,m,s,e;
int dijkstras(int src,int e);

int main()
{

	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d""%d""%d""%d",&n,&m,&s,&e);

		int u,v,w;
		for(int i=1;i<=m;i++)
		{
			scanf("%d""%d""%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			g[v].push_back(make_pair(u,w));
		}

		int k = dijkstras(s,e);
		if(k == INF)
			printf("NONE\n");
		else
			printf("%d\n",k);

		for(int i=0;i<=n;i++)
			g[i].clear();
	}

}

int dijkstras(int src,int e)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
	q.push(make_pair(src,0));
	
	for(int i=1;i<=n;i++)
	{
			D[i]=INF;
			visited[i]=0;
	}
	
	D[src]=0;

	while(!q.empty())
	{
		int u = q.top().first;
		int d = q.top().second;
		q.pop();

		if(visited[u]==1)
			continue;
		if(u==e)
			return d;

		for(int i=0;i<g[u].size();i++)
		{
			int v,w;
			v=g[u][i].first;
			w=g[u][i].second;

			if(d+w<D[v])
			{
				D[v]=d+w;
				q.push(make_pair(v,d+w));
			}
		}

		visited[u]=1;
	}

	return INF;
}



	


