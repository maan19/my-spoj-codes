#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define MAX 100009
int parent[MAX];
int leaf[MAX];
int vertex[MAX];
vector<vector<int>> g(MAX);

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<MAX;i++)
	{
		parent[i]=0;
		leaf[i]=1;
	}

	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d""%d",&u,&v);
		g[u].push_back(v);
		leaf[u]=0;
	}

	/*printf("leaf nodes\n");
	for(int i=1;i<=n;i++)
	{
		if(leaf[i]==1)
			printf("%d\  ",i);
	}
	printf("\n");*/

	for(int i=1;i<=n;i++)
	{
		if(leaf[i]==0)
		{
			for(int j=0;j<g[i].size();j++)
			{
				if(leaf[g[i][j]]==1)
				{
					parent[i]=1;
					break;
				}
			}
		}
	}


	/*printf("marked nodes\n");
	for(int i=1;i<=n;i++)
	{
		if(parent[i]==1)
			printf("%d ",i);
	}

	printf("\n");*/
		
	int k=0;
	for(int i=1;i<=n;i++)
	{
		if(leaf[i]==0)
		{
			for(int j=0;j<g[i].size();j++)
			{
				if(parent[g[i][j]]==0)
					{
						vertex[k++]=i;
						break;
						printf("%d ",i);
				}
			}
		}
	}
	
	printf("%d\n",k);

	for(int i=1;i<=n;i++)
		g[i].clear();
}

