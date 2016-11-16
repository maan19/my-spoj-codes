#include<iostream>
#include<limits>

using namespace std;


 long int treat[2001];
 long int memo[2001][2001];
 
 



 long int fun( long int front,long int end,long int n);


int main()
{
	 long int n ,i;
	 long int x=0,y=0;
	 
	 scanf("%ld",&n);


	


	for( i=0;i<n;i++)
	{
		scanf("%ld",&treat[i]);
		
	}

	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=n;k++)
			memo[j][k]=-1;
	}




	
	

	printf("%ld\n",fun(0,n-1,n));
	return 0;
}

long int fun(long int front,long int end,long int n)
{
	long int x=0,y=0;
	
	
	if(front > end)
	{
		return 0;
	}

	if(memo[front][end] !=-1)
		return memo[front][end];

	

	x=fun(front+1,end,n) + (n-(end-front+1)+1) * treat[front];
	y=fun(front,end-1,n) + (n-(end-front+1)+1)*treat[end];

	return ( memo[front][end] =(x>y?x:y));


}


