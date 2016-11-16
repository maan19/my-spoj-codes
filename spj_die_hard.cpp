#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int armour,health,count=0;
		int flag1=1;
		scanf("%d""%d",&health,&armour);

		while(1)
		{
			if(flag1)
			{
				health = health +3;
				armour = armour+2;
				flag1=0;
				count++;
			}

			else if(health-5 >0 && armour-10>0)
			{
				health = health -5;
				armour = armour-10;
				flag1=1;
				count++;
			}

			else if(health-20>0 && armour+5>0)
			{
				health = health - 20;
				armour = armour + 5;
				flag1=1;
				count++;
			}

			else
				break;
		}

		printf("%d\n",count);
		
	}
}


