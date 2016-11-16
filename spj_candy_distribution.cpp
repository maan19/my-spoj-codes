#include<stdio.h>
#include<algorithm>
using namespace std;
unsigned long long int s[100010];
unsigned long long int c[100010];
unsigned long long int myfun(unsigned long long int i,unsigned long long int j)
{
	return i>j;
}

int main()
{
	unsigned long long int n;
	unsigned long long int m;
	scanf("%llu",&n);

	while(n!=0)
	{
		m=0;
		for(int i=0;i<n;i++)
			scanf("%llu",&s[i]);
		for(int i=0;i<n;i++)
			scanf("%llu",&c[i]);

		sort(c,c+n);
		sort(s,s+n,myfun);

		/*for(int i=0;i<n;i++)
			printf("%d ",c[i]);

		printf("\n");

		for(int i=0;i<n;i++)
			printf("%d ",s[i]);*/

		for(int i=0;i<n;i++)
		{
			m =  m + s[i]*c[i];
		}

		printf("%llu\n",m);
		scanf("%llu",&n);
	}
}






