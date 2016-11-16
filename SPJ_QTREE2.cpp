#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
#define N 10100

using namespace std;

vector<int> adj[N];
vector<int> wt[N];

int depth[N];
int subtree[N];
int parent[15][N];
int chainid[N];
int chainhead[N];
int base_array[N];
int pos_base_array[N];
int seg_tree[6*N];


int n,chainno,ptr,LGN;

void dfs(int cur,int dpth,int prev);
void hld(int cur,int prev,int cost);
void build_tree(int i,int s,int e);
int query_tree(int i,int s,int e,int qs,int qe);
int lca(int u,int v);
int query_up(int u,int l);
int query(int u,int v);
int query2(int u,int v,int k);
int k_node(int u,int k);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		chainno=0;ptr=0;
		scanf("%d",&n);
		LGN = log((double)n)/log((double)2) + 1;

		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
			wt[i].clear();
		}

		for(int i=0;i<LGN;i++)
			for(int j=0;j<=n;j++)
				parent[i][j]=-1;

		for(int i=0;i<n;i++)
			chainhead[i]=-1;

		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d""%d""%d",&u,&v,&w);
			adj[u].push_back(v);
			wt[u].push_back(w);
			adj[v].push_back(u);
			wt[v].push_back(w);
		}

		dfs(1,0,-1);
		hld(1,-1,-1);
		build_tree(1,1,ptr-1);

		for(int i=1;i<LGN;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(parent[i-1][j]!=-1)
					parent[i][j] = parent[i-1][parent[i-1][j]];
			}
		}

		while(1)
		{
			char s[15];
			scanf("%s",s);

			if(s[1]=='O')
				break;

			int a,b,k;

			if(s[0]=='D')
			{
				scanf("%d""%d",&a,&b);
				printf("%d\n",query(a,b));
			}
			else
			{
				scanf("%d""%d""%d",&a,&b,&k);
				printf("%d\n",query2(a,b,k));
			}
		}
	}
}

void dfs(int cur,int dpth,int prev)
{
	depth[cur] = dpth;
	parent[0][cur] = prev;
	subtree[cur]=1;

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev)
		{
			dfs(adj[cur][i],depth[cur]+1,cur);
			subtree[cur] += subtree[adj[cur][i]];
		}
	}
}

void hld(int cur,int prev,int cost)
{
	if(chainhead[chainno]==-1)
		chainhead[chainno]=cur;

	chainid[cur]=chainno;
	pos_base_array[cur] = ptr;
	base_array[ptr++] = cost;



	int mx=0,id=-1;
	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && subtree[adj[cur][i]]>mx)
		{
			mx = subtree[adj[cur][i]];
			id = adj[cur][i];
			cost = wt[cur][i];
		}
	}

	if(id==-1)
		return;

	hld(id,cur,cost);

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && adj[cur][i] !=id)
		{
			chainno++;
			hld(adj[cur][i],cur,wt[cur][i]);
		}
	}
}

void build_tree(int i,int s,int e)
{
	if(s==e)
	{
		seg_tree[i] = base_array[s];
		return;
	}

	int mid = (s+e)>>1;

	build_tree(2*i,s,mid);
	build_tree(2*i+1,mid+1,e);

	seg_tree[i] = seg_tree[2*i] + seg_tree[2*i+1];
}

int query_tree(int i,int s,int e,int qs,int qe)
{
	if(s>qe || e<qs)
		return 0;

	if(s>=qs && e<=qe)
		return seg_tree[i];

	int mid = (s+e)>>1;

	int x =query_tree(2*i,s,mid,qs,qe);
	int y =query_tree(2*i+1,mid+1,e,qs,qe);

	return x+y;
}

int lca(int u,int v)
{
	if(depth[u]<depth[v])
		swap(u,v);

	for(int i=LGN-1;i>=0;i--)
	{
		if(depth[u]-(1<<i)>=depth[v])
			u = parent[i][u];
	}

	if(u==v)
		return u;

	for(int i=LGN-1;i>=0;i--)
	{
		if(parent[i][u]!=parent[i][v])
		{
			u = parent[i][u];
			v = parent[i][v];
		}
	}

	return parent[0][u];
}

int query_up(int u,int l)
{
	int uchain,lchain,sum=0;
	uchain = chainid[u],lchain = chainid[l];

	while(1)
	{
		if(uchain == lchain)
		{
			if(u==l)
				return sum;
			sum += query_tree(1,1,ptr-1,pos_base_array[l]+1,pos_base_array[u]);
			return sum;
		}

		sum += query_tree(1,1,ptr-1,pos_base_array[chainhead[uchain]],pos_base_array[u]);
		u = parent[0][chainhead[uchain]];
		uchain = chainid[u];
	}
}

int query(int u,int v)
{
	int l = lca(u,v);
	return (query_up(u,l) + query_up(v,l));
}

int query2(int u,int v,int k)
{
	int l =lca(u,v);
	if(depth[u]-depth[l]+1>=k)
		return k_node(u,k);
	else
		return k_node(v,(depth[v]-depth[l]+1)-(k-(depth[u]-depth[l]+1)));
}

int k_node(int u,int k)
{
	if(k==1)
		return u;

	int i;
	for( i=LGN-1;(1<<i)+1!=k;i--)
	{
		//printf("i is %d , k is %d , u is %d\n",i,k,u);
		if((1<<i) +1 < k)
		{
				u = parent[i][u];
				k = (k-(1<<i));
		}
		//printf("AFTER i is %d , k is %d , u is %d\n",i,k,u);
	}
	//printf("i is %d\n",i);
	return parent[i][u];
}  





			









