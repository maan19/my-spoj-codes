#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 35000
short int  que[MAX];
int lucky[3001];


int main()
{
	

	for(int i=2;i<MAX;i++)
		que[i]=2;

	for(int i=2;i!=1;)
	{
		que[i]=0;
		int cnt=0;
		for(int j=i+1;j<MAX;j++)
		{
			if(que[j]==2)
				cnt++;
			if(cnt==i)
			{
				que[j]=1;
				cnt=0;
			}
		}
		int first=1;
		for(int k=first+1;k<MAX;k++)
		{
			if(que[k]==2)
			{
					first =k;
					break;
			}
		}
		i=first;
		
	}

	int j=1;
	for(int i=2;i<MAX;i++)
	{
		if(que[i]==0)
			lucky[j++]=i;
	}

	//printf("%d\n",j);



	int n;
	scanf("%d",&n);


	while(n)
	{
		printf("%d\n",lucky[n]);
		scanf("%d",&n);
	}
}
