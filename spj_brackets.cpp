#include<stdio.h>
char brac[30002];

int main()
{
	int t=1;


	while(t<=10)
	{
		int n;
		scanf("%d",&n);
		
		getchar();
		for(int i=0;i<n;i++)
			scanf("%c",&brac[i]);
		//for(int i=0;i<n;i++)
		//	printf("%c",brac[i]);
		//printf("\n");
		int m;
		scanf("%d",&m);

		printf("TEST %d:\n",t);
		for(int i=0;i<m;i++)
		{
			int k;
			scanf("%d",&k);

			if(k>0)
			{
				if(brac[k-1]=='(')
					brac[k-1]=')';
				else
					brac[k-1]='(';
		//	for(int i=0;i<n;i++)
	//			printf("%c",brac[i]);
	//	printf("\n");
			}

			else
			{
				int flag=0;int f=1;
				
				
				for(int i=0;(i<n)&&(f);i++)
				{
					if(brac[i]=='(')
						flag++;
					else
					{
						if(flag==0)
							f=0;
						else
							flag--;
					}
				}
				
				
				if(f==0 || flag !=0)
					printf("NO\n");
				else
					printf("YES\n");
			}
		}
		t++;
	}
}



