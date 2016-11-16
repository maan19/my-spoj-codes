#include<stdio.h>
#include<iostream>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;
char data[55][55];
int visited[55][55];
int m,n,p=1;
int bfs(int i,int j);
int mx;


int main()
{
	cin>>m>>n;
	
	while(m!=0 && n!=0)
	{
		
		mx = 0;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
					cin>>data[i][j];
					visited[i][j]=0;
			}

		
		/*	printf("data\n");
		for(int i=0;i<m;i++)
		{
				for(int j=0;j<n;j++)
					printf("%c",data[i][j]);
				printf("\n");
		}*/


		for(int i=0;i<m;i++)
		{
				for(int j=0;j<n;j++)
			{
				if(data[i][j]=='A')
				{
						//printf("bfs on %c\n",data[i][j]);
						mx = max(bfs(i,j),mx);
				}
			}
		}
		
		printf("Case %d: %d\n",p++,mx);
		cin>>m>>n;
	}
}


int bfs(int k,int l)
{
	int level=1;
	queue<int> q;
	visited[k][l]=1;
	q.push(k);
	q.push(l);
	q.push(level);

	while(!(q.empty()))
	{
		int i,j;
		i=q.front();
		q.pop();
		j=q.front();
		q.pop();
		level = q.front();
		q.pop();

		if(i!=0 && visited[i-1][j]!=1 && data[i-1][j] == data[i][j] + 1)
		{
			q.push(i-1);q.push(j);q.push(level+1);
			visited[i-1][j]=1;
		}


		if(i!=m-1 && visited[i+1][j]!=1 && data[i+1][j] == data[i][j] +1)
		{
			q.push(i+1);q.push(j);q.push(level+1);
			visited[i+1][j]=1;
		}

		if(j!=0 && visited[i][j-1]!=1 && data[i][j-1] == data[i][j]+1)
		{
			q.push(i);q.push(j-1);q.push(level+1);
			visited[i][j-1]=1;
		}

		if(j!=n-1 && visited[i][j+1]!=1  && data[i][j+1] == data[i][j]+1)
		{
			q.push(i);q.push(j+1);q.push(level+1);
			visited[i][j+1]=1;
		}

		if(i!=0 && j!=0 && visited[i-1][j-1]!=1 && data[i-1][j-1] == data[i][j] +1)
		{
			q.push(i-1);q.push(j-1);q.push(level+1);
			visited[i-1][j-1]=1;
		}

		if(i!=m-1 && j!=0 && visited[i+1][j]!=1 && data[i+1][j-1] == data[i][j] +1)
		{
			q.push(i+1);q.push(j-1);q.push(level+1);
			visited[i+1][j-1]=1;
		}

		if(i!=0 && j!=n-1 && visited[i-1][j+1] !=1 && data[i-1][j+1]  == data[i][j]+1)
		{
			q.push(i-1);q.push(j+1);q.push(level+1);
			visited[i-1][j+1]=1;
		}

		if(i!=m-1 && j!= n-1 && visited[i+1][j+1] !=1 && data[i+1][j+1] == data[i][j]+1)
		{
			q.push(i+1);q.push(j+1);q.push(level+1);
			visited[i+1][j+1]=1;
		}
	}

	return level;
}







