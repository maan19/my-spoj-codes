#include<iostream>
unsigned long long int m =0;
long int money[10003];
unsigned long long int memo[2][10003];

unsigned long long int  max(int start,int end,int flag);

int main()
{
	int n,t,i=1;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);

		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
				memo[i][j]=-1;
		}
	

	
	
	

	for(int i=0;i<n;i++)
	{
		scanf("%ld",&money[i]);
	}

	;
	printf("Case %d: %llu\n",i,max(0,n-1,0));
	i++;
	}


}

unsigned long long int  max(int start,int end,int flag)
{
	unsigned long long int x=0,y=0;  
	if(start > end)
	{
		
		return 0;
	}

	if(memo[flag][start]!=-1)
		return memo[flag][start];
		

	if(!flag)    
		x=max(start+1,end,1) + money[start];
	y=max(start+1,end,0);



	return(memo[flag][start] =(x>y?x:y));
}
