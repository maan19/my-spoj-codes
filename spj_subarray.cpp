#include<iostream>
#include<limits.h>
int arr[1000000];
int main()
{
	int n,k,max=INT_MIN;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	scanf("%d",&k);

	for(int i=0;i + k<=n;i++)
	{
		max= INT_MIN;
		for(int j=0;j<k;j++)
		{
			max = arr[i+j] > max?arr[i+j]:max;
		}
		printf("%d",max);
		if(!(i+k==n))
			printf(" ");

	}

	return 0;
}


