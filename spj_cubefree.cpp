#include<stdio.h>
#include<iostream>

using namespace std;

int cube[102];
int series[1000003];

int main()
{
	for(int i=2;i<=100;i++)
		cube[i] = i*i*i;
	
	int count =1,flag=1;

	for(int i=1;i<=1000000;i++)
	{
		flag =1;
		for(int j=2;j<=100 && cube[j]<=i;j++)
		{
			if(i%cube[j]==0)
			{
					flag =0;
					break;
			}
		}

		if(flag==1)
			series[i]=count++;
		else
			series[i]=0;
	}
	
	int t;
	scanf("%d",&t);

	int k=1;

	while(t--)
	{
		int n;
		scanf("%d",&n);

		if(series[n])
			printf("Case %d: %d\n",k++,series[n]);

		else
			printf("Case %d: Not Cube Free\n",k++);
	}
}
		
