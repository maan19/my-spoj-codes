#include<stdio.h>
#include<queue>
#include<map>

using namespace std;

  
int a,b,c;
long int bfs(int x,int y);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		
		scanf("%d""%d""%d",&a,&b,&c);
		printf("%ld\n",bfs(0,0));
	}

}


long int bfs(int x,int y)
{
	queue<int> q;
	map <pair<int,int>,int> m;

	long int level;
	
	q.push(x);
	q.push(y);
	q.push(0);
	m.insert(make_pair(make_pair(x,y),1));
	
	while(!q.empty())
	{
		int A,B;
		A=q.front();
		q.pop();
		B=q.front();
		q.pop();
		level=q.front();
		q.pop();
		
		if(A==c || B == c)
			break;  
		
		if(A==0 &&m.find(make_pair(a,B))== m.end() )
		{
				q.push(a);
				q.push(B);
				q.push(level+1);
				m.insert(make_pair(make_pair(a,B),1));
		}

		if(B==0 && m.find(make_pair(A,b)) == m.end())
		{
				q.push(A);
				q.push(b);
				q.push(level+1);
				m.insert(make_pair(make_pair(A,b),1));
		}

		if(A!=0 && m.find(make_pair(0,B)) == m.end())
		{
				q.push(0);
				q.push(B);
				q.push(level+1);
				m.insert(make_pair(make_pair(0,B),1));
		}

		if(B!=0 && m.find(make_pair(A,0))==m.end())
		{
				q.push(A);
				q.push(0);
				q.push(level+1);
				m.insert(make_pair(make_pair(A,0),1));
		}

		if(b-B>=A && m.find(make_pair(0,A+B))==m.end())
		{
			q.push(0);
			q.push(A+B);
			q.push(level + 1);
			m.insert(make_pair(make_pair(0,A+B),1));
		}

		else if(b-B<A && m.find(make_pair(A-(b-B),b)) ==m.end())
		{
			q.push(A-(b-B));
			q.push(b);
			q.push(level+1);
			m.insert(make_pair(make_pair(A-(b-B),b),1));
		}

		if(a-A>=B && m.find(make_pair(A+B,0))==m.end())
		{
			q.push(A+B);
			q.push(0);
			q.push(level+1);
			m.insert(make_pair(make_pair(A+B,0),1));
		}

		else if(a-A < B && m.find(make_pair(a,B-(a-A)))==m.end())
		{
			q.push(a);
			q.push(B-(a-A));
			q.push(level+1);
			m.insert(make_pair(make_pair(a,B-(a-A)),1));
		}
	} 
	if(q.empty())
		return -1;
	return level;
}


