#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<map>
using namespace std;
int vert[1010];
int hor[1010];

int fun(int sv,int ev,int sh,int eh);
map<pair<pair<pair<int,int>,int>,int>,int> m;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int m,n;
		scanf("%d""%d",&m,&n);

		for(int i=1;i<m;i++)
			scanf("%d",&vert[i]);
		for(int j=1;j<n;j++)
			scanf("%d",&hor[j]);

		printf("%d\n",fun(1,m-1,1,n-1));
	}
}  

int fun(int sv,int ev,int sh,int eh)
{
	int sum=0;
	int mx=INT_MAX;
	if(sv>ev)
	{
		for(int i=sh;i<=eh;i++)
			sum = sum + hor[i];
		return sum;
	}

	if(sh>eh)
	{
		for(int i=sv;i<=ev;i++)
			sum = sum + vert[i];
		return sum;
	}
	

	if(m.find(make_pair(make_pair(make_pair(sv,ev),sh),eh))!=m.end())
	{
			printf("map\n");
			return m[make_pair(make_pair(make_pair(sv,ev),sh),eh)];
	}

	for(int i=sv;i<=ev;i++)
		mx = min(fun(sv,i-1,sh,eh)+fun(i+1,ev,sh,eh)+vert[i] ,mx);
	

	for(int i=sh;i<=eh;i++)
		mx = min(fun(sv,ev,sh,i-1) + fun(sv,ev,i+1,eh) + hor[i],mx);
	
	(m.insert(make_pair(make_pair(make_pair(make_pair(sv,ev),sh),eh),mx)));
	return mx;
}




