#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
bool even(string s,int l);
int main()
{
	int d;
	scanf("%d",&d);
	while(d--)
	{
		string s;
		cin>>s;
		//cout<< s<<endl;
		int l =s.length();
		if(l==1)
		{
				printf("NO\n");  
				continue;
		}
 
		if((l%2)==0)
		{
			if(even(s,l))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			int i;
			for(i=0;i<l;i++)
			{
				string a = s.substr(i+1) + s.substr(0,i);
				if(even(a,l-1))
				{
						printf("YES\n");
						break;
				}
			}
			if(i==l)
				printf("NO\n");
		}
	}
}
 
bool even(string s,int l)
{
	string a = s.substr((l/2));
	string b = s.substr(0,(l/2));
	/*cout << " a is "<< a<<endl;
	cout<<" b is "<<b<<endl;*/
	return (a==b);
}