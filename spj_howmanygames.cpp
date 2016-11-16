#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

char data[15];
int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{

	scanf("%s",data);
	//cout<<"data ";
	//puts(data);

	int num =0;
	int i,x;
	for(i=strlen(data)-1,x=1;i>=0 && data[i] != '.';i--,x*=10)
	{
		num = num + ((data[i]-'0')*x);
	}

	//cout<<"num is " << num <<endl;

	if(i<0)
		printf("%d\n",1);

	else
	{
			int y=num *1,j;
			for(j=2;(y%x)!=0;j++)
			{
				y= num *j;
			}

			printf("%d\n",j-1);
	}
	}
}

				







	
