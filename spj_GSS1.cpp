#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
void build_tree(int i,int low,int high);
void merge(struct node &parent,node &left,node &right);
node query(int i,int qlow,int qhigh);


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

int main()
{
	int t;
	scanf("%d",&t);

	for(int i=1;i<=t;i++)
		scanf("%d",&data[i]);
	build_tree(1,1,t);
	//cout<<"tree built\n";
	
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int l,h;
		scanf("%d""%d",&l,&h);
		printf("%d\n",query(1,l,h).maxsum);
	}
}

void build_tree(int i,int low,int high)
{
	if(low==high)
	{
		seg[i].low =low;
		seg[i].high = high;
		seg[i].sum  =data[low];
		seg[i].maxsum = data[low];
		seg[i].prefixsum = data[low];
		seg[i].suffixsum = data[low];
		return;
	}

	seg[i].low = low;
	seg[i].high = high;
	int mid = (low + high)/2;
	build_tree(2*i,low,mid);
	build_tree(2*i+1,mid+1,high);

	merge(seg[i],seg[2*i],seg[2*i+1]);


}

void merge( node &parent,node &left,node &right)
{
	parent.sum = left.sum + right.sum;
	parent.prefixsum = max(left.prefixsum , left.sum + right.prefixsum);
	parent.suffixsum = max(right.suffixsum,right.sum + left.suffixsum);
	parent.maxsum = max(left.suffixsum + right.prefixsum,max(left.maxsum,right.maxsum));
}

node query(int i,int qlow,int qhigh)
{
	if(seg[i].low == qlow && seg[i].high == qhigh)
		return seg[i];

	int mid = (seg[i].high + seg[i].low )/2;

	if(qlow > mid)
		return query(2*i+1,qlow,qhigh);
	
	else if(qhigh<=mid)
		return query(2*i,qlow,qhigh);
	else
	{
		struct node  x = query(2*i,qlow,mid);
		struct node y = query(2*i+1,mid+1,qhigh);
		struct node temp;
		merge(temp,x,y);
		return temp;
	}
}












