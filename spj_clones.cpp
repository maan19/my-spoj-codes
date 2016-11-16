#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

string d[20009];
int person[20009];


int main()
{
	int n,m;

	while(1)
	{
		scanf("%d""%d",&n,&m);

		if(n==0&&m==0)
			break;

		for(int i=0;i<n;i++)
			cin>>d[i];

		sort(d,d+n);


		for(int i=0;i<n;i++)
			person[i]=0;

		int j=0;
		for(int i=0;i<n-1;i++)
		{
			if(d[i]==d[i+1])
				j++;
			else
			{
				person[j]++;
				j=0;
			}
		}
		

		if(d[n-1]!=d[n-2])
			person[0]++;

		if(j!=0)
			person[j]++;


		for(int i=0;i<n;i++)
			printf("%d\n",person[i]);
	}
}
