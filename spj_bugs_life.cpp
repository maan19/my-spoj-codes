#include<iostream>
#include<malloc.h>
#include<queue>

using namespace std;

int colour[3000];
int visited[3000];


struct adjlistnode
{
	int data;
	struct adjlistnode * next;
};

struct adjlist
{
	struct adjlistnode * head;
};

struct graph
{
	int v;
	struct adjlist * ary;
};

struct adjlistnode * create_new_node(int data)
{
	struct adjlistnode * t = new (struct adjlistnode) ;
	t->data = data;
	t->next = NULL;

	return t;
}

struct graph * create_graph(int v)
{
	struct graph * Graph = new (struct graph);

	Graph->v = v;
	struct adjlist * p = new struct adjlist [v+1];
	Graph->ary = p;

	for(int i=0;i<=v;i++)
	{
		Graph->ary[i].head = NULL;
	}

	return Graph;
}

void create_edge(int source,int dest,struct graph  * Graph)
{
	struct adjlistnode * p = create_new_node( dest);
	p->next = Graph->ary[source].head;
	Graph->ary[source].head = p;

	p = create_new_node(source);
	p->next = Graph->ary[dest].head;
	Graph->ary[dest].head  = p;

}

int bfs_bipirateness(struct graph * Graph,int src)
{
	queue <int> q;
	

	q.push(src);
	colour[src] = 1;
	visited[src]=1;

	if(Graph->v==1)
		return 1;

	while(!q.empty())
	{
		int src = q.front();
		
		
		q.pop();
		
		

		struct adjlistnode * p =NULL;
		p= Graph->ary[src].head;

		while(p!=NULL)
		{
			
			if(colour[p->data] ==-1)
			{
				if(colour[src] == 1)
					colour[p->data] = 2;
				else
					colour[p->data] = 1;
				q.push(p->data);
				visited[p->data]=1;
			}

			else if(colour[p->data] == colour[src])
				return 0;
			p=p->next;
			
		}

		

	}

	for(int i=1;i<=Graph->v;i++)
		{
			if(visited[i] == -1)
				{
					if(!bfs_bipirateness(Graph,i))
						return 0;
			}
			
		}


		return 1;


		

}

	

int main()
{
	int t,bugs,src,dst;
	long int itr;

	scanf("%d",&t);

	int j=1;

	while(t--)
	{
		
		

		scanf("%d" "%ld",&bugs,&itr);
		struct graph * Graph = create_graph(bugs);

		src=0;
		for(int i = 0;i<itr;i++)
		{
			scanf("%d" "%d",&src,&dst);
			create_edge(src,dst,Graph);
		}

		for(int i=0;i<=bugs;i++)
		{
				colour[i] = -1;
				visited[i]=-1;
		}
		
		
		printf("Scenario #%d:\n",j);
		if(bfs_bipirateness(Graph,1))
			printf("No suspicious bugs found!\n");

		else
			printf("Suspicious bugs found!\n");

		j++;


		struct adjlistnode *p,*q;
	
		for(int i=1;i<=Graph->v;i++)
		{
			p= q = Graph->ary[i].head;
			while(p!=NULL)
			{
				q=p;
				p=p->next;
				delete(q);
			}
		}
			
		delete(Graph->ary);
		delete(Graph);
	}

	return 0;
}








	





