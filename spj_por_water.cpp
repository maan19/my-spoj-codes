#include<stdio.h>

char visited[40001][40001];
  
int a,b,c;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d""%d""%d",&a,&b,&c);
		for(int i=0;i<=a;i++)
		{
			for(int j=0;j<=b;j++)
				visited[i][j]='a';
		}

	}
}


int solve(int x, int y)
{
	if(x==c||y==c)
		return 0;

	if(visited[x][y]!='a')
		return visited[x][y]-'0';
}
