#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;


vector<vector<int> > g(1003);
int depth [1003];
int parent[11][1003];
int LGN;
void dfs(int node,int prnt,int dpth);
int lca(int u,int v);

int main()
{
	int t,k=1;
	scanf("%d",&t);

	while(t--)
	{
		int n,m,c;
		scanf("%d",&n);

		LGN = (log(double(n))/log(2.0))+1;

		

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
					scanf("%d",&c);
					g[i].push_back(c);
			}
		}
		
		for(int i=0;i<=LGN;i++)
			for(int j=0;j<=n;j++)
				parent[i][j]=-1;
		

		dfs(1,-1,0);

		for(int i=1;i<LGN;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(parent[i-1][j]!=-1)
					parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}

		int u,v,q;
		scanf("%d",&q);
		printf("Case %d:\n",k++);
		for(int i=1;i<=q;i++)
		{
			scanf("%d""%d",&u,&v);
			printf("%d\n",lca(u,v));
		}

		for(int i=0;i<=n;i++)
			g[i].clear();

	}
}

void dfs(int node,int prnt,int dpth)
{
	depth[node] = dpth;
	parent[0][node]  = prnt;

	for(int i=0;i<g[node].size();i++)
		dfs(g[node][i],node,dpth+1);
}

int lca(int u,int v)
{
	  int tmp=u;
	  u = depth[u]>=depth[v]?u:v;
	  v = depth[tmp]<depth[v]?tmp:v;
	 
	  for(int i=LGN-1;i>=0;i--)
	 {
		if((depth[u]-(1<<i)) >= depth[v])
			u = parent[i][u];
	 }

	if(u == v)
		return u;

	for(int i=LGN-1;i>=0;i--)
	{
		if(parent[i][u]!=-1 && parent[i][u]!=parent[i][v])
		{
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}