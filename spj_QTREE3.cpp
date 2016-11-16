#include<stdio.h>
#include<vector>
#include<algorithm>
#define N 100009

using namespace std;

struct node
{
	int clr;
	int fb;
};

int n,q,chainno,ptr;

vector<int> adj[N];

struct node seg_tree[6*N];
int pos_base_array[N];
int base_array[N];
int subtree[N];
int parent[N];
int chainid[N];
int chainhead[N];
int segid[N];


void dfs(int cur,int prnt);
void hld(int cur,int prev);
void build_tree(int i,int s,int e);
int  query_tree(int i,int s,int e,int qs,int qe);
int query_up(int u,int v);
void update_tree(int i,int s,int e,int us);

int main()
{
	scanf("%d""%d",&n,&q);
	ptr=1,chainno=0;

	for(int i=0;i<=n;i++)
		adj[i].clear();

	for(int i=0;i<=n;i++)
		chainhead[i]=-1;

	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d""%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,-1);
	hld(1,-1);

	/*printf("base array\n");

	for(int i=1;i<=n;i++)
		printf("%d ",base_array[i]);
	printf("\n");

	printf("pos \n");
	for(int i=1;i<=n;i++)
		printf("%d ",pos_base_array[i]);
	printf("\n");*/

	build_tree(1,1,ptr-1);


	/*printf("seg\n");
	for(int i=1;i<=15;i++)
		printf("%d ",seg_tree[i].fb);*/

	

	for(int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d""%d",&a,&b);
		if(a==0)
		{
			update_tree(1,1,ptr-1,pos_base_array[b]);

		}
		else
		{
			printf("%d\n",query_up(b,1));
		}
	}
	return 0;
	
}

void dfs(int cur,int prnt)
{
	subtree[cur]=1;
	parent[cur]=prnt;

	for(int i = 0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prnt)
		{
			dfs(adj[cur][i],cur);
			subtree[cur] += subtree[adj[cur][i]];
		}
	}
}

void hld(int cur,int prev)
{
	if(chainhead[chainno]==-1)
		chainhead[chainno] = cur;

	pos_base_array[cur]=ptr;
	base_array[ptr++]= cur;
	chainid[cur]=chainno;

	int id=-1,mx=0;
	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev)
		{
			if(subtree[adj[cur][i]] > mx)
			{
				mx = subtree[adj[cur][i]];
				id = adj[cur][i];
			}
		}
	}

	if(id==-1)
	{
		

		return;
	}

	hld(id,cur);

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && adj[cur][i]!=id)
		{
			chainno++;
			hld(adj[cur][i],cur);
		}
	}
}

void build_tree(int i,int s,int e)
{
	if(s==e)
	{
		seg_tree[i].clr=0;
		seg_tree[i].fb=-1;
		return;
	}

	int mid = (s+e)>>1;

	build_tree(2*i,s,mid);
	build_tree(2*i+1,mid+1,e);

	seg_tree[i].fb = seg_tree[2*i].fb==-1?seg_tree[2*i+1].fb:seg_tree[2*i].fb;


}

int  query_tree(int i,int s,int e,int qs,int qe)
{
	if(e<qs || s>qe)
		return -1;

	if(s>=qs && e<=qe)
		return seg_tree[i].fb;

	int mid = (s+e)>>1;

	int x = query_tree(2*i,s,mid,qs,qe);
	if(x==-1)
		x = query_tree(2*i+1,mid+1,e,qs,qe);

	return x;
}

int query_up(int u,int v)
{
	int uchain,vchain,x=-1,y;
	uchain = chainid[u];
	vchain = chainid[v];
	//printf("u chain is %d vchain is %d\n",uchain,vchain);


	while(1)
	{
		if(uchain==vchain)
		{
			y =query_tree(1,1,ptr-1,pos_base_array[v],pos_base_array[u]);
			if(y==-1)
				return x;
			else
				return y;

		}

		y=query_tree(1,1,ptr-1,pos_base_array[chainhead[uchain]],pos_base_array[u]);
		if(y!=-1)
			x = y;
		u =parent[chainhead[uchain]];
		uchain = chainid[u];
	}
}

void update_tree(int i,int s,int e,int us)
{
	if(s==e)
	{
		if(seg_tree[i].clr==1)
		{
			seg_tree[i].clr=0;
			seg_tree[i].fb=-1;
		}
		else
		{
			seg_tree[i].clr=1;
			seg_tree[i].fb = base_array[s];
		}
		return;
	}

	int mid = (s+e)>>1;
	if(us > mid)
		update_tree(2*i+1,mid+1,e,us);
	else
		update_tree(2*i,s,mid,us);

	seg_tree[i].fb = seg_tree[2*i].fb==-1?seg_tree[2*i+1].fb:seg_tree[2*i].fb;
}
















