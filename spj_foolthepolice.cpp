#include<iostream>
#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<queue>
#include<string.h>
using namespace std;
int tim[105][105];
int risk[105][105];
int n,t;
pair<int,int> D[105];
bool visited[105];
void dijkstra();
struct cmp
{
	bool operator()(pair<int,pair<int,int> > & a,pair<int,pair<int,int> > &b)
	{
		if(a.second.first==b.second.first)
			return a.second.second>b.second.second;
		return a.second.first>b.second.first;
	}
};
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d""%d",&n,&t);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&tim[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&risk[i][j]);
		dijkstra();
	}
	
}
 
void dijkstra()
{
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,cmp >q;
	memset(visited,0,sizeof(visited));
	q.push(make_pair(1,make_pair(0,0)));
	for(int i=1;i<=n;i++)
		D[i].first=INT_MAX;
	D[1].first=0;
	D[1].second=0;
	while(!q.empty())
	{
		pair<int, pair<int,int> > u =q.top();
		q.pop();
		if(visited[u.first]==true)
			continue;
		if(u.first==n)
		{
			printf("%d %d\n",u.second.first,u.second.second);
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==u.first)
				continue;
			if(u.second.second + tim[u.first][i] <=t && u.second.first + risk[u.first][i] <=D[i].first)
			{
				if(u.second.first+risk[u.first][i]==D[i].first && u.second.second+tim[u.first][i]>=D[i].second)
					continue;
				D[i].first=u.second.first+risk[u.first][i];
				D[i].second=u.second.second + tim[u.first][i];
				q.push(make_pair(i,make_pair(u.second.first+risk[u.first][i],u.second.second + tim[u.first][i])));
			}
		}
		visited[u.first]=true;
	}
	printf("%d\n",-1);
}