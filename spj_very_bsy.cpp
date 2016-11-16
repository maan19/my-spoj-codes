#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;


struct node
{
	int st;
	int en;
};

int my_cmp(const void* a,const void * b)
{
	return ((node*)a)->en > ((node*)b)->en;
}

node data[100009];


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d %d",&data[i].st,&data[i].en);
		

		qsort(data,n,sizeof(node),my_cmp);
		/*printf("sorted\n");
		for(int i=0;i<n;i++)
		{
			printf("%d  %d\n",data[i].st,data[i].en);
		}*/

		int cnt=1,en=data[0].en;
		
			for(int j=1;j<n;j++)
			{
				if(data[j].st >= en)
				{
						cnt++;
						en = data[j].en;
				}
			}
			
		

		printf("%d\n",cnt);
	}
	


}
