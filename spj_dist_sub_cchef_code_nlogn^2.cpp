#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int g[2];
	int p;
};



char A[60000];
int str_len();
int my_cmp(const void *a,const void * b );
void build_sa();
void build_lcp();
void quick_sort(int start,int end);
int ptn(int start,int end);
void swp(int i,int j);
int rand_part(int start,int end);



node sa[60000];
int pos[20][60000];
int lcp[60000];
int gap,step;
int n,sum;



int main()
{
	int t;
	scanf("%d",&t);
	

	while(t--)
	{
		scanf("%s",A);
		n=str_len();
		build_sa();

		
		 
		/*cout<<"sorted list\n";
		for(int i=0;i<n;i++)
			cout<<sa[i].p<<" ";

		cout<<"\n pos \n";
		for(int i=0;i<n;i++)
			cout<<pos[step-1][i]<<" ";*/


		build_lcp();
		/*cout<<"\nlcp\n";

		for(int i=0;i<n;i++)
			cout<<lcp[i]<<" ";
		cout<<endl;*/



		
		

		printf("%d\n",n*(n+1)/2-sum);
	}
}

int my_cmp(const void *c,const void *  d)
{
	node a = *(node*)c;
	node b =*(node *)d;
	return a.g[0] == b.g[0]?(a.g[1]<b.g[1]?-1:1):(a.g[0]<b.g[0]?-1:1);
}


void build_sa()
{
	
	for(int i=0;i<n;i++)
		pos[0][i]=A[i]-'A';

	

	for(step=1,gap=1;gap<n;gap*=2,step++)
	{
		for(int i=0;i<n;i++)
		{
			sa[i].g[0] = pos[step-1][i];
			sa[i].g[1] = i+gap<n?pos[step-1][i+gap]:-1;
			sa[i].p=i;
		}

		qsort(sa,n,sizeof(node),my_cmp);
		pos[step][sa[0].p]=0;
		for(int i=1;i<n;i++)
			pos[step][sa[i].p] =  sa[i].g[0]==sa[i-1].g[0] && sa[i].g[1]==sa[i-1].g[1]?pos[step][sa[i-1].p]:pos[step][sa[i-1].p]+1;
			

		if(pos[step][sa[n-1].p]==n-1)
			break;
	}

	
}

void build_lcp()
{
	int k=0;
	int s= gap<n?step:step-1;
	sum=0;

    /*for(int i=0;i<n;i++)
		cout<<A+sa[i].p<<endl;
	
	cout<<"pos\n";

	for(int i=0;i<n;i++)
		cout<<pos[s][i]<<endl;*/

	for(int i=0;i<n;i++)
	{
		if(pos[s][i]==0)
		{
				lcp[pos[s][i]]=0;
				continue;
		}
		int j = sa[pos[s][i]-1].p;
		
		while(i+k<n && j + k<n && A[i+k]==A[j+k])
			k++;
		lcp[pos[s][i]]=k;
		sum = sum + k;

		if(k)
			k--;
	}
	//printf("sum is %lld\n",sum);
}


int str_len()
{
	char * p ;
	
	for(p=A;*p;p++)
	{}

	return p-A;
}


/*int ptn(int start,int end)
{
	int pindex = start;
	int pivot = end;

	for(int i=start;i<end;i++)
	{
		if(my_cmp(sa[i],sa[pivot]))
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
	int k = rand_part(start,end);
	quick_sort(start,k-1);
	quick_sort(k+1,end);
}*/




