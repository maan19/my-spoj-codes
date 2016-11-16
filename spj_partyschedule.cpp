#include<iostream>
#include<string.h>
using namespace std;





int main()
{
	int parties,budget;
	int price[200];
    int fun[200];
    int dp[502][200];
    int bud[502][200];
	char a[10000];

	
	
	while(1)
	{
		scanf("%d %d",&budget,&parties);

		if(budget==0 && parties==0)
			break;  
		

		for(int i=1;i<=parties;i++)
		{
			scanf("%d %d",&price[i],&fun[i]);
		}
		
		for(int j =0;j<=budget;j++)
		{
				dp[0][j]=0;
				bud[0][j]=0;
		}
		
		for(int i=0;i<=parties;i++)
		{
			dp[i][0]=0;
			bud[i][0]=0;
		}

		for(int i =1;i<=parties;i++)
		{
			int x,y,m,n;
			for(int j=1;j<=budget;j++)
			{
				if(price[i]<=j)
				{
					   x= fun[i] + dp[i-1][j-price[i]];
					   m= price[i] + bud[i-1][j-price[i]];
					   n= bud[i-1][j];
					   y= dp[i-1][j];

					if(x>y)
					{
						dp[i][j]=x;
						bud[i][j]=m;
					}

					else if(x==y)
					{
						dp[i][j]=x;
						bud[i][j] = m<n?m:n;
					}

					else
					{
						dp[i][j]=y;
						bud[i][j]=n;
					}
				}

				else
				{
					y=dp[i-1][j];
					n=bud[i-1][j];
					dp[i][j]=y;
					bud[i][j]=n;
				}
			}
		}
		

		printf("%d %d\n",bud[parties][budget],dp[parties][budget]);
		getchar();  
		gets(a);
}
	return 0;
	
}




