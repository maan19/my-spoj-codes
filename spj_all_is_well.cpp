#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
string data[105];
string s = "ALLIZZWELL";
int r1,c1;
int visited[105][105];
bool dfs(int i,int j,int p);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>> r1>>c1;
		for(int i=0;i<r1;i++)
			cin>>data[i];
		bool flag = true;
		for(int i=0;i<r1 && flag ;i++)
		 {
			 for(int j=0;j<c1&& flag;j++)
	           {
				   if(data[i][j]=='A')
					  { if(dfs(i,j,1))
						   printf("YES\n"),flag=false;
					   else
						   memset(visited,0,sizeof(visited));
				   }
			 }
		}
		if(flag ==true)
			printf("NO\n");
	}
}
bool dfs(int i,int j,int p)
{
	if(p==10)
		return true;
	visited[i][j]=1;
	bool flag=true;
	for(int r=-1;r<2;r++)
	{
		for(int c=-1;c<2;c++)
		{
			if(i+r<0 || i+r ==r1 || j+c<0 || j+c == c1||(r==0 && c==0))
				continue;
			if(visited[i+r][j+c]==0 && s[p]==data[i+r][j+c])
				if(dfs(i+r,j+c,p+1)){/*visited[i][j]=0;*/return true;}
		}
	}
	visited[i][j]=0;
	return false;
}
	