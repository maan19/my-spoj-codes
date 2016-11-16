#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string,int> m;
int data[30008];
void merge_sort(int s,int e);
void merge(int s,int n);
int n,inv;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d",&n);
		inv =0;

		string s;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			m[s]=i;
		}

		for(int i=1;i<=n;i++)
		{
			cin>>s;
			data[i] = m[s];
		}
		merge_sort(1,n);
		printf("%d\n",inv);
		m.clear();
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
	





		

