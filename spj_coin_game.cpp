#include<stdio.h>
int k ,l,m;
int win(int c,int t);
int memo[1000000][2];
int main()
{
	
	scanf("%d" "%d" "%d",&k,&l,&m);
	
	for(int i=1;i<=25;i++)
	{
		int coins=i;
		

		for(int i=1;i<=coins;i++)
			{
				for(int j=0;j<2;j++)
					memo[i][j]=-1;
		}

		

		int j = win(coins,1);
		printf("j %d\n",j);
		if(j%2!=0)
			printf("A");
		else
			printf("B");
	}
	printf("\n");
}

int win(int c,int t)
{
	if(c==k || c==l||c==1)
		return t;
	if(t%2==0)
		{
			printf("memo\n");
			if(memo[c][0]!=-1)
				return memo[c][0];
	}
	else
		if(memo[c][1]!=-1)
			{
				printf("memo\n");
				return memo[c][1];
		}
		
		
	int x ,y=-1,z=-1;
	printf("running\n");
	t++;
	x= win(c-1,t);
	if(c-k>0)
		 y= win(c-k,t);
	if(c-l>0)
		 z = win(c-l,t);
	if(t==2)
		printf(" %d %d %d \n",x,y,z);
	t--;
	 if(t%2!=0)
	 {
		 if(x%2!=0 || y>0 && y%2!=0 || z>0 && z%2!=0)
			 return memo[c][1]=t;
		 
		 else
			 return memo[c][1]=t+1;
	 }

	 else
	 {
		 if(x%2 ==0 || y>0&& y%2 == 0 || z>0 && z%2==0)
			 return memo[c][0]=t;
		 else
			 return memo[c][0]=t+1;
	 }
}