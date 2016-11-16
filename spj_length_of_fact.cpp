#include<stdio.h>
#include<math.h>
#define pi 3.14

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		 if(n==1||n==2||n==0)
			 printf("1/n");
		 else
			 printf("%lld\n",(long long int)floor((log(2*acos(-1)*n)/2+n*(log(n)-1))/log(10))+1);
		 
	}
}

