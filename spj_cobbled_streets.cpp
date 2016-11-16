#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

unordered_map <int,int> PARENT;
unordered_map <int,int> RANK;






struct Edge
{
	int a;
	int b;
	int weight;
	Edge(int a,int b,int weight):a(a),b(b),weight(weight){}
};

struct Graph
{
	vector <int> vertices;
	vector <Edge> edges;
};

bool myfun(Edge x, Edge y)
{
	return(x.weight < y.weight);
}

void make_set(int m)
{
	for(int i=1;i<=m;i++)
		PARENT[i]=i;
}

int Find(int a)
{
	if(PARENT[a]==a)
		return a;
	return Find(PARENT[PARENT[a]]);
}

void Union(int a,int b)
{
	if(RANK[a] > RANK[b])
		PARENT[b]=a;
	else if(RANK[a] < RANK[b])
		PARENT[a] = b;
	else
		{
			PARENT[a] = b;
			RANK[b] = RANK[b] + 1;
	}
}

unsigned int kruskal(Graph & G,int n,int p);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int p;
		scanf("%d",&p);
		int n;
		scanf("%d",&n);
		int m;
		scanf("%d",&m);
		int a,b,c;

		Graph G;

		for(int i=1;i<=n;i++)
			G.vertices.push_back(i);
		
		for(int i=0;i<m;i++)
		{
			scanf("%d""%d""%d",&a,&b,&c);
			G.edges.push_back(Edge(a,b,c));

		}

		printf("%lu\n",kruskal(G,n,p));
	}
}

unsigned int kruskal(Graph & G,int n,int p)
{
	vector<Edge> MST;
	make_set(n);
	sort(G.edges.begin(),G.edges.end(),myfun);

	int i=1;

	for(vector<Edge>::iterator it = G.edges.begin();i<=n-1&&it!=G.edges.end();it++)
	{
		int x,y;
		if((x=Find(it->a)) != (y=Find(it->b)))
		{
			MST.push_back(Edge(it->a,it->b,it->weight));
			Union(x,y);
			i++;
		}

	}

	unsigned sum =0;

	for(int i=0;i<n-1;i++)
	{
		sum = sum + MST[i].weight;
	}

	return sum * p;
}
		









