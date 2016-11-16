#include<stdio.h>
#include<iostream>
#include<algorithm>

int a[100008];
int bin[33];
int bb[33];


struct node
{
	int no;
	int sub[2];
	node * child[2];
};

node root;
void initialise(node * p);
void insert(unsigned int n,node * root);
int query(int n,node * root,int k);

int main()
{

	int t,cnt=0,pre=0;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		cnt=0,pre=0;
		scanf("%d""%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		insert(0,&root);
		for(int i=1;i<=n;i++)
		{
			pre ^= a[i];
			cnt+=query(pre,&root,k);
			printf("cnt is %d\n",cnt);
			insert(pre,&root);
		}
		printf("%d\n",cnt);
	}
}

void insert(unsigned int n,node * root)
{
	node *p=root;node*t;
	printf("n is %d\n",n);
	for(int i=0;i<=31;i++)
	{
			//printf("%d ",bin[i]);
	}
	printf("\n");
	
	for(int i=3;i>=0;i--)
	{
		if(p->child[bin[i]]==NULL)
		{
			p->child[bin[i]]=t=new node;
			p->sub[bin[i]]++;
			printf("p->sub[%d] is %d\n",bin[i],p->sub[bin[i]]);
			initialise(t);
			p=p->child[bin[i]];
		}
		else
		{
			p=p->child[bin[i]];
			p->sub[bin[i]]++;
			printf("p->sub[%d] is %d\n",bin[i],p->sub[bin[i]]);
		}
	}
}

void initialise(node * p)
{
	p->child[1]=p->child[0]=NULL;
	p->sub[1]=p->sub[0]=0;
	p->no=0;
}

int query(int n,node * root,int k)
{
	printf("query for n %d ",n);
	for(int i=0;i<=3;i++,n=n>>1,k=k>>1)
	{
			bin[i] =(n&1);
			//printf("  %d ",bin[i]);
			bb[i]=(k&1);
			//printf(" %d ",bin[i]);
	}
	printf("\n");
	int cnt=0;

	for(int i=3;i>=0;i--)
	{
		if(bb[i]==0)
		{
			if(bin[i]==0)
			{
				if(root->child[1]!=NULL)
				{
					cnt+=0;
				}
				if(root->child[0]!=NULL)
					root=root->child[0];
			}
			else
			{
				if(root->child[0]!=NULL)
				{
				cnt+=0;
				}
				if(root->child[1]!=NULL)
					root=root->child[1];
			}
		}
		else
		{
			if(bin[i]==0)
			{
				if(root->child[0]!=NULL)
				{
					printf("returning %d\n",root->sub[0]);
					cnt+= root->sub[0];
				}
				if(root->child[1]!=NULL)
					root=root->child[1];
			}
			else
			{
				if(root->child[0]!=NULL)
					root=root->child[0];
				if(root->child[1]!=NULL)
				{
					printf("return %d\n",root->sub[1]);
					cnt+= root->sub[1];
				}
			}
		}
	}
	return cnt;
}

		
		





		
			
