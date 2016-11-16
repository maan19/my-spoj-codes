#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
#define N 10100
#define LGN 14
using namespace std;



vector< vector<pair<int,int> > > g (N);
vector<int> index[N];

int depth[N];
int other_end[N];
int subtree[N];
int chainhead[N];
int chainid[N];
int base_array[N];
int pos_base_array[N];
int seg_tree[6*N];
int parent[15][N];
char a[15];

int chainno,ptr;
void dfs(int node,int prnt,int dpth);
void hld(int cur,int cost,int prev);
void build_tree(int i,int s,int e);
int  query_tree(int i,int s,int e,int qs,int qe);
void update_tree(int i,int s,int e,int us,int val);
int lca(int u,int v);
int query_up(int u,int v);
int query(int u,int v);


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int nod;
		scanf("%d",&nod);
		printf("n is %d\n",nod);
		
		ptr=0;chainno=0;
		
		for(int i=1;i<nod;i++)
		{
			printf("scn\n");
			int u,v,w;
			scanf("%d""%d""%d",&u,&v,&w);
			g[u].push_back(make_pair(v,w));
			index[u].push_back(i);
			g[v].push_back(make_pair(u,w));
			index[v].push_back(i);
		}

		for(int i=0;i<LGN;i++)
			for(int j=0;j<=nod;j++)
				parent[i][j]=-1;

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
			printf("....\n");
		}

		

		hld(1,-1,-1);

		for(int i=0;i<ptr;i++)
			printf("%d\n",base_array[i]);

		build_tree(1,0,ptr-1);
		/*printf("tree\n");
		for(int i=0;i<64;i++)
			printf("%d\n",seg_tree[i]);*/

		scanf("%s",a);
		int u,v;
		
		while(a[0]!='D')
		{
		if(a[0]=='Q'){
			scanf("%d""%d",&u,&v);
			printf("%d\n",query(u,v));}
		else if(a[0]=='C'){
			scanf("%d""%d",&u,&v);
			update_tree(1,0,ptr-1,pos_base_array[other_end[u]],v);
		}
		scanf("%s",a);
		}
	}
}


void dfs(int node,int prnt,int dpth)
{
	printf("dfs\n");
	depth[node] = dpth;
	parent[0][node] = prnt;
	subtree[node]=0;

	for(int i=0;i<g[node].size();i++){
		if(depth[g[node][i].first]==-1)
		{
			dfs(g[node][i].first,node,dpth+1);
			subtree[node] = subtree[node]+ subtree[g[node][i].first];
			other_end[index[node][i]]=g[node][i].first;
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
	for(int i=0;i<g[cur].size();i++)
	{
		if(g[cur][i].first!=prev && subtree[g[cur][i].first]>mx)
		{
			mx = subtree[g[cur][i].first];
			id = g[cur][i].first;
			cost =g[cur][i].second;
		}
	}
	
	if(id==-1)
		return;
	
	hld(id,cost,cur);

	for(int i=0;i<g[cur].size();i++)
	{
		if(g[cur][i].first!=prev && g[cur][i].first!=id){
			chainno++;
			hld(g[cur][i].first,g[cur][i].second,cur);
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

int query_up(int u,int v)
{
	if(u==v)
		return 0;
	int uchain = chainid[u];
	int vchain = chainid[v];
	int ans=-1,cur=-1;
	while(1)
	{
		if(uchain==vchain)
		{
			if(u==v)
				break;
			ans = query_tree(1,0,ptr-1,pos_base_array[v]+1,pos_base_array[u]);
			cur = cur>ans?cur:ans;
			break;
		}

		ans =query_tree(1,0,ptr-1,pos_base_array[chainhead[uchain]],pos_base_array[u]);
		cur = ans>cur?ans:cur;
		u = parent[0][chainhead[uchain]];
		uchain= chainid[u];
	}
	return cur;
}


int query(int u,int v)
{
	int l = lca(u,v);
	printf("lca %d\n",l);
	int x =query_up(u,l);
	printf("x is %d\n",x);
	int y =query_up(v,l);
	printf("y is %d\n",y);
	return x>y?x:y;
}







	 





		









