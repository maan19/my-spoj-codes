#include<iostream>
#include<limits.h>
int a[1005];
int b[1005];
int c[1005];
void merge_sort(int * org,int n,int start,int end);
int min_merge(int *a,int *b,int n,int m);
void merge(int * org,int s1,int e1,int s2,int e2);



int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,m;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);

		scanf("%d",&m);

		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		merge_sort(a,n,0,n-1);
		merge_sort(b,m,0,m-1);

		printf("%d\n",min_merge(a,b,n,m));

	}
	return 0;
}
void merge_sort(int * org,int n,int start,int end)
{
	if(n==1)
		return;

	int mid = (start + end ) /2;

	merge_sort(org,mid - start + 1,start,mid);
	merge_sort(org,end-(mid+1)+1,mid+1,end);
	merge(org,start,mid,mid+1,end);
}

void merge(int * org,int s1,int e1,int s2,int e2)
{
	int i=s1,j=s2,k=0;

	while(i!=e1+1 && j!= e2 +1)
	{
		if(org[i]<=org[j])
		{
			c[k++] = org[i++];
		}

		else
			c[k++] =org[j++];
	}

	while(i!=e1+1)
		c[k++] = org[i++];

	while(j!=e2+1)
		c[k++] = org[j++];
	k=0;
	for(int i=s1;i!=e2+1;)
		org[i++] =c[k++];
}

int min_merge(int *a,int *b,int n,int m)
{
	int i=0,j=0,min=INT_MAX,diff;

	while(i!= n && j!=m)
	{
		
		
		if(a[i] <= b[j])
			{
				diff = b[j] - a[i];
				i++;
		}
		else
		{
			diff = a[i]-b[j];
			j++;
		}

		min = min > diff?diff:min;
	}

	return min;
}

	







