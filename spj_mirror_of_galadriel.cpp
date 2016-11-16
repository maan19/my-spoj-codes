#include<stdio.h>
#include<string.h>
char data[11];

int main()
{
	int t;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%s",data);
		int i,j;
		for(i=0,j=strlen(data)-1;i<j;i++,j--)
		{
			if(data[i] !=data[j])
				break;
			
		}

		if(i>=j)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
