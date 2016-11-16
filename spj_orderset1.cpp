#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int bit[2*100000+4];
bool bh[200000+6];
char a[200000+7];
int x[200000+7],b[200000+7];
unordered_map <int,int> m;
int t,cnt=0;

void update(int k,int val);
int query(int k);

int main()
{
	int p; 
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%s",&a[i]);
		scanf("%d",&p);
		x[i]=b[i]=p;
	}
	sort(x+1,x+t+1);
	for(int i=1;i<=t;i++)  //coordinate compression
		m[x[i]]=i;         //for multiple entries map will store the very last value assigned
    for(int i=1;i<=t;i++)
	{
		if(a[i]=='I')
		{
			if(bh[m[b[i]]]==false)
			{
				cnt++;
				update(m[b[i]],1);
			}
		}
		if(a[i]=='D')
		{
			if(bh[m[b[i]]]==false)
				continue;
			else
				update(m[b[i]],-1),cnt--;
		}
		if(a[i]=='C')
			printf("%d\n",query(m[b[i]]-1));
		if(a[i]=='K')
		{
			if(b[i]>cnt)
				printf("invalid\n");
			else
			{
				  int lo=1,hi=200000,mid;
				  while(lo<hi)
				  {
					  mid = lo + (hi-lo)/2;
					  int j=query(mid);
					  if(j<b[i])
						  lo=mid+1;
					  else
						  hi=mid;
				  }
				  printf("%d\n",x[lo]);
			}
		}
	}
}
void update(int k,int val)
{
	int i=k;
	bh[i]=(val==1)?true:false;
	while(i<=200000) //??
	{
		bit[i]+=val;
		i+=(i&(-i));
	}
}
int query(int k)
{
	int i=k,sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}