#include<stdio.h>
#include<limits.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<unordered_set>
using namespace std;
int seq[21];
int n,k,c=0;
bool check(string  a);
void fun(int i,string s);

unordered_set<int > m;




int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
	
		scanf("%d %d",&n,&k);
		c=0;
		
		int d;
		for(int i=0;i<k;i++)
		{
				scanf("%d",&d);
				m.insert( d-1);
		}

		string s;

		for(int i=0;i<2*n-1;i++)
			s = s + '[';

		s = s + ']';

		
		
			
		fun(2*n-2,s);
		printf("%d\n",c);
	}
}

void fun(int i,string s)
{
	//cout<< "s received is: "<<s<<endl;

	
	if(check(s))
	{
		c++;
		return;
	}
	if(i==0)
		return;

	

	if(m.find(i)!=m.end())
		fun(i-1,s);
	else
		{
			fun(i-1,s);
			s[i] = ']';
			fun(i-1,s);
		}
}

bool check(string a)
{
	int cnt1=0,cnt2=0,flag =1;

	for(int i=0;i<(2*n) &&flag ;i++)
	{
		if(a[i]=='[')
			cnt1++;
		else
		{
			if(cnt1==0)
				flag=0;
			else
				cnt1--;
		}
	
	}

	if(flag==0 || cnt1 !=0)
		return false;
	return true;
	
}
