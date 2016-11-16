#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
char s1[12];
char s2[12];
map<char,int>M;
map<int,char>L;
int s_to_i(char *s);
void i_to_s(int k);
int str_len(char *s);
int main()
{
	int n;
	scanf("%d",&n);

	M['m'] =1000;
	M['c']=100;
	M['x']=10;
	M['i'] =1;

	L[1000] = 'm';
	L[100]='c';
	L[10]='x';
	L[1]='i';

	for(int i=1;i<=n;i++)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		//printf("%s  %s\n",s1,s2);
		int num = s_to_i(s1) + s_to_i(s2);
		//printf("%d  %d\n",s_to_i(s1),s_to_i(s2));
		i_to_s(num);
	}
}

int s_to_i(char *s)
{
	int sum=0,d=0;

	for(int i=0;i<str_len(s);i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			(sum = sum + ((d==0)?M[s[i]]:M[s[i]]*d));
			d=0;
		}
		else
			d = s[i]-'0';
	}

	return sum;
}

void i_to_s(int k)
{
	char ans[15];
	int i=0;

	for(int x=1000;x>0;x=x/10)
	{
		if(k/x==0)
			continue;
		else
		{
			if(k/x!=1)
				ans[i++] = (k/x)+'0';
			ans[i++] = L[x];
			k = k%x;
		}
	}
	ans[i]=NULL;
	printf("%s\n",ans);
}

int str_len(char *s)
{
	int i;
	for(i=0;s[i]!=NULL;i++)
	{}

	return i;
}



		
