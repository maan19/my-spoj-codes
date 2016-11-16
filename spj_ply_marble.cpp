#include<stdio.h>

int main()
{
	int n;

	unsigned long long int prev;
	unsigned long long int total=12,nw;

	
	scanf("%d",&n);
	
	while(n!=0)
	{

	prev = 5;
	for(int i=2;i<=n;i++)
	{
		nw = 3 * i + 1;
		total = nw + prev;
		prev = total;

	}
	if(n==1)
		printf("%d\n",5);
	
	else
		printf("%llu\n",total);
	scanf("%d",&n);
	}
}