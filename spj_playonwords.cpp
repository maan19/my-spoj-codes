#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
char plate[1009];
int mtx[27][27];
int ideg[27];
int odeg[27];
int nodes[27];
int np[27];
int hlp[27];
int visited[27];
int num=0;

int check_deg();
int bfs_cycle();
int bfs_trail();

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,len;
		scanf("%d",&n);

		for(int i =0;i<27;i++)
		{
			ideg[i]=odeg[i]=nodes[i]=visited[i]=np[i]=0;
		}

		for(int i=0;i<27;i++)
			for(int j=0;j<27;j++)
				mtx[i][j]=0;

		
		for(int i=1;i<=n;i++)
		{
				scanf("%s",plate);
				len = strlen(plate);
				mtx[plate[0]-'a'][plate[len-1]-'a']+=1;
				ideg[plate[len-1]-'a']+=1;
				odeg[plate[0]-'a']+=1;
				nodes[plate[0]-'a'] = nodes[plate[len-1]-'a'] = 1;
		}

		num =0;
		for(int i =0;i<27;i++)
		{
			if(nodes[i])
				{
					//printf("ideg odeg of  %d is %d %d\n",i,ideg[i],odeg[i]);
					np[num++]=i;
			}
		}

		//printf("nodes\n");

		/*for(int i=0;i<num;i++)
			printf("%d\n",np[i]);*/
			


		int x=check_deg();
		if(x==-1)
			{
				//printf("not met\n");
				printf("The door cannot be opened.\n");
		}
		else if(x==1)
		{
			//printf("cycle\n");
			if(bfs_cycle())
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
		}

		else
		{
			//printf("trail\n");
			if(bfs_trail())
				printf("Ordering is possible.\n");
			else
				printf("The door cannot be opened.\n");
		}

		}
}




	



int check_deg()
{
	int cnt =0;
	for(int i=0,j=0;i<num;i++)
	{
		//printf("ideg %d odeg %d \n",ideg[np[i]],odeg[np[i]]);
	
		
			if(ideg[np[i]]==odeg[np[i]]){}

			else
			{
				cnt++;
				hlp[j++] = ideg[np[i]]-odeg[np[i]];
			}
		
	}

	//printf("count %d\n",cnt);

	if(!cnt)
		return 1;
	else if(cnt !=2)
		return -1;
	else
		return ((hlp[0]==-1 && hlp[1]==1 || hlp[0]==1 && hlp[1]==-1)? 0: -1);
}

int bfs_cycle()
{
	queue <int> q;
	q.push(np[0]);
	visited[np[0]]=1;

	while(!q.empty())
	{
		int src = q.front();
		q.pop();

		for(int i=0;i<num;i++)
		{
			if(mtx[src][np[i]]&& visited[np[i]]==0)
			{
				q.push(np[i]);
				visited[np[i]]+=1;
			}
		}
	}

	q.push(np[0]);
	visited[np[0]]+=1;

	while(!q.empty())
	{
		int src = q.front();
		q.pop();


		for(int i=0;i<num;i++)
		{
			if(mtx[np[i]][src] && visited[np[i]]==1)
			{
				q.push(np[i]);
				visited[np[i]]+=1;
			}
		}

	}

	for(int i=0;i<num;i++)
	{
		if(visited[np[i]]!=2)
			return 0;
	}

	//printf("strongly connected\n");

	return 1;
}

int bfs_trail()
{
	queue<int> q;

	q.push(np[0]);
	visited[np[0]]=1;

	while(!q.empty())
	{
		int src = q.front();
		q.pop();

		for(int i=0;i<num;i++)
		{
			if((mtx[src][np[i]] || mtx[np[i]][src]) && visited[np[i]]==0)
			{
				q.push(np[i]);
				visited[np[i]]=1;
			}
		}
	}

	for(int i=0;i<num;i++)
	{
		if(!visited[np[i]])
			return 0;
	}
	//printf("connected\n");
	return 1;
}





			
	  






		






				





