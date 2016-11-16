#include<iostream>
#include<algorithm>
int set[103];
int A[1000005];
int B[1000005];
int C[1000005];
int D[1000005];

using namespace std;
void merge(int * org,int * cpy,int s1,int e1,int s2,int e2);
void merge_sort(int *a,int * cpy,int m,int start,int end);
int intersec(int m,int n);

int main()
{
	int t;
	scanf("%d",&t);

	for(int i=0;i<t;i++)
		scanf("%d",&set[i]);
	
	int m=0,n=0;
	
	for(int i=0;i<t;i++)
	{
		for(int j=i;j<t;j++)
		{
			for(int k=0;k<t;k++)
			{
				int v;
				A[m++] = v=set[i]*set[j]+set[k];
				if(j>i)
					A[m++] = v;
				
			}
		}
	}

	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			for(int k=j;k<t;k++)
			{
				if(set[i] !=0 && k==j)
					B[n++] = set[i]*(set[j] + set[k]);
				else if(set[i] !=0 && k>j)
				{
					int v;
					B[n++] = v = set[i]*(set[j] + set[k]);
					B[n++] = v;
				}
			}
		}
	}
			
	
	
	
	merge_sort(A,C,m,0,m-1);

	merge_sort(B,D,n,0,n-1);
	
	
	printf("%d\n",intersec(m,n));

	return 0;
}






void merge_sort(int *a,int * cpy,int m,int start,int end)
{
	if(m==1)
		return;

	int mid = (start + end)/2;

	

	

	merge_sort(a,cpy,mid-start +1,start,mid);
	merge_sort(a,cpy,end-(mid+1)+1,mid+1,end);
	merge(a,cpy,start,mid,mid+1,end );
	  
	
}

void merge(int * org,int * cpy,int s1,int e1,int s2,int e2)
{
	int i=s1,j=s2,k=0;

	while((i != e1+1  && j != e2+1))
	{
		if(org[i]<=org[j])
			cpy[k++] = org[i++];
		else
			cpy[k++] =org[j++];
	}

	while(i!=e1+1)
	{
		cpy[k++] = org[i++];
	}

	while(j!=e2+1)
	{
		cpy[k++]= org[j++];  
	}

	for(int i= 0;i<k;i++)
	{
		org[s1++] = cpy[i];
	}


}

int intersec(int m,int n)
{
	int i=0,j=0,count=0;
	while(!(i == m || j==n))
	{
	if(A[i] < B[j])
		i++;

	if(A[i] > B[j])
		j++;

	else if(A[i] == B[j])
	{
		int c1=0,c2=0,temp;
		temp = A[i];

		while(A[i] == temp && i !=m)
		{
			c1++;
			i++;
		}
		while(B[j] == temp && j!=n)
		{
			c2++;
			j++;
		}

		count = count + c1*c2;
		
	}
	}
	
	return count;
}













				





