#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;


struct node
{
	int L,R,k;
};

int data[300008];
struct node query[200007];
int BLOCK_SIZE;

bool my_cmp(node x,node y)
{
	return((x.L/BLOCK_SIZE != y.L/BLOCK_SIZE )?(x.L/BLOCK_SIZE < y.L/BLOCK_SIZE):(x.R<y.R));
}

int ans,cnt[1000009],qans[200008];




int main()
{
	int n;
	scanf("%d",&n);

	BLOCK_SIZE = sqrt((double)n);

	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);

	/*cout<<"data\n";

	for(int i=1;i<=n;i++)
		cout<<data[i]<<" ";
	cout<<endl;*/

	int d;
	scanf("%d",&d);

	for(int i=1;i<=d;i++)
	{
		scanf("%d""%d",&query[i].L,&query[i].R);
		query[i].k = i;
	}

	/*cout<<"queries\n";

	for(int i=1;i<=d;i++)
	{
		cout<<query[i].L << "  " <<query[i].R << "  " << query[i].k<<endl;
	}*/

	sort(query+1,query+d+1,my_cmp);

	/*for(int i=1;i<=d;i++)
		cout<<"sort " << query[i].k << endl;*/


	int L,R,CL,CR;
	CL=1;CR=0;

	for(int i=1;i<1000006;i++)
		cnt[i]=0;

	for(int i=1;i<=d;i++)
	{
		L=query[i].L;
		R=query[i].R;
		

		while(CL < L)
		{
			cnt[data[CL]]--;
			if(cnt[data[CL]]==0)
				ans--;

			CL++;
		}

		while(CL > L)
		{
			CL--;
			cnt[data[CL]]++;
			if(cnt[data[CL]]==1)
				ans++;
		}

		while(CR >R)
		{
			cnt[data[CR]]--;
			if(cnt[data[CR]]==0)
				ans--;
			CR--;
		}

		while(CR < R)
		{
			CR++;
			cnt[data[CR]]++;
			if(cnt[data[CR]]==1)
				ans++;
		}

		qans[query[i].k] = ans;
	}

	for(int i=1;i<=d;i++)
		printf("%d\n",qans[i]);
	

}







