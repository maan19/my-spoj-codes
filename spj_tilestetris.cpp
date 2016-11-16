#include<stdio.h>
#include<iostream>
using namespace std;

int gcd(int a,int b);

int main()
{
	int l,w;
	scanf("%d %d",&l,&w);

	while(l!=0 && w!=0)
	{
		int x,y,z;
		x = l>w?l:w;
		y = l<w?l:w;
		z = gcd(x,y);
		printf("%lld\n",(long long)(l/z)*(long long)(w/z));
		scanf("%d""%d",&l,&w);
	}

}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return(gcd(b,a%b));
}