#include<stdio.h>
#include<iostream>
#define INF 199999;
using namespace std;
int pp[100009];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int a,b;
		scanf("%d""%d",&a,&b);

		for(int i=1;i<=a;i++)
			scanf("%d",&pp[i]);
	
		int ewin,sum=0;
		
		for( ewin=1;sum<=b;ewin++)
			sum = sum +pp[ewin];
		ewin--;
		sum = sum - pp[ewin];
		ewin--;

		int swin=1,mx=ewin-1+1,mxsum=sum;
		ewin++;
		while(ewin<=a)
		{
			sum = sum - pp[swin++];
			sum = sum + pp[ewin++];
			if(sum<b)
			{
				
				while(sum<=b && ewin<=a)
					sum = sum + pp[ewin++];

				
				if(sum>b)
				{
					sum = sum -pp[ewin-1];
					ewin--;
					
				}
				
				mx = ewin-swin>mx?ewin-swin:mx;

				if(ewin - swin == mx)
					mxsum = sum<mxsum?sum:mxsum;
				else
					mxsum =sum;
				
			}

		
		}

		printf("%d %d\n",mxsum,mx);
	}
}




			


