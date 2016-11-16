#include<stdio.h>
#include <algorithm>
using namespace std;
long long int max_path(int * p,int *q,int m,int n);


int main()
{
	int m,n;
	scanf("%d",&m);

	while(m!=0)
	{

	int * p = new int [m];

	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);

	scanf("%d",&n);

	int * q = new int [n];

	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);

	printf("%lld\n",max_path(p,q,m,n));
	scanf("%d",&m);

	}
}


long long int max_path(int * p,int *q,int m,int n)
{
	int i=0,j=0;
	long long int count1=0,count2=0;
	long long int count=0;

	while(i<m&&j<n)
	{
		if(p[i] < q[j])
		{
			count1 = count1 + p[i];
			i++;
		}

		else if(p[i] > q[j])
		{
			count2 = count2 + q[j];
			j++;
		}

		else
		{
			count1 = count1 + p[i];
			count2 = count2 + q[j];
			count = count + max(count1,count2);
		
			count1=count2=0;
			i++;j++;
		}
	}

	

	while(i<m)
	{
		count1=  count1+ p[i++];
	}

	while(j<n)
	{
		count2 = count2 + q[j++];
	}

	return count + (max(count1,count2));



}


