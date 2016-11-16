#include<stdio.h>
#include<iostream>
using namespace std;
int t[6];
int result[100009];
int x,k;
bool f(int c,int pc,int a);
bool dp();
int main()
{
	scanf("%d""%d",&x,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&t[i]);
	if(dp())
		printf("YES\n");
	else
		printf("NO\n");
}
bool dp()
{
	for(int i=0;i<=x;i++)
		result[i]=((i%t[1])==0);
	for(int c=2;c<=k;c++)
	{
		for(int i=1;i<=x;i++)
		{
			for(int j=0;(j*t[c]+j*t[c-1])<=i;j++)
			{
				result[i]=result[i-((j*t[c])+(j*t[c-1]))];
			}
		}
	}
	return result[x];
}