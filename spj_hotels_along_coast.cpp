#include<iostream>

int hotel[300001];

int main()
{
	int n;
	unsigned  int m;
    long long int sum,max=-1;

	scanf("%d",&n);
	scanf("%u",&m);

	for(int i=1;i<=n;i++)
		scanf("%d",&hotel[i]);
	
	int j=1;
	sum =0;
	

	for(int i=1;i<=n;i++)
	{
		for(;j<=n && (sum + hotel[j] <=m);j++)
		{
				sum = sum + hotel[j];
			
				
		}

		max = sum>max?sum:max;

		sum = sum - hotel[i];
		
	}

	printf("%lld\n",max);
	return 0;
}






