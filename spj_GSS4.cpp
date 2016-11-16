#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long int data[100010];

struct node 
{
	int start,end;
	long long int  sum;
};

node seg[300000];

void build_tree(int i,int start,int end);
void merge(node & parent ,node &left,node &right);
node query(int i,int qlow,int qend);
void update(int i,int ulow ,int uhigh);
void lazy_prop(int i);
bool is_prop_req(int i);


int main()
{
	int n,j=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&data[i]);

		build_tree(1,1,n);

		int m;
		scanf("%d",&m);
		printf("Case #%d:\n",j++);
		for(int i=1;i<=m;i++)
		{
			int j,x,y;
			
			scanf("%d" " %d ""%d",&j,&x,&y);

			if(x>y)
				swap(x,y);
			
			if(j)
				printf("%lld\n",query(1,x,y).sum);
			else
				update(1,x,y);

			/*for(int i=1;i<=9;i++)
				printf("%lld\n",seg[i].sum);*/
		}
		printf("\n");
	}
}

void build_tree(int i,int start,int end)
{
	if(start == end)
	{
		seg[i].start = start;
		seg[i].end = end;
		seg[i].sum = data[start];
		return;
	}

	seg[i].start = start;
	seg[i].end = end;

	int mid = (start + end )/2;

	build_tree(2*i,start,mid);
	build_tree(2*i+1,mid+1,end);

	seg[i].sum = seg[2*i].sum +  seg[2*i+1].sum;

}

void merge(node & parent ,node &left,node &right)
{
	parent.sum = left.sum + right.sum;
}

node query(int i,int qlow,int qhigh)
{
	if(seg[i].start == qlow && seg[i].end == qhigh)
		return seg[i];

	int mid = (seg[i].start + seg[i].end)/2;

	if(qlow>mid)
		return query( 2*i+1,qlow,qhigh);
	else if(qhigh <= mid)
		return query(2*i,qlow,qhigh);
	else
	{
		node x = query(2*i,qlow,mid);
		node y = query(2*i+1,mid+1,qhigh);
		node temp;
		merge(temp,x,y);
		return temp;
	}
}

void update(int i,int ulow ,int uhigh)
{
	if((long long int)(seg[i].end - seg[i].start + 1) == seg[i].sum)
		return;

	if(seg[i].start == seg[i].end)
	{
		//cout<<"lazy from "<<i<<endl;
		seg[i].sum = (floor)((sqrt (double(seg[i].sum))));
		return;
	}

	int mid = (seg[i].start + seg[i].end)/2;

	if(ulow>mid)
		update(2*i+1,ulow,uhigh);
	else if(uhigh <=mid)
		update(2*i,ulow,uhigh);
	else
	{
		update(2*i,ulow,mid);
		update(2*i+1,mid+1,uhigh);
	}

	seg[i].sum =  seg[2*i].sum + seg[2*i+1].sum;
}



/*void lazy_prop(int i)
{
	if(!is_prop_req(i))
		return;

	if(seg[i].start == seg[i].end)
	{
		seg[i].sum = (floor)((sqrt (double(seg[i].sum))));
		//cout<< "update " << i << " " << data[seg[i].start] << " by " << seg[i].sum << endl;
		return;
	}

	

	lazy_prop(2*i);
	lazy_prop(2*i+1);

	merge(seg[i],seg[2*i],seg[2*i+1]);


}

bool is_prop_req(int i)
{
	return seg[i].sum > (seg[i].end - seg[i].start + 1);
}*/