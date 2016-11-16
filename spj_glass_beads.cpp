#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
char data[10005];

int main()
{
	int n;
	scanf("%d",&n);
	int count,mx=0,index;

	
	
	
	while(n--)
	{
		scanf("%s",data);
		count=0;
		mx=0;


		for(int i=0;i<strlen(data);i++)
		{
			for(int j=0;j<strlen(data);j++)
			{
				int k=0,l=0,c=0,flag1=1,flag2=1;
				k=i;l=j;
				while(c!=strlen(data)+1 && flag1 && flag2)
				{
					if(data[k]<data[l])
						flag1=0;
					else if(data[k]>data[l])
						flag2=0;

						k++;l++;c++;
					if(k==strlen(data))
						k=0;
					if(l==strlen(data))
						l=0;
				}

				if(!flag1)
					count++;
					
			}

			index = count>mx?i:index;
			mx = count>mx?count:mx;
			count=0;

			
		}

		printf("%d\n",index+1);
	}
}







				
				




		


