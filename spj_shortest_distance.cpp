#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

struct adj_list_node
{
	int dest;
	int weight;
	struct adj_list_node * next;
};

struct graph
{
	int vertices;
	struct adj_list_node ** adj_list;
};

struct heap_node
{
	int v;
	int dist;
};

struct Heap
{
	int size;
	int capacity;
	int *pos ;  //for dec_key()
	struct heap_node * arr;
};





struct graph * create_graph(int v);
struct adj_list_node * create_node(int dest,int weight);
void add_edge(struct graph * G,int src,int dest,int weight);
void dijkstra(struct graph * G,int src,int dest);
Heap * create_heap(int cap);
void initiator(int source,Heap * H,int vertices);
void heapify(Heap *H, int i);
int extract_min(Heap * H);
void dec_key(Heap *H,int dist,int i);
void swap_heap_node(Heap * H,int i,int j);
void dijkstra(struct graph * G,int src,int dest,int vertices);
void print_heap_state(Heap * H);

unordered_map<std::string,int> m;

int main()
{
	
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int vertices;
		scanf("%d",&vertices);

		graph * G = create_graph(vertices);

		for(int i=1;i<=vertices;i++)
		{
		

			string s;
			cin>>s;
			
			
			m[s] =i;

			int n;
			scanf("%d",&n);

			int dest,weight;
			for(int j=1;j<=n;j++)
			{
				
				scanf("%d""%d",&dest,&weight);

				add_edge(G,i,dest,weight);
			}
		}

		int n;
		scanf("%d",&n);

		
		
			/*cout<<"gdansk is mapped to "<<m["gdansk"]<<endl;
			cout<<"warszawa is mapped to " << m["warszawa"]<<endl;
			cout<<"torum is mapped to "<<m["torum"]<<endl;
			cout<<"bydgoszcz is mapped to "<<m["bydgoszcz"]<<endl;*/
		

		for(int k=1;k<=n;k++)
		{
			string source,dest;
			cin>> source;
			cin>> dest;
			

			//printf("finding shortest dist b/w %d and %d\n",m[source],m[dest]);

			dijkstra(G,m[source],m[dest],vertices);
		}



	}
	return 0;
}


struct graph * create_graph(int v)
{
	struct graph * G = new graph ;
	G->vertices = v;

	G->adj_list = new adj_list_node *[v+1];

	for(int i=0;i<=v;i++)
	{
		G->adj_list[i] = NULL;
	}


	return G;
}

struct adj_list_node * create_node(int dest,int weight)
{
	adj_list_node * node = new adj_list_node;
	node->dest = dest;
	node->weight = weight;

	//printf("node created\n");

	return node;
}

void add_edge(struct graph * G,int src,int dest,int weight)
{
	 adj_list_node * node = create_node(dest,weight);
	node->next =G->adj_list[src] ;
	G->adj_list[src] =node;
	//printf("edge added\n");
	return;
}

Heap * create_heap(int cap)
{
	Heap * H = new Heap;
	H->capacity = cap;
	H->size=0;
	H->arr = new heap_node [cap+1];
	H->pos = new int [cap+1];
	return H;
}

void initiator(int source,Heap * H,int vertices)
{
	H->pos[source] = 1;
	H->size = vertices;
	H->arr[1].dist = 0;
	H->arr[1].v = source;

	for(int i=1,j=2;i<=vertices && j<= vertices ;i++)
	{
		if(source==i)
			continue;

		H->arr[j].v = i;
		H->arr[j].dist = INT_MAX;

		H->pos[i] =j;

		j++;
	}
}

void heapify(Heap *H, int i)
{
	int smaller = i,left = 2*i,right = 2*i+1;
	if(left<=H->size && H->arr[left].dist < H->arr[smaller].dist)
		smaller = left;
	if(right<=H->size && H->arr[right].dist < H->arr[smaller].dist)
		smaller  =right;

	if(smaller != i)
	{
		H->pos[H->arr[i].v] = smaller;
		H->pos[H->arr[smaller].v] =i;
		swap_heap_node(H,smaller,i);

		heapify(H,smaller);
	}
}

int extract_min(Heap * H)
{
	int dist = H->arr[1].dist;
	H->pos[H->arr[1].v] = H->size;
	H->pos[H->arr[H->size].v] = 1;
	swap_heap_node(H,1,H->size);
	
	(H->size)--;
	heapify(H,1);
	return dist;
}

void dec_key(Heap *H,int dist,int i)
{
	H->arr[i].dist = dist;
	i=i/2;
	while(i>=1)
		{
			heapify(H,i);
			i=i/2;
	}
}

	

void dijkstra(struct graph * G,int src,int dest,int vertices)
{
	Heap * H =create_heap(vertices);
	initiator(src,H,vertices);
	//print_heap_state(H);

	int * ps = new int [vertices+1];
	int * dist = new int [vertices + 1];
	int j=1;
	while(H->size!=0)
	{
		int d = extract_min(H);
		ps[H->arr[H->size+1].v] = j;
		dist[j] = d;

		adj_list_node * p =G->adj_list[H->arr[H->size+1].v];
		while(p!=NULL)
		{
			if(d  + p->weight < H->arr[H->pos[p->dest]].dist)
				dec_key(H,d+p->weight,H->pos[p->dest]);
			p = p->next;
		}
		//print_heap_state(H);
		j++;
	}

	printf("%d\n",dist[ps[dest]]);
}

void swap_heap_node(Heap * H,int i,int j)
{
	heap_node temp;
	temp.dist = H->arr[i].dist;
	temp.v = H->arr[i].v;

	H->arr[i].dist = H->arr[j].dist;
	H->arr[i].v = H->arr[j].v;
	H->arr[j].dist = temp.dist;
	H->arr[j].v = temp.v;
}

void print_heap_state(Heap * H)
{
	printf("\n heap \n");
	for(int i=1;i<=H->size;i++)
	{
		printf("%d %d     ",H->arr[i].v,H->arr[i].dist);
	}

	printf("\n pos \n");

	for(int i=1;i<=H->size;i++)
		printf("%d ",H->pos[i]);
	printf("\n");
}
















