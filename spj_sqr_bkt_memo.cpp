#include<stdio.h>
#include<unordered_set>


using namespace std;
int f(int i,int j);
int memo[40][40];
unordered_set<int> m;
int main()
{
	int t;
	scanf("%d",&t);
	

	while(t--)
	{
		int n,k;
		scanf("%d""%d",&n,&k);
		m.clear();
		for(int i=0;i<k;i++)
		{
			int d;
			scanf("%d",&d);
			m.insert(d);
		}

		for(int i=0;i<40;i++)
		{
			for(int j=0;j<40;j++)
				memo[i][j]=-1;
		}

		printf("%d\n",f(2*n,0));
	}



}

int f(int i,int j)
{
	if(i==j)
		return 1;
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(m.find(i)!=m.end())
	{
		if(j==0)
			return memo[i][j]=0;
		else
			return memo[i][j] =f(i-1,j-1);
	}

	else
	{
		if(j==0)
			return memo[i][j]=f(i-1,1);
		else
			return memo[i][j] = f(i-1,j-1) + f(i-1,j+1);
	}
}

