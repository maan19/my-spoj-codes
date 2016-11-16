#include<stdio.h>

int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		int n,k,t,f;
		scanf("%d""%d""%d""%d",&n,&k,&t,&f);
		printf("%lld\n",(((f-n)/(k-1))*k)+n);
	}
}