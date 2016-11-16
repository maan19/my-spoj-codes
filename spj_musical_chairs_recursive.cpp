#include<stdio.h>
int f(int n,int k);
int main()
{
	int n,d;
	scanf("%d""%d",&n,&d);

	while(!(n==0 && d==0))
	{
		printf("%d %d %d\n",n,d,(f(n,d)+1)%n);
		scanf("%d""%d",&n,&d);
	}

			
	
	
}

int f(int n,int k)
{
	if(n==1)
		return 0;
	return (f(n-1,k) + k%n)%n;
}