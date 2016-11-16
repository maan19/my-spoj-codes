#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define N 10010
using namespace std;

vector<int>  adj[N];
vector<int> index[N];
vector<int> wt[N];

int parent[15][N];
int depth[N];
int subtree[N];
int other_end[N];
int cst[N];
int heavy[N];
int chainid[N];
int chainhead[N];
int base_array[N];
int pos_base_array[N];
int seg_tree[6*N];
char a[15];

int nod,chainno,ptr,LGN;
void heavy_light(int cur,int prev);
void dfs(int cur);
void init();
void build_tree(int i,int s,int e);
int  query_tree(int i,int s,int e,int qs,int qe);
void update_tree(int i,int s,int e,int us,int val);
int query_up(int u,int l);
int query(int u,int v);



int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		chainno=0;ptr=0;
		
		scanf("%d",&nod);

		LGN  = log(double(nod))/log(double(2)) + 1;

		for(int i=0;i<=nod;i++)
			heavy[i]=-1;

		for(int j=0;j<LGN;j++)
			for(int i=0;i<=nod;i++)
				parent[j][i]=-1;

		for(int i=0;i<=nod;i++)
		{
				adj[i].clear();
				index[i].clear();
				wt[i].clear();
		}
		
		for(int i=1;i<nod;i++)
		{
			int u,v,w;
			scanf("%d""%d""%d",&u,&v,&w);
			adj[u].push_back(v);
			index[u].push_back(i);
			wt[u].push_back(w);
			adj[v].push_back(u);
			index[v].push_back(i);
			wt[v].push_back(w);
	
		}
	
		
		depth[1]=0;

		dfs(1);

		/*printf("ends\n");
		for(int i=0;i<=nod;i++)
			printf("%d %d\n",i,other_end[i]);*/
		
		heavy_light(1,-1);

		/*printf("base array\n");
		for(int i=0;i<ptr;i++)
			printf("%d\n",base_array[i]);

		 printf("base arary\n");
		for(int i=0;i<ptr;i++)
			printf("%d\n",base_array[i]);

		printf("pos\n");
		for(int i=0;i<=nod;i++)
			printf("%d %d\n",i,pos_base_array[i]);

		printf("heavy\n");
		for(int i=1;i<=nod;i++)
			printf("%d \n",heavy[i]);*/

		build_tree(1,1,ptr-1);

		int u,v;
		

		while(1)
		{
			scanf("%s",a);
			if(a[0]=='D')
				break;
			scanf("%d""%d",&u,&v);
			if(a[0]=='Q')
				printf("%d\n",query(u,v));
			else
				update_tree(1,1,ptr-1,pos_base_array[other_end[u]],v);
		}
	}
	return 0;
}

void dfs(int cur)
{
	subtree[cur]=1;

	for(int i=0;i<adj[cur].size();i++)
	{
		int j = adj[cur][i];
		if(j==parent[0][cur]) 
			continue;

		parent[0][j] = cur;
		depth[j] = depth[cur]+1;
		other_end[index[cur][i]] = adj[cur][i];
		cst[adj[cur][i]] = wt[cur][i];

		dfs(j);  

		subtree[cur] += subtree[j];
		if(heavy[cur]==-1 || subtree[j] > subtree[heavy[cur]])
		{
			heavy[cur]=j;
		}
	}

}

void heavy_light(int cur,int prev)
{
	if(parent[0][cur] ==-1 || heavy[prev]!=cur)
		chainhead[chainno] = cur;

	chainid[cur] = chainno;
	pos_base_array[cur] = ptr;
	base_array[ptr++] = cst[cur];  //chaeck for edge incident on root;

	if(heavy[cur]==-1)
		return;

	heavy_light(heavy[cur],cur);

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && adj[cur][i] != heavy[cur])
		{
			chainno++;
			heavy_light(adj[cur][i],cur);
		}
	}
}


void build_tree(int i,int s,int e)
{
	if(s==e){
		seg_tree[i] = base_array[s];
		return;
	}

	int mid = (s+e)>>1;
	build_tree(2*i,s,mid);
	build_tree(2*i+1,mid+1,e);

	seg_tree[i] = seg_tree[2*i]>seg_tree[2*i+1]?seg_tree[2*i]:seg_tree[2*i+1];
}

int  query_tree(int i,int s,int e,int qs,int qe)
{
	if(qs>e || qe<s)
		return 0;

	if(s >= qs && e <=qe)
		return seg_tree[i];
	
	int mid = (s + e)>>1;
	int x,y;
	x = query_tree(2*i,s,mid,qs,qe);
	y = query_tree(2*i+1,mid+1,e,qs,qe);

	return x>y?x:y;
}

void update_tree(int i,int s,int e,int us,int val)
{
	if(s==e)
	{
		seg_tree[i]=val;
		return;
	}

	int mid = (s+e)>>1;
	if(us>mid)
		update_tree(2*i+1,mid+1,e,us,val);
	else
		update_tree(2*i,s,mid,us,val);

	seg_tree[i] = seg_tree[2*i]>seg_tree[2*i+1]?seg_tree[2*i]:seg_tree[2*i+1];
}

int lca(int u,int v)
{
	  
	  if(depth[u]<depth[v])
		  swap(u,v);

	  for(int i=LGN-1;i>=0;i--)
	  {
		  if(depth[u]-(1<<i)>=depth[v])
			  u = parent[i][u];           //u at level of v
	  }

	  if(u==v)
		  return u;

	  for(int i=LGN-1;i>=0;i--)
	  {
		  if(parent[i][u]!=parent[i][v])
		  {  
			  u = parent[i][u];
			  v= parent[i][v];
		  }
	  }

	  return parent[0][u];
}

int query_up(int u,int l)
{
	int uchain=chainid[u],lchain=chainid[l],ans,mx=0;
	while(1)
	{
		if(uchain==lchain)
		{
			if(u==l)
				return mx;
			ans = query_tree(1,1,ptr-1,pos_base_array[l]+1,pos_base_array[u]);
			mx = ans>mx?ans:mx;
			return mx;
		}

		ans=query_tree(1,1,ptr-1,pos_base_array[chainhead[uchain]],pos_base_array[u]);
		mx = ans>mx?ans:mx;
		u = parent[0][chainhead[uchain]];
		uchain = chainid[u];

	}
}    

int query(int u,int v)
{
	int l = lca(u,v);
	int x = query_up(u,l);
	int y = query_up(v,l);
	return x>y?x:y;
}

				







