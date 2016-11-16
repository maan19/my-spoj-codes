#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<limits.h>
#include<string.h>
#include<vector>
using namespace std;
pair<int,int> bit[1000009];
void update(int k,int val);
pair<int,int> query(int k);
int  data[1000009];
int auxi[1000009];
int aux[100009];
int map[1000006];
int ne=2,pi=2;
int main()
{
	int n,np=2;
	scanf("%d",&n);
	memset(data,-1,sizeof(data));
	long long int sum=0;
	for(int t=1;t<=n;t++)
	{
		int d;scanf("%d",&d);
		for(int j=1;j<=d;j++)
			scanf("%d",&auxi[j]);
		if(d==0)
		{
			int j=1;
			for(int i=1;i<=ne;i++)
				if(data[i]!=-1)
					aux[j++]=data[i];
			for(int i=1;i<j;i++)
				data[i]=aux[i],map[aux[i]]=i;
			ne =j-1;
		}
		else
		{

		int i=1;
		for(int c=0,j=1;c<d;i++)
		{
			if(data[i]==-1)
				data[i]=auxi[j],c++,map[auxi[j]]=i,j++;
		}
			ne=ne-2+d;
		}
		
		for(int i=1;i<=ne;i++)
			bit[i].first=-1,bit[i].second=10000000;

		/*printf("data\n");
			for(int j=1;j<=ne;j++)
				printf("%d ",data[j]);
			printf("\n");*/
		for(int j=1;j<=ne;j++)
			update(j,data[j]);
		
		pair<int,int> q=query(ne);
		sum+=q.first-q.second;
		//printf("sum is %lld\n",sum);
		data[map[q.first]]=-1;data[map[q.second]]=-1;
		/*printf("new data\n");
			for(int j=1;j<=ne;j++)
				printf("%d ",data[j]);
			printf("\n");*/
	}
	printf("%lld\n",sum);
}
void update(int k,int val)
{
	int i=k;
	while(i<=ne)  //improved??
	{
		bit[i].first=val>bit[i].first?val:bit[i].first;
		bit[i].second = val<bit[i].second?val:bit[i].second;
		i+=(i&(-i));
	}
}

pair<int,int> query(int k)
{
	int i=k,mx=-1,mn=1234567;
	while(i>0)
	{
		mx=bit[i].first>mx?bit[i].first:mx;
		mn=bit[i].second<mn?bit[i].second:mn;
		i-=(i&(-i));
	}
	return make_pair(mx,mn);
}


