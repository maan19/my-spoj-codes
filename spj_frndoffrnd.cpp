#include<iostream>
int f[102];
int ff[100000];
int c[100000];
void merge(int s1,int e1,int s2,int e2);
void merge_sort(int n,int start,int end);


int main()
{
	int n,m;
	scanf("%d",&n);

	int k=0;

	for(int i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
		scanf("%d",&m);

		for(int i=0;i<m;i++)
		{
			scanf("%d",&ff[k++]);
		}
	}

	merge_sort(k,0,k-1);
	int count =0;

	for(int i=0;i<k;)
	{
		int j;
		for( j=0;j<n;j++)
		{
			if(ff[i] == f[j])
				break;
		}

		if(j==n)
			count++;

		while(ff[i] == ff[i+1])
			i++;
		i++;
	}


	printf("%d\n",count);

	return 0;






}

void merge_sort(int n,int start,int end)
{
	if(n==1)
		return;

	int mid = (start + end )/2;

	merge_sort(mid-start + 1,start,mid);
	merge_sort(end-(mid + 1)+1,mid+1,end);
	merge(start,mid,mid+1,end);
}

void merge(int s1,int e1,int s2,int e2)
{
	int i=s1,j=s2,k=0;

	while(i != e1+1  && j!= e2 +1)
	{
		if(ff[i] <= ff[j])
		{
			c[k++] = ff[i++];
		}

		else
			c[k++] = ff[j++];
	}


	while(i!=e1+1)
		c[k++] = ff[i++];
	
	while(j!=e2+1)
		c[k++] = ff[j++];
	int l=0;
	for(int i=s1;i!=e2+1;i++)
		ff[i] = c[l++];
}

