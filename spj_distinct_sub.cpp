#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
char S[60000];
using namespace std;
int gap;
int sa[50001];
int pos[50001];
int tmp[50001];
int lcp[50001];
int rnk[50001];
int str_len();
bool suf_cmp(int i,int j);
void build_sa();
void build_lcp();


int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	
	while(t--)
	{
		gets(S);
		cout<<"string is " << S<<endl;


	

	build_sa();
	build_lcp();
	int k=0,n=str_len();
	for(int i=0;i<n;i++)
		k=k+lcp[i];

	printf("%d\n",n*(n+1)/2-k);
	}
}




		



void build_sa()
{
	int gap=1;
	int n = str_len();

	for(int i=0;i<n;i++)
	{
		sa[i] = i;
		pos[i]=S[i];
	}

	tmp[0]=0;
	cout<<"sa called\n";  
	int g;
	for(gap=1,g=0;g<7;gap*=2,g++)
	{
		sort(sa,sa+n,suf_cmp);
		
		cout<<"sort\n";
		for(int i=0;i<n;i++)
			cout<<sa[i]<<" " ;

		for(int i=0;i<n-1;i++)
			tmp[i+1]=tmp[i]  + suf_cmp(sa[i],sa[i+1]);

		cout<<"tmp\n";
		for(int i=0;i<n;i++)
			cout<<tmp[i]<<"  ";
	

		for(int i=0;i<n;i++)
			pos[sa[i]]=tmp[i];

		if(tmp[n-1]==n-1)
			break;
	}
	printf("sa built\n");
}

void build_lcp()
{
	int n = str_len();

	for(int i=0;i<n;i++)
		rnk[sa[i]] = i;

	for(int i=0, k=0;i<n;i++,k?k--:0)
	{
		if(rnk[i]==0)
		{
			lcp[0]=0;
			k=0;
			continue;
		}

		int j= sa[rnk[i]-1];
		while(i+k<n && j + k<n && S[i+k]==S[j+k])
			k++;
		lcp[rnk[i]]=k;
		printf("lcp %d is %d\n",rnk[i],k);
	}

	
}
			








bool suf_cmp(int i,int j)
{
	if(pos[i]!=pos[j])
		return pos[i]<pos[j];

	i = i + gap;
	j= j + gap;
	int n= str_len();

	return (i<n && j<n)? pos[i] < pos[j]:i>j;
}



int str_len()
{
	int k=0;

	while(S[k]!=NULL)
		k++;
	cout<<"strlen is "<<k<<endl;
	return k;
}











