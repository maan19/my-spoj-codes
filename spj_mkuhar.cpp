#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

struct node
{
	int req,pre,s,ps,l,pl;
};

int n,m;
node ing[101];

bool predicate(int meal);


int main()
{
	scanf("%d""%d",&n,&m);

	for(int i=0;i<n;i++)
		scanf("%d""%d""%d""%d""%d""%d",&ing[i].req,&ing[i].pre,&ing[i].s,&ing[i].ps,&ing[i].l,&ing[i].pl);

	int lo=0,hi=100000,mid;

	while(lo < hi)
	{
		 mid = lo + (hi-lo+1)/2;

		if(predicate(mid))
			lo = mid;
		else
			hi = mid-1;
	}
	
	printf("%d\n",lo);
}


bool predicate(int meal)
{
	int cost =0;
	//printf("meals %d\n",meal);
	for(int i=0;i<n;i++)
	{
		int need = meal*ing[i].req - ing[i].pre,mn = INT_MAX,large=1,more;
		for(int j = 0;large;j++)
		{
		    int x = need - ing[i].s*j;
			more = x<0?0:x;
			large = more%ing[i].l==0?more/ing[i].l:(more/ing[i].l)+1;
			mn = min(ing[i].ps*j+ing[i].pl*large,mn);
		}
		//printf("%d %d\n",i+1,mn);
		cost +=mn;
		if(cost>m)
			return false;
	}
	//printf("cost %d\n",cost);
	return cost <=m;

}
			







