#include<stdio.h>

int main()
{
	int n;
	unsigned long long int count;
	scanf("%d",&n);

	while(n!=0)
	{
		count=0;
		for(int i=1;n>1;i++)
		{
			n=n/2;
			count++;
		}

		printf("%llu\n",count);
		scanf("%d",&n);
	}
	return 0;

}