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

int LGN,chainno,ptr,nod;

int depth[N];
int cst[N];
int other_end[N];
int subtree[N];
int chainhead[N];
int chainid[N];
int base_array[N];
int pos_base_array[N];
int seg_tree[6*N];
int parent[15][N];
char a[15];

void dfs(int node,int prnt,int dpth);
void hld(int cur,int cost,int prev);
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
	
		for(int i=0;i<=nod;i++)
			chainhead[i]=-1;
		
		dfs(1,-1,0);

		for(int i=1;i<LGN;i++)
		{
			for(int j=1;j<=nod;j++)
			{
				if(parent[i-1][j]!=-1)
					parent[i][j] = parent[i-1][parent[i-1][j]];    
			}
		}


		hld(1,-1,-1);

		printf("base array\n");
		for(int i=0;i<ptr;i++)
			printf("%d\n",base_array[i]);

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



void dfs(int node,int prnt,int dpth)
{
	
	depth[node] = dpth;
	parent[0][node] = prnt;
	subtree[node]=0;

	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i]!=prnt)
		{
			dfs(adj[node][i],node,dpth+1);
			subtree[node] = subtree[node]+ subtree[adj[node][i]];
			other_end[index[node][i]]=adj[node][i];
			cst[adj[node][i]] = wt[node][i];
		}
	}
	subtree[node]+=1;
}

void hld(int cur,int cost,int prev)
{
	if(chainhead[chainno]==-1)
		chainhead[chainno] = cur;

	chainid[cur] = chainno;

	pos_base_array[cur]=ptr;   // pos array -> pos[node] will give position of the edge incident upon the node and pos[chainhead] =-1 as there is no edge incident upon the chainhead node
	base_array[ptr++]=cost;   //base array is holding all the chains(of edges in this case) and also the light edges..  
	                          //all the edges of a chain are present in contaguous positions in this array
	                      //this is beacuse the HLD starts at a chain and then traverses it till the leaf node.
	int mx=-1,id=-1;
	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && subtree[adj[cur][i]]>mx)
		{
			mx = subtree[adj[cur][i]];
			id = adj[cur][i];
			cost =wt[cur][i];
		}
	}
	
	if(id==-1)
		return;
	
	hld(id,cost,cur);

	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=prev && adj[cur][i]!=id)
		{
			chainno++;
			hld(adj[cur][i],wt[cur][i],cur);
		}
	}
}

//one seg tree is built upon the whole base array...(upon all the chains)
//query(u,v) is broken down to two paths: one from u to lca(u,v) and other v to lca(u,v)
//since lca(u,v) is present above the nodes u and v,we will be traversing both the paths from bottom to top of the tree
//in traversing u to lca(u,v) and v to lca(u,v),at most log2n chains will be changed..
//we can query the segtree chain wise only while moving up,to make sure that we are quering only those edges which are actually present in the path from u to lca(u,v)
//if the segtree is not queried chain wise ,then we may end up quering for the wrong set of edges
//this is because of the fact that base array is filled chain-wise!
// so for log2n queries ,complexity is O(log2n*log2n) for u to lca(u,v) and same for v to lca(u,v)
//query overall O(log2n*log2n)

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
	//printf("lca is %d\n",l);
	int x = query_up(u,l);
	int y = query_up(v,l);
	return x>y?x:y;
}