#include<stdio.h>
#include<stack>
#include<limits.h>
#include<algorithm>
long long int height[100000];
int area[100000];
int n;

long long int mx_area();

using namespace std;

int main()
{
	
	scanf("%d",&n);

	while(n!=0)
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&height[i]);
		printf("%lld\n",mx_area());

		scanf("%d",&n);

	}
}

long long int mx_area()
{
	stack<int> S;
	int t;
	long long int m=LLONG_MIN,ar;

	for(int i=0;i<n;i++)
	{
		while(!S.empty())
		{
			if(height[i] <= height[S.top()])
				S.pop();
			else
				break;
		}

		if(S.empty())
			t =-1;
		else
			t = S.top();

		area[i] = i-t-1;

		S.push(i);
	}


	while(!S.empty())
		S.pop();

	for(int i = n-1;i>=0;i--)
	{
		while(!S.empty())
		{
			if(height[i] <= height[S.top()])
				S.pop();
			else
				break;
		}

		if(S.empty())
			t = n;
		else
			t = S.top();

		area[i] = area[i] + (t-i-1);

		S.push(i);
	}

	for(int i=0;i<n;i++)
	{
		m = max(m,(ar = height[i] * (area[i]+1)));
	}

	return m;
}
		



