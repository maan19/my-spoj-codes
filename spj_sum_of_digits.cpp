#include<stdio.h>
#include<iostream>
using namespace std;

 long long int dp[100000000];

int main()
{
	
	for(int i=0;i<=10000000;i++)
	{
		dp[i+1]=dp[i];
		for(int j=i;j>0;j=j/10)
			  dp[i+1] = dp[i+1]  + (j%10);
	}

	printf("done\n");
	int a,b;
	scanf("%d""%d",&a,&b);

	while(a!=-1 && b!=-1)
	{

		if(a>10000000)
		{
			long long int sum=0;
			for(int i=a;i<=b;i++)
				for(int j=i;j>0;j=j/10)
					sum = sum + (j%10);
			printf("%lld\n",sum);
		}
		else
			printf("%lld\n",dp[b+1]-dp[a]);
		scanf("%d""%d",&a,&b);
	}
}


			
		

	