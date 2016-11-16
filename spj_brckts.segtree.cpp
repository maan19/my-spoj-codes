#include<stdio.h>
#include<iostream>
#include<algorithm>

struct node
{
	int low,high;
	int unmatched_open;
	int unmatched_close;
};

char data[31000];
node seg[2*32768];


using namespace std;

void update(int i,int low,int high);
void build_tree(int i,int low,int high);
void merge(node & parent,node & left, node & right);
bool query(int i,int qlow,int qhigh);


int main()
{
	int j=1;
	while(j<=10)
	{
	int n;
	scanf("%d",&n);

	scanf("%s",data+1);
	//puts(data+1);
	
	build_tree(1,1,n);

	/*for(int i=1;i<=25;i++)
		printf("%d %d\n",seg[i].unmatched_open,seg[i].unmatched_close);*/

	int m;
	scanf("%d",&m);
	printf("Test %d:\n",j);
	
	for(int i=0;i<m;i++)
	{
		int k;
		scanf("%d",&k);

		if(k)
			{
				update(1,k,k);
				//printf("new\n");
				/*for(int i=1;i<=19;i++)
					printf("%d %d\n",seg[i].unmatched_open,seg[i].unmatched_close);*/
		}

		else
		{
			if(query(1,1,n))
				printf("YES\n");
			else
				printf("NO\n");
			//printf("%d %d\n",seg[1].unmatched_close,seg[1].unmatched_open);
		}
	}
	j++;
	}
}


void build_tree(int i,int low,int high)
{
	if(low == high)
	{
		seg[i].high = high;
		seg[i].low = low;
		
		if(data[low]==')')
		{
			seg[i].unmatched_close = 1;
			seg[i].unmatched_open =0;
		}
		else
		{
			seg[i].unmatched_close = 0;
			seg[i].unmatched_open = 1;
		}
		return;
	}


	int mid = (high + low)/2;

	seg[i].low = low;
	seg[i].high = high;

	build_tree(2*i,low,mid);
	build_tree(2*i+1,mid+1,high);

	merge(seg[i],seg[2*i],seg[2*i+1]);
}

void merge(node & parent,node & left, node & right)
{
	int new_match = min(left.unmatched_open,right.unmatched_close);
	parent.unmatched_open = left.unmatched_open + right.unmatched_open - new_match;
	parent.unmatched_close = left.unmatched_close + right.unmatched_close - new_match;
}

bool query(int i,int qlow,int qhigh)
{
	if(seg[i].unmatched_close == 0 && seg[i].unmatched_open == 0)
		return true;
	return false;
}

void update(int i,int low,int high)
{
	if(seg[i].low==low && seg[i].high == high)
	{
		seg[i].unmatched_close = !(seg[i].unmatched_close);
		seg[i].unmatched_open = !(seg[i].unmatched_open);
		//printf("%d updated op %d cl %d\n",i,seg[i].unmatched_open,seg[i].unmatched_close);
		return;
	}

	int mid = (seg[i].low + seg[i].high)/2;

	if(low > mid)
		update(2*i+1,low,high);
	else
		update(2*i,low,high);
	
	merge(seg[i],seg[2*i],seg[2*i+1]);
}



				 