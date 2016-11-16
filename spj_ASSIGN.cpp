#include<stdio.h>
#include<iostream>

using namespace std;

int data[25][25];
long long int memo[21][1048580];


long long int f(int s,int t);
int n;
int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&data[i][j]);
		/*cout<<"data\n";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cout<<data[i][j] <<" "<<endl;*/
		

		

		for(int i=0;i<=n;i++)
			for(int j=0;j<=(1<<n);j++)
				memo[i][j]=-1;

		printf("%lld\n",f(0,(1<<n)-1));

		
	}  
}

long long  f(int s,int t) 
{
	if(s==n)
		return 1;
	if(memo[s][t]!=-1)
		return memo[s][t];

	
	long long int x=0;
	for(int i=0;i<n;i++)
	{
		if(data[s][i]==1 && ((t >> ((n-1)-i))&1))
		{
			x = x +f(s+1,t &(~(1<<((n-1)-i))));
		}
	}

	return memo[s][t]= x;
}
  

    



