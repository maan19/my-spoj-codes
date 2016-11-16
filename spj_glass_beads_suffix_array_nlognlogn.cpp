#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node
{
	int g[2];
	int p;
};

char A[11000];
node sa[11000];
int pos[20][11000];
int step,gap;

int str_len();
int my_cmp(const void* c,const void * d);
void build_sa();
void quick_sort(int start,int end);
int ptn(int start,int end);
void swp(int i,int j);
int rand_part(int start,int end);

int main()
{
	int t;
	scanf("%d",&t);

		while(t--)
		{
			scanf("%s",A);
			build_sa();
			int n=str_len();
			int i;
			for( i=0;i<n;i++)
			{
				if(pos[step-1][i]==0)
					break;
			}
			printf("%d\n",i+1);




		}
}



void build_sa()
{
	int n =str_len();
	for(int i=0;i<n;i++)
		pos[0][i]=A[i]-'a';

	

	for(step=1,gap=1;gap<n;gap*=2,step++)
	{
		for(int i=0;i<n;i++)
		{
			sa[i].g[0] = pos[step-1][i];
			sa[i].g[1] = pos[step-1][(i+gap)%n];
			sa[i].p=i;
		}

		qsort(sa,n,sizeof(node),my_cmp);

		for(int i=0;i<n;i++)
			pos[step][sa[i].p] = i>0 && sa[i].g[0]==sa[i-1].g[0] && sa[i].g[1]==sa[i-1].g[1]?pos[step][sa[i-1].p]:i;
		

	}

	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%c",A[(sa[i].p + j )%n]);
		}
		printf("\n");
	}
		*/
}



int str_len()
{
	char * p =A;
	int k;
	for(k=0;*p;k++,p++)
	{}

	return k;
}


/*int ptn(int start,int end)
{
	int pindex = start;
	int pivot = end;

	for(int i=start;i<end;i++)
	{
		if(my_cmp(&sa[i],&sa[pivot]))
		{
			swp(i,pindex);
			pindex++;
		}
	}

	swp(pindex,pivot);
	return pindex;
	
}

int rand_part(int start,int end)
{
	int pindex = (rand()%(end-start+1)) + start;
	swp(pindex,end);
	return ptn(start,end);
}

void swp(int i,int j)
{
	node tmp;
	tmp.g[0] = sa[i].g[0];
	tmp.g[1] = sa[i].g[1];
	tmp.p=sa[i].p;

	sa[i].g[0] = sa[j].g[0];
	sa[i].g[1] = sa[j].g[1];
	sa[i].p = sa[j].p;

	sa[j].g[0] = tmp.g[0];
	sa[j].g[1] = tmp.g[1];
	sa[j].p  = tmp.p;
	
}

void quick_sort(int start,int end)
{
	if(start>=end)
		return;

	int p = (rand()%(end-start+1)) + start;
	swp(p,end);

    int pindex = start;
	int pivot = end;

	for(int i=start;i<end;i++)
	{
		if(my_cmp(&sa[i],&sa[pivot]))
		{
			swp(i,pindex);
			pindex++;
		}
	}

	swp(pindex,pivot);
	int k = pindex;

	quick_sort(start,k-1);
	quick_sort(k+1,end);
}
*/


int my_cmp(const void *  a ,const void * b)
{

	
	
	
	return(((node*)a)->g[0] == ((node*)b)->g[0]?(((node*)a)->g[1]<((node*)b)->g[1]?-1:1):(((node*)a)->g[0]<((node*)b)->g[0]?-1:1));
}
