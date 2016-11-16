#include<stdio.h>
#include<algorithm>
using namespace std;
int data[1008];
int memo[1008][1008];
int f_max(int s,int e);
int main()
{
	int n,t=1;
	scanf("%d",&n);

	while(n!=0)
	{

	long long int sum =0;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			memo[i][j]=-1;
	
	for(int i=0;i<n;i++)
	{
			scanf("%d",&data[i]);
			sum = sum + data[i];
	}
	int k =f_max(0,n-1);
	printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t++,k-(sum-k));
	scanf("%d",&n);
	}


}

int f_max(int s,int e)
{
	if(s>=e)
		return 0;
	if(memo[s][e]!=-1)
		return memo[s][e];
	int x = data[s+1] >= data[e]?f_max(s+2,e):f_max(s+1,e-1);
	int y = data[s]  >= data[e-1]?f_max(s+1,e-1):f_max(s,e-2);

	return memo[s][e]=max(x + data[s] , y+data[e]);
}