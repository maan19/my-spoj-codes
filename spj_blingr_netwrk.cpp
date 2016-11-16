#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
	int u,v,w;
};

bool my_cmp(const edge & a,const edge & b)
{
	return a.w < b.w;
}



char city[15];
vector<edge> g;
//vector<edge> MST;

int parent[10009];
int rnk[10009];
int n;

int kruskal();
int p(int x);
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
		{
			scanf("%s",city);
			int k;
			scanf("%d",&k);

			edge e;
			e.u=i;
			for(int j=1;j<=k;j++)
			{
					scanf("%d""%d",&e.v,&e.w);
					g.push_back(e);
			}
		}

		for(int i=1;i<=n;i++)
		{
			parent[i]=i;
			rnk[i]=0;
		}
			
		printf("%d\n",kruskal());
		g.clear();

		

	}
}


int kruskal()
{
    int mn=0;
	sort(g.begin(),g.end(),my_cmp);

	for(int i=0,j=0;j!=n-1 && i<g.size();i++)
	{
		int u=g[i].u,v=g[i].v,pu = p(u),pv=p(v);
		
		if(pu!=pv)
		{
			//MST.push_back(g[i]);
			mn = mn + g[i].w;
			j++;

			if(rnk[pu]==rnk[pv])
			{
				parent[pu]=pv;
				rnk[pv]++;
			}

			else if(rnk[pu] > rnk[pv])
				parent[pv]=pu;
			else
				parent[pu] = pv;
		}
	}
	return mn;
}


int p(int x)
{
	int i;
	for(i=x;parent[i]!=i;i=parent[i])
	{}
	return i;
}





				






