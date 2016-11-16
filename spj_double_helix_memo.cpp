#include<stdio.h>
#include<iostream>
#include<algorithm>
#define l 10001

using namespace std;
 long long int fun_max(int * current,int * free,int c,int ec,int f,int ef,int t);
int bin_srch(int * arr,int target,int low,int high);

int a[10001];
int b[10001];
int n,m;
int memo[25000];

int main()
{
	scanf("%d",&n);
	while(n!=0)
	{

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	scanf("%d",&m);

	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);

	for(int i=0;i<25000;i++)
		memo[i]=-1;

	printf("%lld\n",max(fun_max(a,b,0,n,0,m,-10001),fun_max(b,a,0,m,0,n,-10001)));
	scanf("%d",&n);

}
	return 0;
}

 long long int fun_max(int * current,int * free,int c,int ec,int f,int ef,int t)
{
	if(c==ec)
		return 0;
	if(memo[t+l]!=-1)
		return memo[t+l];
	long long int count =0;

			
	

	int k=-1;
	

	while(c < ec && k<0)
	{
		count = count + current[c];
		k=bin_srch(free,current[c],f,ef);
		c++;
	}
	
    long long int x=0,y=0;
	if(k>=0)
	{
		t = free[k];
		x = fun_max(current,free,c,ec,f,ef,t);
		y = fun_max(free,current,k+1,ef,c,ec,t);
	}

	if(k>=0)
		memo[t+l] =  max(x,y);
	
	return((count + max(x,y)));
}

	


int bin_srch(int * arr,int target,int low,int high)
{
	int mid = (low + high)/2;

	while(low<=high)
	{

	if(arr[mid] == target)
		return mid;

	else if(arr[mid] > target)
		high = mid - 1;
	else
		low = mid + 1;
	mid = (low + high)/2;
	}
	return -1;
}



