#include<stdio.h>
#include<iostream>
using namespace std;



int main()
{
	int t;
	scanf("%d",&t);


	while(t--)
	{
		unsigned long long  int n;
		scanf("%llu",&n);
		
		if(n==1||n==2)
			printf("%llu\n",1);

		else if(n%2==0)
		{
			if((n/2)%2==0)
				printf("%llu\n",(n/2)-1);
			else
				printf("%llu\n",(n/2)-2);
		}
			
		else
			printf("%llu\n",n/2);
	}
	
}