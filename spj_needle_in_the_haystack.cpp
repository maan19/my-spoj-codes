#include<iostream>
#include<string.h>


char text[5000000];
char pattern[5000000];



int int_mod(int a, int b);
void rabin();

int main()
{
	int n;

	        
	
	while(scanf("%d",&n)!=EOF)
	{
	getchar();

	scanf("%s",pattern);
	getchar();

	scanf("%s",text);
	getchar();

	rabin();
	printf("\n");
	}


	
	


	
}

int int_mod(int a, int b)
{
	return ((a%b) + b)%b;
}

void rabin()
{
	int n = strlen(text);
	int m =strlen(pattern);
	int B =256;

	int M=101;

	if(n<m)
	{
		printf("\n");
		return;
	}

	int hp=0;

	for(int i=0;i<m;i++)
		hp = int_mod((hp * B) +pattern[i],M);
	
	int ht =0;

	for(int i=0;i<m;i++)
		ht = int_mod((ht*B)+text[i] , M);
	
	int j;
	if(hp==ht)
	{
		for( j = 0;j<m;j++)
		{
			if(pattern[j] != text[j])
				break;
		}
	

	if(j==m)
		printf("%d\n",0);
	}
	int E=1;

	for(int i=0;i<m-1;i++)
		E=(E*B)%M;  

	for(int i=m;i<n;i++)
	{
		ht = int_mod(ht-int_mod(text[i-m]*E,M),M);
		ht = int_mod(ht*B,M);
		ht = int_mod(ht+text[i],M);

		if(ht==hp)
		{
			int k=i-(m-1);
			int j;
			for(j=0;j<m;j++,k++)
			{
				if(pattern[j] != text[k])
					break;
			}
			

			if(j==m)
				printf("%d\n",i-(m-1));
			
		}
	}
}
		

		







