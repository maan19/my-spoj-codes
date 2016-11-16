#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

char x[500018];
char y[500018];

bool predicate(int m);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",x);
		scanf("%s",y);

	
	int low =0,high =500020,mid;

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
}

bool predicate(int m)
{
	int cnt=0,a=strlen(x),b=strlen(y),resume=-1;

	if(m>b)
		return false;

	for(int i=0;i<a;i++)
	{
		cnt=0;
		for(int j=resume+1;j<b && cnt!=m;j++)
		{
			if(y[j]==x[i])
				cnt++;
			resume = j;
		}

		if(cnt!=m)
			return false;
		
	}
	return true;
}



