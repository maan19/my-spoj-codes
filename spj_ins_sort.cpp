#include<iostream>
#include<stdio.h>
int data[100090];
int inv;
void merge_sort(int s,int e);
void merge(int s,int e);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			scanf("%d",&data[i]);
		inv=0;
		merge_sort(1,n);
		printf("%d\n",inv);
	}
}


void merge_sort(int s,int e)
{
	if(s==e)
		return;

	int mid = (s+e)/2;

	merge_sort(s,mid);
	merge_sort(mid+1,e);
	merge(s,e);
}


void merge(int s,int e)
{
	int mid = (s+e)/2;
	int i=s,j=mid+1,k=1;
	int tmp[100090];

	while(i<=mid && j<=e)
	{
		if(data[i]<=data[j])
			tmp[k++]=data[i++];
		else
		{
			inv = inv + mid-i+1;
			tmp[k++]=data[j++];
		}
		
	}

	while(i<=mid)
		tmp[k++]=data[i++];
	while(j<=e)
		tmp[k++] = data[j++];

	for(int i = s,j=1;j<k;i++,j++)
		data[i]= tmp[j];
	
}
	


