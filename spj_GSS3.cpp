#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int low,high;
	int sum;
	int prefixsum;
	int suffixsum;
	int maxsum;
};

int data[51000];
node seg[2*65536];
int diff;

void build_tree(int i,int low,int high);
void merge(node &parent,node&left,node&right);
node query(int i,int qlow,int qhigh);
void update(int i,int value,int qlow,int qhigh);

int main()
{
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);

	build_tree(1,1,n);
	
	int m;
	scanf("%d",&m);

	for(int i=1;i<=m;i++)
	{
		int x,l,h;
		scanf("%d""%d""%d",&x,&l,&h);

		if(x)
			printf("%d\n",query(1,l,h).maxsum);
		else
			update(1,h,l,l);

	}
}

void build_tree(int i,int low,int high)
{
	if(low==high)
	{
		seg[i].high=high;
		seg[i].low=low;
		seg[i].sum = data[low];
		seg[i].prefixsum = data[low];
		seg[i].suffixsum = data[low];
		seg[i].maxsum = data[low];

		return;
	}

	int mid = (low + high)/2;

	seg[i].low =low;
	seg[i].high = high;

	build_tree(2*i,low,mid);
	build_tree(2*i+1,mid+1,high);

	merge(seg[i],seg[2*i],seg[2*i+1]);

}

void merge(node &parent,node&left,node&right)
{
	parent.sum = left.sum + right.sum;
	parent.prefixsum = max(left.prefixsum,left.sum+ right.prefixsum);
	parent.suffixsum = max(right.suffixsum,right.sum + left.suffixsum);
	parent.maxsum = max(left.suffixsum+right.prefixsum,max(left.maxsum,right.maxsum));
}

node query(int i,int qlow,int qhigh)
{
	if(seg[i].low==qlow && seg[i].high == qhigh)
		return seg[i];

	int mid = (seg[i].low + seg[i].high)/2;

	if(qlow>mid)
		return query(2*i+1,qlow,qhigh);
	else if(qhigh<=mid)
		return query(2*i,qlow,qhigh);
	else
	{
		node x = query(2*i,qlow,mid);
		node y =query(2*i+1,mid+1,qhigh);
		node temp;
		merge(temp,x,y);
		return temp;
	}
}

void update(int i,int value,int qlow,int qhigh)
{
	if(seg[i].low == qlow && seg[i].high == qhigh)
	{
		diff = value - seg[i].sum;
		seg[i].sum = value;
		seg[i].maxsum = value;
		seg[i].prefixsum = value;
		seg[i].suffixsum  = value;
		seg[i].maxsum = value;

		return;
	}


	int mid = (seg[i].low + seg[i].high)/2;

	if(qhigh<=mid)
		update(2*i,value,qlow,qhigh);
	else
		update(2*i+1,value,qlow,qhigh);

	merge(seg[i],seg[2*i],seg[2*i+1]);
}


