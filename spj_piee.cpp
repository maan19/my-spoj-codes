#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define PIE 3.14159265358979323846264338327950
long double pie[20009];
int N,F,r;

long double bin_srch();

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d %d",&N,&F);
		F=F+1;

		for(int i=0;i<N;i++)
		{
			scanf("%d",&r);
			pie[i]=r*r*PIE;

		}

		sort(pie,pie+N);
		long double x =bin_srch();
		printf("%.4Lf\n",x);
	}
}

long double bin_srch()
{
	long double low=0,high=pie[N-1],mid;
	int c=0,x,cnt=1;

	while(high-low>=1e-6)
	{
		 mid = (low+high)/2;
		 c=0;

		for(int i=0;i<N;i++)
		{
			x = pie[i]/mid;
			c = c+x;
			if(c>=F)
				break;
		}

		if(c>=F)
			low = mid;
		else
			high = mid;
		
	}

	return low;
}

