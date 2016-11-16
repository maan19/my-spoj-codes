#include<iostream>
#include<limits.h>

using namespace std;
int c[20009];
int height[20009];
void merge(int s1,int e1,int s2,int e2);
void merge_sort(int n,int start,int end);


int main()
{
	int t;
	int min = INT_MAX;
	scanf("%d",&t);

	while(t--)
	{
		int n,k;
		scanf("%d" "%d",&n,&k);

		for(int i=0;i<n;i++)
			scanf("%d",&height[i]);

		merge_sort(n,0,n-1);
		/*for(int i=0;i<n;i++)
			printf("%d\n",height[i]);*/
		min= INT_MAX;
		for(int i=0,j=k-1;i<=n-k;i++,j++)
		{
			min = min > (height[j] - height[i]) ? (height[j]- height[i]):min;
		}

		printf("%d\n",min);
	}

	return 0;



}


void merge_sort(int n,int start,int end)
{
	if(n==1)
		return;

	int mid = (start + end ) /2;

	merge_sort(mid - start + 1,start,mid);
	merge_sort(end-(mid+1)+1,mid+1,end);
	merge(start,mid,mid+1,end);
}

void merge(int s1,int e1,int s2,int e2)
{
	int i=s1,j=s2,k=0;

	while(i!=e1+1 && j!= e2 +1)
	{
		if(height[i]<=height[j])
		{
			c[k++] = height[i++];
		}

		else
			c[k++] =height[j++];
	}

	while(i!=e1+1)
		c[k++] = height[i++];

	while(j!=e2+1)
		c[k++] = height[j++];
	k=0;
	for(int i=s1;i!=e2+1;)
		height[i++] =c[k++];
}


