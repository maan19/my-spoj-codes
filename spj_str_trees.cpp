#include<stdio.h>
int dis[100009];
int gcd(int a,int b);

int main()
{
	int n;
	scanf("%d",&n);
	int nw,old=0;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&nw);
		dis[i] = nw-old>0?nw-old:old-nw;
		old=nw;
	}


	/*printf("dis array is:\n");
	for(int i=1;i<n;i++)
		printf("%d  ",dis[i]);
	printf("\n");*/

	 int s=0;

	
	
		
		int t=dis[1],x,y;
		
		for(int i=2;i<n;i++)
		{
			
			x = dis[i]>t?dis[i]:t;
			y= dis[i]<t?dis[i]:t;
			t=gcd(x,y);
		}

		//printf("gcd %d\n",x);

		for(int i=1;i<n;i++)
		{
			s = s + ((dis[i]/t)-1);
		}

		printf("%d\n",s);
	
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return (gcd(b,a%b));
}








