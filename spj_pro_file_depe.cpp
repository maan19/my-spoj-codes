#include<stdio.h>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int m,n;
int id[103];

vector<vector<int>> g(101);
set<int> S;

int main()
{

	scanf("%d""%d",&n,&m);

	for(int i=1;i<=n;i++)
		id[i]=0;

	int v,k,u;

	for(int j=1;j<=m;j++)
	{
		scanf("%d""%d",&v,&k);
		id[v]=k;
		
		for(int i=0;i<k;i++)
		{
			scanf("%d",&u);
			g[u].push_back(v);
		}
	}

	
	for(int i=1;i<=n;i++)
		if(id[i]==0)
				S.insert(i);
	
	while(!S.empty())
	{
		set<int> ::iterator it = S.begin();
		printf("%d ",*it);
		int p =*it;
		S.erase(*it);
		
		

		for(int i=0;i<g[p].size();i++)
		{
			id[g[p][i]]--;
			if(id[g[p][i]]==0)
			{
				S.insert(g[p][i]);
			}
				
		}

		
	}


	
	
	return 0;
}


	