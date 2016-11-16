#include<stdio.h>
#include<algorithm>
using namespace std;

int vert[1010];
int hor[1010];
bool myfun(int i ,int j)
{
	return i>j;
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int m,n;
		scanf("%d""%d",&m,&n);

		for(int i=0;i<m-1;i++)
			scanf("%d",&vert[i]);
		for(int j=0;j<n-1;j++)
			scanf("%d",&hor[j]);

		
		

		sort(vert,vert+(m-1),myfun);
		sort(hor,hor+(n-1),myfun);
		//printf("sort\n");
		/*for(int i=0;i<m-1;i++)
			printf("%d\n",vert[i]);
		printf("\n");
		for(int j=0;j<n-1;j++)
			printf("%d\n",hor[j]);
		printf("\n");*/

		

		int vc=0,hc=0,cost=0;
		int i=0,j=0;

		

		while(i<m-1&&j<n-1)
		{
			if(vert[i]>hor[j])
			{
				cost = cost + vert[i++]*(hc+1);
				vc++;
			}

			else
			{
				cost = cost + hor[j++]*(vc+1);
				hc++;
			}
		}

		while(i<m-1)
		{
			cost = cost + vert[i++]*(hc+1);
		}

		while(j<n-1)
		{
			cost = cost + hor[j++]*(vc+1);
		}

		printf("%d\n",cost);
	}







}