#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;


struct node
{
	int a,b;
};



node m1[102];
node m2[102];
int M1[102];
int M2[102];

int n,m,T,t;

bool predicate(int mid);
int main()
{
	
	scanf("%d",&T);
	
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		scanf("%d""%d",&m1[i].a,&m1[i].b);

	scanf("%d",&m);

	for(int i=1;i<=m;i++)
		scanf("%d""%d",&m2[i].a,&m2[i].b);

	int low=0,high=1000000000,mid;

	while(low<high)
	{
		mid = low + (high-low+1)/2;

		if(predicate(mid))
			low = mid;
		else
			high = mid-1;
	}

	printf("%d\n",low);
}


bool predicate( int t)
{
	long long int coco=0,coco2=0;

	for(int i=1;i<=n;i++)
	{
		if(t>=m1[i].a)
		{
		coco++;
		coco += (long long int) (t-m1[i].a)/m1[i].b;
		}
	}

	for(int i=1;i<=m;i++)
	{
		if((T-t)>=m2[i].a)
		{
			coco2++;
			coco2 += (long long int)((T-t)-m2[i].a)/m2[i].b;
		}
	}

	return coco<=coco2;
}






	