#include<stdio.h>
#include<math.h>
char bin[1000000000];

int main()
{
	int t;
	scanf("%d",&t);
	
	
	while(t--)
	{
		int k, length,n,x=1,c=0;
		scanf("%d",&k);

		int i;
		for( i=1;c<k;i++)
		{
			x=  x*2;
			c = c +x;
		}

		length = i-1;
		n = x-(c-k);

		//printf("length %d and n is %d\n",length,n);

		int quo,rem,num=n-1,j=0;

		while(num!=0)
		{
			quo = num/2;
			rem   = num %2;
			bin[j++] = rem + '0';

			num = quo;
		}

		if(j<length)
		{
			while(j<length)
			{
				bin[j++] = '0';
			}
		}

		/*printf("bin has \n");
		for(int i=0;i<j;i++)
			printf("%c",bin[i]);
		printf("\n");*/

		for(int i=j-1;i>=0;i--)
		{
			if(bin[i]=='0')
				printf("%d",5);
			else
				printf("%d",6);
		}
		printf("\n");
	}
}

			


		

		











	





