#include<stdio.h>
#include<string>
#include<iostream>
#include<string>

using namespace std;


int main()
{
	int n;char y;
	scanf("%d",&n);
	int quo=1,num,rem;
	num = n;
	string s=" ";
	

	while(quo)
	{
		quo = num/-2;
		
		rem = num%-2;
		
		if(rem<0)
			rem+=2;
		if(num<0 && rem!=0)
			quo++;
		num =quo;
		y =rem + '0';
		
		s = s+ y;
	}

	for(string::reverse_iterator  it = s.rbegin();it!=s.rend();it++)
		cout<<(*it);
	cout<<endl;
}

	
	


	

	
	
