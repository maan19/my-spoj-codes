#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp
{
	bool operator()(pair<int,  double> & p,pair<int,double> & q)
	{
		return p.second < q.second;
	}
};

vector<vector<pair<int,double>>> g(105);
double D[105];
int visited[105];

double dijks(int src,int n);

int main()
{
	int n,m;
	scanf("%d",&n);

	while(n)
	{
		scanf("%d",&m);

		for(int i=1;i<=m;i++)
		{
			int u,v;
			double w;
			scanf("%d""%d""%lf",&u,&v,&w);
			g[u].push_back(make_pair(v,w/(100.0)));
			g[v].push_back(make_pair(u,w/(100.0)));
		}

		printf("%.6lf percent\n",dijks(1,n)*(100.0));

		for(int i=1;i<=n;i++)
			g[i].clear();

		scanf("%d",&n);
	}

}

 double dijks(int src,int n)
{
	for(int i=1;i<=n;i++)
	{
			D[i]=-1.0;
			visited[i]=0;
	}

	priority_queue<pair<int,double>,vector<pair<int,double>>,cmp> q;

	pair<int,double> t;
	t.first = 1;
	D[1]=1.0;
	t.second =1.0;

	q.push(t);

	while(!q.empty())
	{
		int u = q.top().first;
		double d =  q.top().second;
		q.pop();

		if(visited[u])
			continue;

		if(u == n)
			return d;

		for(int i=0;i<g[u].size();i++)
		{
			int v = g[u][i].first;
		    double w = g[u][i].second;

			if(visited[v]==0 && (d* w) > D[v])
			{
					D[v] = d*w;
					q.push(make_pair(v,D[v]));
			}
		}

		visited[u]=1;
	}
}






