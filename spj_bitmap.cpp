#include <iostream>
#include <cstdio>
#include <queue>
#include <limits.h>

using namespace std;

int data[182][182];
int n ,m,t;
void bfs(int i,int j);


int main()
{
	
	

	queue <int> Q;
	scanf("%d",&t);

	

	while(t--)
	{
		scanf("%d",&n);
	    scanf("%d",&m);
	    getchar();

	 for(int i =0;i<n;i++)
		{
			for(int j =0;j<m;j++)
		{
			char x;

			x= getchar();

			if(x=='1')
				{
					data[i][j]=0;
					Q.push(i);
					Q.push(j);
			   }
			else
				data[i][j]  = INT_MAX;
		}
			getchar();
	}

	

	while(!Q.empty())
	{
		int i = Q.front();
		Q.pop();
		int j = Q.front();
		Q.pop();

		bfs(i,j);

	
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",data[i][j]);
		}

		printf("\n");
	}
}

	return 0;
}





void bfs(int i,int j)
{
	queue <int> A;
	

	A.push(i);
	A.push(j);

	while(!A.empty())
	{
		i = A.front();
		A.pop();
		j=A.front();
		A.pop();

		if(i>0 && data[i-1][j]!=0 && (data[i-1][j] > data[i][j]+1))  //upper neighbour
		{
			data[i-1][j] = data[i][j]+1;
			A.push(i-1);
			A.push(j);
		}

		if(i!=n-1 && data[i+1][j] !=0 && (data[i+1][j] > data[i][j]+1))  //down
		{
			data[i+1][j] = data[i][j]+1;
			A.push(i+1);
			A.push(j);
		}

		if(j>0 && data[i][j-1] !=0 && (data[i][j-1] > data[i][j] +1))  //left
		{
			data[i][j-1] =data[i][j]+1;
			A.push(i);
			A.push(j-1);
		}

		if(j!=m-1 && data[i][j+1] !=0 && (data[i][j+1] > data[i][j] +1))  //right
		{
			data[i][j+1] = data[i][j]+1;
			A.push(i);
			A.push(j+1);
		}
	}
}








	

