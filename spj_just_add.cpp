#include<stdio.h>
#define m  10000007

unsigned long long int s_mod (unsigned long long int n,int k);

int main()
{
	unsigned long long int n;
	int k;
	
	scanf("%llu""%d",&n,&k);

	while(!( n==0 && k==0))
	{
		printf("%llu\n",((s_mod(n-1,k)*2)%m + s_mod(n,k) + (2*(s_mod(n-1,n-1)))%m  + s_mod(n,n))%m);
		scanf("%llu""%d",&n,&k);
	}
}


unsigned long long int s_mod(unsigned long long int n,int k)
{
	if(k==0)
		return 1%m;
	if(n==0)
		return 0;
	

	if (k%2!=0)
	{
		return (n%m * s_mod(n,k-1))%m;
	}

	else
	{
		unsigned long long int x;
		x = s_mod(n,k/2);
		return (x*x)%m;
	}

}


	

