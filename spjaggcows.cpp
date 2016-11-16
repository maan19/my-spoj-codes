#include<iostream>

using namespace std;
long  int pos[100001];

long int bin_srch(int stalls,int cow);
void merge(long int * arr,long int * p ,long int *q,int m,int n);
void merge_sort(long int * arr,int stalls);


int main()
{
	int cows,stalls,cases;

	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%d %d",&stalls,&cows);

	for(int i=0;i<stalls;i++)
	{
		scanf("%ld",&pos[i]);
	}
	
	merge_sort(pos,stalls);
	
	printf("%lu\n",bin_srch(stalls,cows));
	}


}


long int bin_srch(int stalls,int cow)
{
	unsigned long long  int lo,hi;
	unsigned long long int mid,prev,cows;

	lo =1;hi=pos[stalls-1];

	

	while(lo<hi)
	{
		prev=pos[0];
		cows =1;
		mid = lo + (hi-lo +1)/2;

		for(int i =1;i<stalls;i++)
		{
			if(pos[i]-prev >= mid)
			{
				cows++;
				prev =pos[i];
			}
		}

		if(cows>=cow)
			lo=mid;
		else
			hi = mid -1;
	}

	return lo;
}

void merge_sort(long int * arr,int stalls)
{
	if(stalls==1)
		return;

	int mid = stalls/2;
	long int  * p ,*q;

	p = new long int[mid];
	q = new long int[stalls-mid];

	int j=0,k=0;

	for(int i=0;i<mid;i++)
	{
		p[j++] = arr[i];
	}

	for(int i=mid;i<stalls;i++)
	{
		q[k++] = arr[i];
	}

	merge_sort(p,mid);
	merge_sort(q,stalls-mid);
	
	merge(arr,p,q,mid,stalls-mid);
}

void merge(long int * arr,long int * p ,long int *q,int m,int n)
{

	int i,j,k;
	i=j=k=0;

	while(j<m&&k<n)
	{
		if(p[j]<=q[k])
		{
			arr[i++] = p[j++];
		}

		else
			arr[i++] = q[k++];
	}

	if(j<m)
	{
		while(j<m)
		{
		arr[i++] =p[j++];
		}
	}


	if(k<n)
	{
		while(k<n)
		{
		arr[i++] = q[k++];
		}
	}
	
}





	
		












