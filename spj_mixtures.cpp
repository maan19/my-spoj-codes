#include<iostream>
#include<limits.h>

int clr[101];
unsigned long int smoke[101][101];
unsigned long int colour[101][101];

unsigned long int  mcm(int n);




int main()
{
	int n,t;
	
	
	while(scanf("%d",&n)!=EOF)
	{
	for(int i =1;i<=n;i++)
	{
		scanf("%d",&clr[i]);
	}

	printf("%lu\n",mcm(n));
	}

	return 0;


	

	


}

 unsigned long int  mcm(int n)
{
	for(int i=1;i<=n;i++)
	{
			smoke[i][i]=0;
			colour[i][i] = clr[i];
	}

	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=(n-l+1);i++)
		{
			int  j=l+i-1;
			smoke[i][j]=ULONG_MAX;

			unsigned long int count;

			for(int k=i;k<=j-1;k++)
			{
				 count = smoke[i][k] + smoke[k+1][j] + (colour[i][k]*colour[k+1][j]);
				 

				if(count<smoke[i][j])
				{
					smoke[i][j] = count;
					colour[i][j] = (colour[i][k] + colour[k+1][j]) %100;
				}

			}
			
		}
	}

	return smoke[1][n];
}


