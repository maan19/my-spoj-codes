#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int entry[107];
int ext[107];

int main()
{
	int t;
	scanf("%d",&t);
	

	while(t--)
	{
		int a,b,max_exit=INT_MIN,max_p=0,c=INT_MIN;
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
		scanf("%d""%d",&a,&b);
		entry[i] = a;
		ext[i] = b;
		max_exit = max(max_exit,b);
		}

		//printf("max exit is %d\n",max_exit);

		for(int i=0;i<=max_exit;i++)
		{
			int j;
			for(j=0;j<n;j++)
			{
				if(entry[j]==i)
				{
					(max_p)++;
					break;
				}
			}

			if(j==n)
			{
				for(int k=0;k<n;k++)
				{
					if(ext[k]==i)
					{
						(max_p)--;
						break;
					}
				}
			}

			c= max(c,max_p);
		}

			printf("%d\n",c);
		}
}