#include<iostream>

using namespace std;
int sieve[1000008];
int factors[1000001];
void make_sieve();

int main()
{
	

	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		int result = n;
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
				result -= (result/i);

			while(n%i==0)
				n/=i;
		}

		if(n>1)
			result -= (result/n);
		printf("%d\n",result);

	}
	return 0;
}









