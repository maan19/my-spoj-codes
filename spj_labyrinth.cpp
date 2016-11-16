
#include<stdio.h>
#include<queue>
using namespace std;

char maze[1002][1002];
long long int level[1002][1002];
int visited[1002][1002];
long long int bfs(int u,int v);

int row,col;
int s,t;


int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		
		scanf("%d""%d",&col,&row);

		getchar();
		int u,v;

		for(int i=0;i<row;i++)
		{
			gets(maze[i]);
		}

		/*for(int i=0;i<row;i++)
		{
				puts(maze[i]);
		}*/
		
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				{
					visited[i][j]=0;
					if(maze[i][j]=='.')
					{
						u=i;
						v=j;
					}
			}
		}

		bfs(u,v);
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				
				visited[i][j]=0;
			}
		}
		printf("Maximum rope length is %lld.\n",bfs(s,t));


	}
}

long long int bfs(int u,int v)
{
	queue<int>Q;
	visited[u][v]=1;
	level[u][v]=0;
	Q.push(u);
	Q.push(v);
	

	while(!Q.empty())
	{
		s = Q.front();
		Q.pop();

		t = Q.front();
		Q.pop();
		//printf("source %d %d\n",s,t);
		if(t+1 != col && maze[s][t+1]=='.' && visited[s][t+1]!=1)
		{
			visited[s][t+1]=1;
			Q.push(s);
			Q.push(t+1);
			level[s][t+1]=level[s][t]+1;
			
			//printf("level %d %d is %d\n",s,t+1,level[s][t+1]);
		}

		if(t!=0 && maze[s][t-1]=='.'&& visited[s][t-1]!=1)
		{
			visited[s][t-1]=1;
			Q.push(s);
			Q.push(t-1);
			level[s][t-1]=level[s][t]+1;
		
			//printf("level %d %d is %d\n",s,t-1,level[s][t-1]);
		}

		if(s+1 != row && maze[s+1][t]=='.' && visited[s+1][t] !=1)
		{
			visited[s+1][t] =1;
			Q.push(s+1);
			Q.push(t);
			level[s+1][t] = level[s][t] + 1;
			
			//printf("level %d %d is %d \n",s+1,t,level[s][t+1]);
		}

		if(s!=0 && maze[s-1][t]=='.' && visited[s-1][t]!=1)
		{
			visited[s-1][t] =1;
			Q.push(s-1);
			Q.push(t);
			level[s-1][t] = level[s][t] + 1;
			
			//printf("level %d %d is %d\n",s-1,t,level[s-1][t]);
		}
	}
	
	
		return level[s][t];
	
}







