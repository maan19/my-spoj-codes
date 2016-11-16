#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
#include<string.h>

using namespace std;


#define sid(n) scanf("%d",&n)
#define sis(n) scanf("%s",n)
#define dout(n) printf("%d",n)
#define sil(n) scanf("%lld",&n)
#define lout(n) printf("%lld",n)
#define FOR(n) for(int i=1;i<=n;i++)

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int,int> PII;

using namespace std;
struct node
{
	int l;
	char a[3];
};

node tgt,src;

int visited[10][10];
int bfs();


int main()
{
	int t;
	sid(t);
	while(t--)
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				visited[i][j]=0;
		sis(src.a);
		sis(tgt.a);
		if(strcmp(src.a,tgt.a)==0)
			printf("%d\n",0);
		else
			printf("%d\n",bfs());
	}
}

int bfs()
{
	queue<node> q;
	src.l=0;
	q.push(src);
	visited[src.a[0]-'a'][src.a[1]-'0']=1;
	while(!q.empty())
	{
		node s=q.front();
		q.pop();
		node n[9];
		n[1].l=n[2].l=n[3].l=n[4].l=n[5].l=n[6].l=n[7].l=n[8].l=s.l+1;
		n[1].a[0]=s.a[0]+1;n[1].a[1]=s.a[1]+2;n[1].a[2]=NULL;
		n[2].a[0]=s.a[0]+1;n[2].a[1]=s.a[1]-2;n[2].a[2]=NULL;
		n[3].a[0]=s.a[0]+2;n[3].a[1]=s.a[1]+1;n[3].a[2]=NULL;
		n[4].a[0]=s.a[0]+2;n[4].a[1]=s.a[1]-1;n[4].a[2]=NULL;
		n[5].a[0]=s.a[0]-1;n[5].a[1]=s.a[1]+2;n[5].a[2]=NULL;
		n[6].a[0]=s.a[0]-1;n[6].a[1]=s.a[1]-2;n[6].a[2]=NULL;
		n[7].a[0]=s.a[0]-2;n[7].a[1]=s.a[1]+1;n[7].a[2]=NULL;
		n[8].a[0]=s.a[0]-2;n[8].a[1]=s.a[1]-1;n[8].a[2]=NULL;

		FOR(8)
		{
			if(!visited[n[i].a[0]-'a'][n[i].a[1]-'0'] && (n[i].a[0]>='a' && n[i].a[0]<='h') && (n[i].a[1]>='1' && n[i].a[1]<='8'))
			{
				if(strcmp(n[i].a,tgt.a)==0)
				{
						//printf("target %s reached at level %d\n",n[i].a,n[i].l);
						return n[i].l;
				}
				visited[n[i].a[0]-'a'][n[i].a[1]-'0']=1;
				//printf("neigh is %s at level %d\n",n[i].a,n[i].l);
				q.push(n[i]);
			}
		}
	}
	//printf("queue empty\n");
}
				




		

	
