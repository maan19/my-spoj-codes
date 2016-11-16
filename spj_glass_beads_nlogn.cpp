#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

char A[50008];
int pos[50008];
int prm[50008];
int cnt[50008];
bool bh[50008];
bool b2h[50008];
int nxt[50008];
int h;

int my_cmp(int i,int j);
void suffix_sort();
int str_len();

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",A);
		suffix_sort();
		printf("%d\n",pos[0]+1);
	}
}

int my_cmp(int i,int j)
{
	return A[i]<A[j];
}

void suffix_sort()
{
	int n=str_len();

	for(int i=0;i<n;i++)
		pos[i]=i;

	sort(pos,pos+n,my_cmp);

	/*cout<<"1 sort\n";

	for(int i=0;i<n;i++)
		cout<<pos[i]<<" ";
	cout<<endl;*/

	for(int i=0;i<n;i++)
		prm[pos[i]]=i;

	/*cout<<"prm\n";
	for(int i=0;i<n;i++)
		cout<<prm[i]<<" ";
	cout<<endl;*/

	
	
	for(int i=0;i<n;i++)
	{
			bh[i] = i==0 || A[pos[i]] != A[pos[i-1]];
			b2h[i]=false;
	}

	/*cout<<"bh\n";
	for(int i=0;i<n;i++)
		cout<<bh[i]<<" ";
	cout<<endl;*/

	for(h=1;h<n;h*=2)
	{
		int buckets=0;
		for(int i=0,j;i<n;i=j)
		{
			j=i+1;
			while(j<n && !bh[j])j++;  // nxt is holding the index of start of new bucket..
			nxt[i]=j;
			buckets++;
		}


		if(buckets==n)
			break;

		for(int i=0;i<n;i= nxt[i])
		{
			cnt[i]=0;
			for(int j=i;j<nxt[i];j++)  //making prm point to the start index of bucket to which Ai belongs
				prm[pos[j]]=i;
		}

		/*cout<<"prm\n";
		for(int i=0;i<n;i++)
			cout<<prm[i]<<" ";
		cout<<endl;*/

		
		cnt[prm[n-h]]++;
		b2h[prm[n-h]]=true;

		for(int i=0;i<n;i=nxt[i])
		{
			for(int j=i;j<nxt[i];j++)
			{
			int s = pos[j]-h;
			if(s>=0)
			{
				int head = prm[s];
				prm[s] = head + cnt[head]++;
				b2h[prm[s]] = true;
			}
			}

			for(int j=i;j<nxt[i];j++)
			{
				int s =pos[j]-h;
				if(s>=0 && b2h[prm[s]])
				{
						for(int k = prm[s] + 1; !bh[k] && b2h[k];k++) b2h[k] = false;
				}
			}
		}

		

		for(int i=0;i<n;i++)
		{
				pos[prm[i]]=i;
				bh[i] = b2h[i];
		}

		for(int i=0;i<n;i++)
			prm[pos[i]] =i;
		  
		/*cout<<"sort\n";
		for(int i=0;i<n;i++)
			cout<<pos[i]<<" ";
		cout<<endl;

	
		
		cout<<"bh\n";
		for(int i=0;i<n;i++)
			cout<<bh[i]<<" ";
		cout<<endl;*/


	}
}

int str_len()
{
	int k;
	for(k=0;A[k];k++)
	{}
	return k;
}