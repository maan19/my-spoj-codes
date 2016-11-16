

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<limits.h>



using  namespace std;

struct compare
{
	bool operator()(pair<int,int> & p,pair<int,int> & q)
	{
		return p.second > q.second;
	}
};

vector<vector<pair<int,int>>> g(120);

int D[120];
int visited[120];

int dijkstras(int src,int n,int ext);


int main()
{
	int n,ext,tim,m;
	scanf("%d %d %d %d",&n,&ext,&tim,&m);

	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);

		g[u].push_back(make_pair(v,w));
	}

	int cnt = 0;

	for(int i=1;i<=n;i++)
	{
		int x = dijkstras(i,n,ext);
		if(x>=0 && x<=tim)
			cnt++;
	}

	printf("%d\n",cnt);

}

int dijkstras(int src,int n,int ext)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;

	for(int i=0;i<=n;i++)
	{
			visited[i]=0;
			D[i] =  (i==src)?0:INT_MAX;
	}
	
	pair<int,int> t;
	t.first = src;
	t.second = 0;
	q.push(t);


	while(!q.empty())
	{
		int u = q.top().first;
		int d = q.top().second;
		q.pop();

		if(visited[u])
			continue;

		if(u == ext)
			return d;

		for(int i=0;i<g[u].size();i++)
		{
			int v = g[u][i].first;
			int w = g[u][i].second;

			if(d + w < D[v])
			{
				D[v] = d+w;
				q.push(make_pair(v,d+w));
			}
		}

		visited[u]=1;
	}

	return D[ext];
}


