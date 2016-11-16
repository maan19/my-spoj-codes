#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int height[100000];

int main()
{
	int n,mn,mx,area;
	scanf("%d",&n);

	while(n!=0)
	{
		mn=INT_MAX;
		mx=INT_MIN;

	for(int i=0;i<n;i++)
		scanf("%d",&height[i]);

	for(int i=0;i<n;i++)
	{
		mx = max(mx,height[i]);
		mn =height[i];

		for(int j=i+1;j<n;j++)
		{
			area = (mn=min(mn,height[j]))*(j+1-i);
			mx = max(mx,area);
		}
	}

	printf("%d\n",mx);
	scanf("%d",&n);
	}  
}

