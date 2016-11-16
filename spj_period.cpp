#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int F[1000009];
char s[1000009];
void kmp_failure_function(int l);
int main()
{
	int t,c=1;
	scanf("%d",&t);
	while(t--)
	{
		int l;
		scanf("%d",&l);
		scanf("%s",s);
		kmp_failure_function(l);
		printf("Test case #%d\n",c++);
		for(int i=2;i<=l;i++)
		{
			int p=i-F[i];
			if(F[i]%p==0 && (i/p)>1)
				printf("%d %d\n",i,i/p);
		}
		printf("\n");
	}
}
void kmp_failure_function(int l)
{
	int j;
	F[0]=F[1]=0;
	for(int i=2 ;i<=l;i++)
	{
		j=i-1;
		while(1)
		{
			if(s[i-1]==s[F[j]]){
				F[i]=F[j]+1;
				break;}
			if(j==0)
			{
				F[i]=0;
				break;
			}
			j=F[j];
		}
	}
}

