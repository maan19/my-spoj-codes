#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int gcd(int a,int b);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,m;

		scanf("%d %d",&n,&m);
		int x= min(m,n);
		int y=max(m,n);
		int g=gcd(y,x);
		int N= (int) sqrt((float)g);
		int ans=0;
		
		for(int i=1;i<=N;i++)
		{
			if(g%i==0)
				ans +=2;
			if(i*i==g)
				ans--;
			
		}

		

		


		printf("%d\n",ans);

		

	}
	return 0;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}