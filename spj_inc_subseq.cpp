#include<stdio.h>
#include<iostream>
using namespace std;
int n,k;
int data[10008];
int cnt=0;
void f(int pi,int p,int pn);
int main()
{
	scanf("%d""%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&data[i]);
	f(0,1,-1);
	printf("%d\n",cnt%5000000);
}

void f(int pi,int p,int pn)
{
	if(p==(k+1))
	{
		cnt = (cnt+1)%5000000;
		return;
	}
	for(int i=pi+1;i<=n-(k-p);i++)
		if(data[i]>pn)
			f(i,p+1,data[i]);
}

