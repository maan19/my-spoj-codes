#include<iostream>
#include<string.h>
using namespace std;
char b[255];
int remain(int a);
int gcd(int big,int small);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",b);
		if(a==0)
			{
				puts(b);
				continue;
		}

		printf("%d\n",gcd(a,remain(a)));


	
	}
	return 0;
}
			

int remain(int a)
{
	if(a == b[0]-'0')
	return 0;

	int rem=b[0]-'0',x;
		for(int i=0;i<strlen(b)-1;)
		{
			
			 x = rem;
	
			if(x<a)
			{
			while(x < a && i <strlen(b)-1)
			{
				x = x * 10 + (b[++i]-'0');
			}
			rem = x %a;
			}

			else
			{
				rem = x%a;
			}
		}
		return rem;
}

int gcd(int big,int small)
{
	if(small == 0)
		return big;

	return(gcd(small,big%small));
}


