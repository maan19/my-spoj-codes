#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int g[105][105];
bool visited[105][105];
int t;pair<int,int> h;
int D[105][105];
int m,n;
int dijkstra();
struct cmp
{
	bool operator()(pair<pair<int,int>,int> &a,pair<pair<int,int>,int>& b)
	{
		return a.second>b.second;
	}
};
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d""%d",&m,&n);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&g[i][j]);
		scanf("%d""%d",&h.first,&h.second);
		scanf("%d",&t);
		int p=dijkstra();
		if(p<=t)
			printf("YES\n%d\n",t-p);
		else
			printf("NO\n");
	}
}
int dijkstra()
{
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,cmp> q;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			D[i][j]=100000000;
	memset(visited,0,sizeof(visited));
	D[1][1]=g[1][1];
	q.push(make_pair(make_pair(1,1),g[1][1]));
	while(!q.empty())
	{
		pair<pair<int,int>,int> u =q.top();
		q.pop();
		int i=u.first.first,j=u.first.second;
		int d= u.second;
		if(visited[i][j])
			continue;
		if(i==h.first && j==h.second)
			return d;
		pair<pair<int,int>,int> b;
		if(i-1>=1)
		{
			if((d+g[i-1][j])<D[i-1][j])
			{
				D[i-1][j]=d+g[i-1][j];
				b.first.first = i-1;
				b.first.second = j;
				b.second = d+g[i-1][j];
				q.push(b);
			}
		}
		if(i+1<=m)
		{
			if((d+g[i+1][j])<D[i+1][j])
			{
				D[i+1][j]=d+g[i+1][j];
				b.first.first=i+1;
				b.first.second =j;
				b.second=d+g[i+1][j];
				q.push(b);
			}
		}
		if(j-1>=1)
		{
			if((d+g[i][j-1])<D[i][j-1])
			{
				D[i][j-1]=d+g[i][j-1];
				b.first.first=i;
				b.first.second =j-1;
				b.second = d+g[i][j-1];
				q.push(b);
			}
		}
		if(j+1<=n)
		{
			if((d+g[i][j+1])<D[i][j+1])
			{
				D[i][j+1]=d+g[i][j+1];
				b.first.first=i;
				b.first.second=j+1;
				b.second =d+g[i][j+1];
				q.push(b);
			}
		}
		visited[i][j]=true;
	}
}