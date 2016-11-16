#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,a,b;
int data[40];
vector<int> l;
vector<int> r;
void gen_subset();
int main()
{
	scanf("%d""%d""%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	gen_subset();
	sort(r.begin(),r.end());
	vector<int>::iterator lo,hi;long long sum=0;
	for(int i=0;i<l.size();i++)
	{
		lo=lower_bound(r.begin(),r.end(),a-l[i]);
		hi=upper_bound(r.begin(),r.end(),b-l[i]);
		sum+=(long long)(hi-lo);
	}
	printf("%lld\n",sum);
}
void gen_subset()
{
	int sum;
	for(int i=0;i<(1<<(n/2));i++)
	{
		sum=0;
		for(int j=i,k=0;j>0;j>>=1,k++)
			if(j&1)
				sum+=data[(n/2)-k];
		l.push_back(sum);
	}
	int rem=n-(n/2);
	for(int i=0;i<(1<<rem);i++)
	{
		sum=0;
		for(int j=i,k=rem;j>0;j>>=1,k--)
			if(j&1)
				sum+=data[(n/2)+k];
		r.push_back(sum);
	}
}


