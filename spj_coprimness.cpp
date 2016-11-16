#include<stdio.h>
#include<iostream>
using namespace std;

int gcd(int a,int b);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		for(int i=n/2;i>=0;i--)
		{
			if(gcd(n,i)==1){
				printf("%d\n",i);
				break;
			}
		}

	}
}


int gcd(int a,int b)
{
	if(b==1)
		return a;
	return gcd(b,a%b);
}
