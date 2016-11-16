#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int row,col;

		scanf("%d""%d",&row,&col);
		 
		if(row%2==0 && col%2!=0)
			{
				if(row >col)
					printf("D\n");
				else
					printf("L\n");
		}
		else if(row%2!=0 && col%2==0)
		{
			if(row<col)
				printf("R\n");
			else
				printf("U\n");
		}

		else if(row%2!=0 && col%2!=0)
		{
				if(row<=col)
					printf("R\n");
				else
					printf("D\n");
		}

		else if(row%2==0  && col%2==0)
			{
				if(row<=col)
					printf("L\n");
				else
					printf("U\n");
		}
		
	}
}