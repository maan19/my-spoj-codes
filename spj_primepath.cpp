#include<iostream>
#include<queue>
#include<math.h>
int sieve[10000];
int visited[10000];
int parent[10000];
int rep[4];
int org[4];

using namespace std;

void make_sieve();
int bfs(int m,int n);


int main()
{
	int t;

	for(int i=0;i<10000;i++)
		sieve[i]=1;

	make_sieve();
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);

		for(int i=0;i<10000;i++)
		{
			visited[i]=0;
			parent[i]=-1;
		}

		int x=bfs(m,n);
		if(x==-1)
			printf("Impossible.\n");
		else
			printf("%d\n",x);

		 

	}
	return 0;
}

void make_sieve()
{
	for(int i=2;i<10000;i++)
	{
		if(sieve[i] == 1)
		{
			for(int j=i+1;j<10000;j++)
			{
				if(j%i==0)
					sieve[j]=0;
			}
		}
	}
	
}

int bfs(int m,int n)
{
	if(m==n)
		return 0;
	
	queue <int> q;
	q.push(m);
	visited[m]=1;
	parent[m]=m;
	int flag=1;

	while(!(q.empty())  && flag)
	{
		int src = q.front();
		int cpy = src;
		q.pop();

		for(int i=3;i>=0;i--)
		{
			rep[i] =org[i] =(cpy%10);
			cpy = cpy/10;
		}
		
		for(int i=0;i<4 && flag;i++)
		{
			rep[0]=org[0];
			rep[1] = org[1];
			rep[2]=org[2];
			rep[3]=org[3];

			for(int j=0;j<10 && flag;j++)
			{
				if(i==0 && j==0)
					j=1;
				rep[i] = j;
				int x=0;
				
				for(int i=0;i<4;i++)
					x = x + (rep[i] ) * pow(10.0,3-i);
				
				if(sieve[x] ==1 && visited[x] !=1)
				{
						q.push(x);
						visited[x] =1;
						parent[x] = src;
						
						if(x==n)
						{
							flag =0;
							
						}
				}
			}
		}
	}

	if(flag ==1)
		return -1;
    
	int count =0;
	for(int i=n; i!=m;)
	{
		
		count ++;
		i=parent[i];
	}
	
	return count;
}


