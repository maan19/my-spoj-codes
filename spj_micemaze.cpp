#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<list>;
#include<limits.h>
using namespace std;

vector<list<pair<int,int>>> g(102);
void swp(int i,int smaller);
void heapify(int i);
void build_heap(int src);
struct node del_min();
void dec_pri(int i,int val);
int dijkstra(int src,int exit,int n);



struct node
{
	int v;
	int pri;
};



struct node heap[102];
int visited[102];
struct node S[102];
int pos[102];
int heap_size;

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

	int cnt=0;

	for(int i=1;i<=n;i++)
	{
		int x = dijkstra(i,exit,n);
		if(x>=0 && x<=time)
		{
				cnt++;
				//printf("%d comes out.\n",i);
		}
	}

	printf("%d\n",cnt);
}


void heapify(int i)
{
	int smaller = i;

	if(2*i <= heap_size && heap[2*i].pri < heap[smaller].pri)
		smaller = 2*i;
	if(2*i+1 <= heap_size && heap[2*i+1].pri < heap[smaller].pri)
		smaller = 2*i+1;

	if(smaller!=i)
	{
		swp(i,smaller);
		heapify(smaller);
	}

}

struct node del_min()
{
	struct node temp = heap[1];
	swp(1,heap_size);
	heap_size--;
	heapify(1);
	return temp;
}

void dec_pri(int i,int val)
{
	heap[i].pri = val;
	i=i/2;

	while(i>=1)
	{
		heapify(i);
		i=i/2;
	}
}



void swp(int i,int smaller)
{
	pos[heap[i].v] = smaller;
	pos[heap[smaller].v]= i;

	struct node temp =heap[i];
	heap[i] = heap[smaller];
	heap[smaller] = temp;
}

void build_heap(int src)
{
	heap[1].v = src;
	heap[1].pri = 0;
	pos[src] = 1;

	for(int i=1,j=2;i<=heap_size;i++)
	{
		if(i==src)
			continue;

		heap[j].v = i;
		heap[j].pri = INT_MAX;
		pos[i] = j;
		j++;
	}


}

int dijkstra(int src,int exit,int n)
{
	heap_size=n;
	build_heap(src);
	

	//printf("dij called with src %d and heap %d\n",src,heap_size);
	for(int i=0;i<102;i++)
		visited[i]=0;

	int i=1;
	while(heap_size)
	{
		S[i++] = del_min();
		visited[S[i-1].v] =1;

		if(S[i-1].v == exit)
		{
				//printf("%d for src %d\n",S[i-1].pri,src);
				return S[i-1].pri;
		}

		

		list<pair<int,int>>::iterator it;

		for(it = g[S[i-1].v].begin();it!=g[S[i-1].v].end();it++)
		{
			if((!visited[it->first]) && S[i-1].pri + it->second < heap[pos[it->first]].pri)
				dec_pri(pos[it->first],S[i-1].pri + it->second);
		}

	/*	for(int i =1;i<=heap_size;i++)
		{
			printf("v %d at %d with pri %d\n",heap[i].v,i,heap[i].pri);
		}*/
			
		
	}
}





















