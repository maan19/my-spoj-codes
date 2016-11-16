#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
bool visited[10000000];
int l[10000000];
int bfs(int src,int dst);
int u,d,f;
queue<int>q;
int main()
{
	int s,g;
	cin>>f>>s>>g>>u>>d;
	if(s==g)
	{cout<<0;return 0;}
	int p=bfs(s,g);
	if(p!=-1)
		cout<<p;
	else
		cout<<"use the stairs";
}
int bfs(int src,int dst)
{
	visited[src]=true;
	l[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		if(s+u<=f && visited[s+u]==false)
		{
			visited[s+u]=true;
			l[s+u]=l[s]+1;
			q.push(s+u);
			if((s+u)==dst)
				return l[s+u];
		}
		if((s-d)>=1 && visited[s-d]==false)
		{
			visited[s-d]=true;
			l[s-d]=l[s]+1;
			q.push(s-d);
			if((s-d)==dst)
				return l[s-d];
		}
	}
	return -1;
}
