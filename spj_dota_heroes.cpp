#include<iostream>
#include<limits.h>

using namespace std;
int health[600];


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,m,d,current;
		scanf("%d""%d""%d",&n,&m,&d);

		for(int i=0;i<n;i++)
			scanf("%d",&health[i]);
		int j;
		for(j=0;j<m;j++)
		{
			current =0;
			for(int i=0;i<n;i++)
			{
					if(health[current] < health[i])
					{
						current = i;
						
					}
			}

					if(health[current] > d)
						health[current] -= d;

					else
						break;
			}

		if(j==m)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}







