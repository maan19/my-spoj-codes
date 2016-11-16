#include<stdio.h>

int c[10000000];
void merge_sort(int * org,int n,int start,int end);
void merge(int * org,int s1,int e1,int s2,int e2);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;

		scanf("%d",&n);
		int * p = new int [n];

		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);

		merge_sort(p,n,0,n-1);

		int i=0;
		unsigned long long int count =0;

		while(i<n)
		{
			count =1;
			while(i < n-1 && p[i] == p[i+1])
			{
				count++;
				i++;
			}

			if(count > n/2)
			{
				printf("YES %d\n\n",p[i]);
				break;
			}
			

			else
				i++;
		}

		if(i==n)
			printf("NO\n\n");




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
