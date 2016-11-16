#include<iostream>
#include<limits.h>

int value[600];
int weight[600];
unsigned  long int memo[10050];
unsigned long int sol[600];
int n;
unsigned long  int mx(int cap);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{

	int E,F;
	scanf("%d" "%d",&E,&F);

	
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d %d",&value[i],&weight[i]);

	for(int i=0;i<=F-E;i++)
		memo[i]=-1;
	
	unsigned long  int d =mx(F-E);



	if(d==ULONG_MAX)
		printf("This is impossible.\n");
	else
	printf("The minimum amount of money in the piggy-bank is %lu.\n",d);
	}
	return 0;

}


 unsigned long int mx(int cap)
{
	
	

	if(cap==0)
		return 0;
	 
	 unsigned long int max =ULONG_MAX;

	if(memo[cap] !=-1)
	{
	
		return memo[cap];
	}

	for(int i=0;i<n ;i++)
	{
		if(cap<weight[i])
			sol[i] =ULONG_MAX;
	
		else
			{
				sol[i] = mx(cap-weight[i]);
				if(sol[i]!=ULONG_MAX)
					sol[i] = sol[i] + value[i];
		}

		max =  sol[i] < max?sol[i]:max;
		
	}
	return (memo[cap] =max);
}


