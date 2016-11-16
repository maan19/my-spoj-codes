#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<limits.h>
#include<string>
#include<iostream>

using namespace std;
struct edge
{
	int start;
	int end;
	string name;
	int weight;
};
struct graph
{
	int vertices;
	vector<edge> edges;};

struct node
{
	int vertex;
	int priority;
	int pred;
};

graph G;
edge E;
unordered_map<std::string,int> m;
vector<node> heap;
vector<node> S;
node temp;
int heap_size;

void heapify(int i);
void del_min();
void dec_priority(int pri,int vertex,int i);
void dijsktra(string source,string dest);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&G.vertices);
		heap_size = G.vertices;
		heap.resize(G.vertices+1);
		

		for(int i =1;i<=G.vertices;i++)
		{
			cin>>E.name;
			//printf("%s\n",E.name);
			E.start =i;
			m.insert(make_pair(E.name,i));

			int n;
			scanf("%d",&n);

			for(int i=1;i<=n;i++)
			{
				scanf("%d",&E.end);
				scanf("%d",&E.weight);
				G.edges.push_back(E);
			}
		}

		int j;
		scanf("%d",&j);
		string source,dest;

		for(int i=1;i<=j;i++)
		{
			scanf("%s",&source);
			scanf("%s",&dest);

			dijsktra(source,dest);
		}

	}






}

void heapify(int i)
{
	if(2*i>heap_size)  //leaf node
		return;
	if(2*i+1 > heap_size)
	{
		if(heap[i].priority > heap[2*i].priority)
			{
				swap(heap[i],heap[2*i]);
				
		}
		return;
	}

	if(heap[i].priority <= min(heap[2*i].priority,heap[2*i + 1].priority))
		return;
	//printf("heapifying\n");

	if(heap[2*i].priority == min(heap[2*i].priority,heap[2*i + 1].priority))
	{
		swap(heap[i],heap[2*i]);
		heapify(2*i);
	}

	else
	{
		swap(heap[i],heap[2*i+1]);
		heapify(2*i+1);
	}
	//printf("heapify done\n");
	return;
}

void del_min()
{
	temp.priority = heap[1].priority;
	temp.pred = heap[1].pred;
	temp.vertex = heap[1].vertex;


	heap[1].pred = heap[heap_size].pred;
	heap[1].priority = heap[heap_size].priority;
	heap[1].vertex = heap[heap_size].vertex;

	heap_size--;
	heapify(1);
	//printf("del min done\n");
}

void dec_priority(int pri,int vertex,int i)
{
	heap[i].priority = pri;
	heapify(i/2);
	//printf("dec pri done\n");
}


void dijsktra(string source,string dest)
{
	
	heap[1].vertex=m[source];
	heap[1].priority=0;
	heap[1].pred = m[source];
	

	int k=1;
	for(int i=2;i<=heap_size;i++)
	{
		if(heap[1].vertex==k)
			k++;
		
		heap[i].priority = INT_MAX;
		heap[i].vertex = k;
		heap[i].pred = k;
		k++;

	}




	while(heap_size!=0)
	{
		del_min();
	
		S.push_back(temp);
		

		for(vector<edge>::iterator it = G.edges.begin();it!= G.edges.end();it++)
		{
			if(it->start == temp.vertex)
			{
				for(int i=1;i<=heap_size;i++)
				{
					if(heap[i].vertex == it->end)
					{
						if(heap[i].priority > temp.priority + it->weight)
							dec_priority(temp.priority + it->weight,it->end,i);
					}
				}
			}
		}
		//printf("pushing into s and updating done..\n");

	}
	//printf("heap empty\n");
	for(vector<node>::iterator it = S.begin();it!=S.end();it++)
	{
		if(it->vertex == m[dest])
			printf("%d\n",it->priority);
	}
}












