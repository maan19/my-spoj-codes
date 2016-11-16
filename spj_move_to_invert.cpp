#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);

	while(n--)
	{
		long long int k;
		scanf("%lld",&k);

		double m = k/2.0;

		unsigned long long int l = m * (k+1)/3;
		printf("%llu\n",l);

		
	}
}