#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;
char str[45000];
int len[1500];

int main()
{
	int n;
	scanf("%d\n",&n);
	
	

	for(int i=0;i<n;i++)
	{
	
		
		gets(str);
		if(strlen(str)==0)
		{
			i--;
			continue;
		}

		//printf("string : ");
		//puts(str);
		int l=0,j=0;

		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]>=97 && str[i]<=122)
				l++;
			else 
			{
				if(str[i-1]!=' ')
				{
					len[j++]=l;
					l=0;
				}
			}
		}
		len[j++]=l;
		/*printf("len array is :\n");
		for(int i=0;i<j;i++)
		{
			printf("%d  ",len[i]);
		}*/

		//printf("\n");

		int mx=INT_MIN,lcs=1;
		for(int i=1;i<j;i++)
		{
			if(len[i]==len[i-1])
			{
				lcs++;
			}

			else
			{
				mx = max(mx,lcs);
				lcs = 1;
			}
		}
		mx=max(mx,lcs);
		if(j==1)
			printf("%d\n",1);
		else
			printf("%d\n",mx);


		
	}
}



