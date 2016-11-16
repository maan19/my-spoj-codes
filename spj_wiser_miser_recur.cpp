#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int rec[102][102];
int memo[102][102];
int n,m;
int fun_min(int city,int bus);
int main()
{
	scanf("%d" "%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			{
				scanf("%d",&rec[i][j]);
				memo[i][j]=-1;
		}
	}


	int mini = INT_MAX;
	for(int i=0;i<m;i++)
	{
		

		mini = min(fun_min(0,i),mini);
	}

	printf("%d\n",mini);


}

int fun_min(int city,int bus)
{
	if(city == n-1)
		return rec[city][bus];

	if(memo[city][bus]!=-1)
		return memo[city][bus];


	int x,y,z;
	x=y=z=INT_MAX;

	if(bus!=0)
		x=fun_min(city+1,bus-1);
	
	y=fun_min(city + 1,bus);
	
	if(bus!=m-1)
			z=fun_min(city + 1,bus+1);
		
	return (memo[city][bus]=min(min(x,y),z) + rec[city][bus]);
	
}
