#include<stdio.h>
#include<algorithm>
using namespace std;
int fun(int h,int a,int m);
int memo[1500][1500];
int air[1500][1500];
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int h,a;
		scanf("%d""%d",&h,&a);
		
		for(int i=0;i<1500;i++)
			for(int j=0;j<1500;j++)
				{
					memo[i][j]=-1;
					air[i][j]=-1;
			}
		
		printf("%d\n",fun(h,a,0)-1);

	}
}

int fun(int h,int a,int m)
{
	if(h<=0||a<=0)
		return 0;

	if((m==2 || m==3 ) && memo[h][a]!=-1)
	{
			return memo[h][a];
	}

	if(m==1 && air[h][a]!=-1)
		return air[h][a];

	int x=0,y=0,z=0;
	if(m!=1)
		x=fun(h+3,a+2,1);
	if(m!=2)
		y=fun(h-5,a-10,2);
	if(m!=3)
		z=fun(h-20,a+5,3);

	int ans= 1 + max(max(x,y),z);

	if(m==2||m==3)
	{
			memo[h][a]=ans;
	}

	if(m==1)
		air[h][a] = ans;
	return ans;
}