#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[100009];
int F[100009];
void kmp_failure_function(int l);
int main()
{
	while(1)
	{
		scanf("%s",s);
		int l=strlen(s);
		if(s[0]=='*')
			break;
		kmp_failure_function(l);
		for(int i=l;;)
		{
			if(l%(l-F[i])==0)
			{printf("%d\n",l/(l-F[i]));break;}
			i=F[i];
		}
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