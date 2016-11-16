#include<stdio.h>
#include<iostream>
using namespace std;
char data[1005][1005];
pair<int,int> p[1005][1005];
int n,m;
void make_set();
void merge(pair<int,int> a,pair<int,int> b);
pair<int,int> find(pair<int,int> a);
void print();
int main()
{
	scanf("%d""%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",data[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			p[i][j]=make_pair(i,j);
	//print();
	int count=0;
	make_set();
	//print();
	for(int i =0;i<n;i++)
		for(int j=0;j<m;j++)
			if(p[i][j]==make_pair(i,j))
				count++;
	printf("%d\n",count);
}

void make_set()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{

			if(data[i][j]=='S')
				merge(make_pair(i,j),make_pair(i+1,j));
			else if(data[i][j]=='W')
				merge(make_pair(i,j),make_pair(i,j-1));
			else if(data[i][j]=='E')
				merge(make_pair(i,j),make_pair(i,j+1));
			else if(data[i][j]=='N')
				merge(make_pair(i,j),make_pair(i-1,j));
		}
		
	}
}

void merge(pair<int,int> a,pair<int,int> b)
{
	pair<int,int>d=find(a);  
	pair<int,int>q = find(b);
	if(d==q)
		return;
	(p[d.first][d.second]).first=q.first;
	(p[d.first][d.second]).second   =q.second;
}

pair<int,int> find(pair<int,int> a)
{
	if(p[a.first][a.second]==a)
		return a;
	return find(p[a.first][a.second]);
}

void print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%c   ",data[i][j],p[i][j].first,p[i][j].second);
		printf("\n");
	}
}

