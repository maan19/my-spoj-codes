#include<iostream>
#include<string.h>
char acc[100005][35];
char c[100005][35];

using namespace std;
void merge_sort(int n,int start,int end);
void merge(int s1,int e1,int s2,int e2);


int main()
{

	  int t;
	  scanf("%d",&t);

	  while(t--)
	  {
		int n;
		scanf("%d",&n);
		getchar();

		for(int i=0;i<n;i++)
			gets(acc[i]);

	/*	for(int i=0;i<n;i++)
			puts(acc[i]);*/

		merge_sort(n,0,n-1);

		/*for(int i=0;i<n;i++)
			puts(acc[i]);*/

		for(int i=0;i<n;i++)
		{
			int count =1;
			while(i !=n-1 && strcmp(acc[i],acc[i+1])==0)
			{
				count++;
				i++;
			}

			

			printf("%s %d\n",acc[i],count);
			


	  }
}
}








				


void merge_sort(int n,int start,int end)
{
	if(n==1)
		return;

	int mid = (start + end ) /2;

	merge_sort(mid - start + 1,start,mid);
	merge_sort(end-(mid+1)+1,mid+1,end);
	merge(start,mid,mid+1,end);
}

void merge(int s1,int e1,int s2,int e2)
{
	int i=s1,j=s2,k=0;

	while(i!=e1+1 && j!= e2 +1)
	{
		if(strcmp(acc[i],acc[j]) <0)
		{
			strcpy(c[k++],acc[i++]);
		}

		else
			strcpy(c[k++] ,acc[j++]);
	}

	while(i!=e1+1)
		strcpy(c[k++],acc[i++]);

	while(j!=e2+1)
		strcpy(c[k++],acc[j++]);
		
	j=0;
	for(int i=s1;i!=e2+1 && j<k;)
	{
			
			strcpy(acc[i++],c[j++]);
	}
}
