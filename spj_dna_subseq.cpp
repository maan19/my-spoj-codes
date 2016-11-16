#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b;
int lcs(int m,int n);
int main()
{
	while(1)
	{
		cin>>a;
		cin>>b;
		printf("%d\n",lcs(a.length()-1,b.length()-1));
	}
}
int lcs(int m,int n)
{
	if(m<0||n<0)
		return 0;
	if(a[m]==b[n])
		return 1+lcs(m-1,n-1);
	return max(max(lcs(m-1,n),lcs(m,n-1)),lcs(m-1,n-1));
}
