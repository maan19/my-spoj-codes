#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    long long int start,end;
	long long int sum;
	long long int pending_update;
};

using namespace std;
node tree[6*100000];
struct node query(long long int i,long long int qlow,long long int qhigh);
void build_tree(long long int i,long long int start,long long int end);
void update(long long int i,long long int start,long long int end,long long int v);
void merge(struct node &parent,struct node &left,struct node &right);

int main()
{
	long long int t;
	cin >> t;

	while(t--)
	{
		long long int n,c;
		cin >> n >> c;

		build_tree(1,1,n);

		long long int p,q,k;
		long long int v;

		for(long long int i=0;i<c;i++)
		{
			cin >> k;
			if(k)
			{
					cin >> p >> q;
					cout << query(1,p,q).sum << endl;
			}
			else
			{
					cin >> p >> q>> v;
					update(1,p,q,v);
			}

		}
	}
}

void build_tree(long long int i,long long int start,long long int end)
{
	if(start == end)
	{
		tree[i].start = start;
		tree[i].end = end;
		tree[i].pending_update =0;
		tree[i].sum = 0;
		return;
	}

	tree[i].start = start;
	tree[i].end = end;
	tree[i].pending_update = 0;
	


	long long int mid = (start + end)/2;

	build_tree(2*i,start,mid);
	build_tree(2*i+1,mid+1,end);
	merge(tree[i],tree[2*i],tree[2*i+1]);
}

void update(long long int i,long long int start,long long int end,long long int v)
{
	if(tree[i].start == start && tree[i].end == end)
	{
		tree[i].pending_update += v;
		//printf("%d to %d has pu %d\n",tree[i].start,tree[i].end,tree[i].pending_update);
		return;
	}


	long long int mid = (tree[i].start + tree[i].end )/2;

	if(start > mid)
		update(2*i+1,start,end,v);
	else if(end<=mid)
		update(2*i,start,end,v);
	else
	{
		update(2*i,start,mid,v);
		update(2*i+1,mid+1,end,v);
	}

	merge(tree[i],tree[2*i],tree[2*i+1]);
	//printf("tree %d to %d has sum %d\n",tree[i].start,tree[i].end,tree[i].sum);

}

void merge(struct node &parent,struct node &left,struct node &right)
{
	parent.sum = left.sum + right.sum;
	if(left.pending_update)
		parent.sum += (left.end-left.start + 1)*(left.pending_update);
	if(right.pending_update)
	{
		parent.sum += (right.end - right.start + 1)*(right.pending_update);
		
	}

	//printf("%d to %d has sum %d\n",parent.start,parent.end,parent.sum);
}

struct node query(long long int i,long long int qlow,long long int qhigh)
{
	if(tree[i].start == qlow && tree[i].end == qhigh)
	{
		struct node result = tree[i];
		
		if(result.pending_update)
		{
				result.sum += (result.end -result.start +1)*result.pending_update;
				result.pending_update = 0;
		}
		
		return result;
	}

	long long int mid = (tree[i].start + tree[i].end)/2;

	struct node result;

	if(qlow>mid)
		result = query(2*i+1,qlow,qhigh);
	else if(qhigh<=mid)
		result = query(2*i,qlow,qhigh);
	else
	{
		struct node left =query(2*i,qlow,mid);
		struct node right = query(2*i+1,mid+1,qhigh);
		merge(result,left,right);
		result.start = left.start;
		result.end = right.end;
	}

	if(tree[i].pending_update)
	{
		result.pending_update += tree[i].pending_update;
		result.sum += (result.end - result.start + 1)*result.pending_update;
		result.pending_update=0;
	}

	return result;
}
















