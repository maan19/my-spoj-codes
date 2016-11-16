#include<stdio.h>



int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		int * p = new int [n];

		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);

		unsigned long long int count =1,max=0;

		for(int i=1;i<n;i++)
		{
			if(p[max] != p[i])
				count--;

			else 
				count++;

			if(count ==0)
			{
				count =1;
				max =i;
			}
		}
		count =0;
		for(int i=0;i<n;i++)
		{
			if(p[i]==p[max])
				count++;
		}

		if(count >n/2)
			printf("YES %d\n\n",p[max]);
		else
			printf("NO\n\n");
	}

	return 0;
}
			


