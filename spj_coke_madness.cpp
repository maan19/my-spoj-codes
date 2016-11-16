#include<stdio.h>


int main()
{
	int t,j=1;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		long long int h=0,power=0;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			h = h + k;
			if(h<1)
			{
				
				power = power +  1 - (h);
				h=1;
			}
		}
		if(power>0)
			printf("Scenario #%d: %lld\n",j++,power);
		else
			printf("Scenario #%d: %d\n",j++,1);
	}

}