#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<limits.h>



using namespace std;

struct node
{
	int max1,max2;
};

int data[100008];
node tree[2*131072-1];
struct node query(int id,int a,int b,int p,int q);
void build_tree(int id,int a,int b);
void update(int id,int a,int b,int x,int v);


int main()
{
	int n;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);

	build_tree(1,1,n);

	int d;
	scanf("%d",&d);

	char c;
	int p,q,v;
	
	for(int i=1;i<=d;i++)
	{
		
		do
		c = getchar();
		while(!(c == 'U' || c == 'Q'));
		
		//cout << " c is " << c << endl;

		if(c=='U')
		{
			scanf("%d""%d",&p,&v);
			update(1,1,n,p,v);
		}

		else
		{
			scanf("%d""%d",&p,&q);
			node r =query(1,1,n,p,q);
			printf("%d\n",r.max1+r.max2);
		}
	}
}

void build_tree(int id,int a,int b)
{
	if(a==b)
	{
		tree[id].max1 = data[a];
		tree[id].max2 = INT_MIN;
		return;
	}

	int mid = (a+b)/2;

	build_tree(2*id,a,mid);
	build_tree(2*id+1,mid+1,b);

	tree[id].max1 = max(tree[2*id].max1,tree[2*id+1].max1);
	tree[id].max2 = (tree[id].max1 == tree[2*id].max1)?max(tree[2*id].max2,tree[2*id+1].max1):max(tree[2*id].max1,tree[2*id+1].max2);

}

void update(int id,int a,int b,int x,int v)
{
	if(a > b || x <a || x > b)
		return;

	if(a == b  )
	{
		tree[id].max1 = v;
		tree[id].max2 = INT_MIN;
		return;
	}

	int mid = (a + b)/2;

	update(2*id,a,mid,x,v);
	update(2*id+1,mid+1,b,x,v);

	tree[id].max1 = max(tree[2*id].max1,tree[2*id+1].max1);
	tree[id].max2 = (tree[id].max1 == tree[2*id].max1)?max(tree[2*id].max2,tree[2*id+1].max1):max(tree[2*id].max1,tree[2*id+1].max2);  
}


struct node query(int id,int a,int b,int p,int q)
{
	if(a > b || p > b || q < a)
	{
		node r;
		r.max1 = r.max2 = INT_MIN;
		return r;
	}

	if(a>=p && b<=q)
		return tree[id];

	int mid = (a+b)/2;
	  
	node r1,r2,r;
	r1 = query(2*id,a,mid,p,q);
	r2 = query(2*id+1,mid+1,b,p,q);

	r.max1 = max(r1.max1,r2.max1);
	r.max2 = (r.max1 == r1.max1)?max(r1.max2,r2.max1):max(r1.max1,r2.max2);

	return r;


}

	



