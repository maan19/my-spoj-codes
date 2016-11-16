#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

struct node
{
	
	int v;
	int pri;
};

struct compare
{
	bool operator()(struct node &l,struct node & r)
	{
		return l.pri > r.pri;
	
	}
};



void build_heap(int src,int n);
int dijkstra(int src,int n,int exit);

struct node S[150];
int visited[150];
int D[150];
priority_queue<struct node,vector<struct node>,compare> q;
vector<vector<pair<int,int>>> g(150);

int main()
{
	int n,exit,time,m;
	scanf("%d %d %d %d",&n,&exit,&time,&m);
	

	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);

		g[u].push_back(make_pair(v,w));
	}

	int cnt =0;

	for(int i=1;i<=n;i++)
	{
		
		if(dijkstra(i,n,exit) <= time)
			cnt++;
	}

	printf("%d\n",cnt);

}

int dijkstra(int src,int n,int exit)
{
	build_heap(src,n);
	int i=1;

	while(!q.empty())
	{
		printf("cuure size %d\n",q.size());
		q.top();
		
		printf("ooon\n");
	
		visited[S[i].v] =1;
		

		if(S[i].v==exit)
			return S[i].pri;

		
		printf("hello2\n");
		for(int j=0 ;j<g[S[i].v].size();j++)
		{
			printf("hello2\n");
			if(visited[g[S[i].v][i].first]!=1 && (S[i].pri + g[S[i].v][i].second < D[g[S[i].v][i].first]))
			{
				struct node k;
				k.pri=D[g[S[i].v][i].first] = S[i].pri +g[S[i].v][i].second;
				k.v = g[S[i].v][i].first;
				q.push(k);
				printf("hello\n");
			}
		}
		i++;
	}
}

void build_heap(int src,int n)
{
	struct node t;

	for(int i=1;i<=n;i++)
	{

		t.v = i;
		D[i] = t.pri = (i==src)?0:INT_MAX;
		q.push(t);
	}

	for(int i=1;i<=150;i++)
		visited[i]=0;
	printf("heap built\n");
	printf("queue size %d\n",q.size());
}




	