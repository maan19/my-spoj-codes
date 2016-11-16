#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<map>
#include<unordered_set>
#include<string>

using namespace std;


#define sid(n) scanf("%d",&n)
#define dout(n) printf("%d",n)
#define sil(n) scanf("%lld",&n)
#define lout(n) printf("%lld",n)
#define FOR(n) for(int i=1;i<=n;i++)

typedef long long int LL;
typedef unsigned long long int ULL;
typedef pair<int,int> PII;


char txt[25];

struct node
{
	int prefix;
	int word;
	bool branch;
	node * child[26];
};

void initialise(node *p)
{
	p->prefix=0;
	p->word=0;
	p->branch=false;
	for(int i=0;i<26;i++)
		p->child[i]=NULL;
}

/*void insert(node * p,char * s)
{
	if(s[0]==NULL)
	{
		p->word++;
		p->branch=true;
		return;
	}
	p->prefix++;
	if(p->branch) p->branch=false;
	if(p->child[s[0]-'a']==NULL)
	{
		p->child[s[0]-'a'] = new node;
		initialise(p->child[s[0]-'a']);
	}
	insert(p->child[s[0]-'a'],s+1);
}*/
void insert(node * p,char *s)
{
	for(int i=0;s[i];i++)
	{
		if(p->child[s[i]-'a']==NULL)
		{
			p->child[s[i]-'a']=new node;
			initialise(p->child[s[i]-'a']);
		}
		p->prefix++;
		p=p->child[s[i]-'a'];
	}
	p->word++;
}

void f(node *p,vector<char>s,bool flag)
{
	if(flag==true && p->word>=1)
	{
		for(int i=0;i<s.size();i++)
			printf("%c",s[i]);
		printf("\n");
	}
	if(p->prefix==0)
		return;
	
	for(int i=0;i<26;i++)
		if(p->child[i]!=NULL)
		{
			s.push_back((char)('a'+i));
			f(p->child[i],s,true);
			s.pop_back();
		}
}

/*void prefix_print(char *s,node * p,char *d)
{
	if(*s==NULL)
	{
		if(p->prefix==0)
			printf("No match.\n");
		else
		{
			vector<char> s;
			for(int i=0;d[i]!=NULL;i++)
				s.push_back(d[i]);
			f(p,s,false);
		}
		return;
	}
	if(p->child[*s-'a']==NULL)
	{
		printf("No match.\n");
		return;
	}

	else
		prefix_print(s+1,p->child[*s-'a'],d);
}*/

node * search(node *p,char *s)
{
	for(int i=0;s[i];i++)
	{
		if(p->child[s[i]-'a']==NULL)
			return NULL;
		p=p->child[s[i]-'a'];
	}
	return p;
}








int main()
{
	int t;
	node root;
	initialise(&root);
	sid(t);
	FOR(t)
	{
		scanf("%s",txt);
		insert(&root,txt);
	}

	int k,c=0;
	sid(k);
	FOR(k)
	{
		scanf("%s",txt);
		printf("Case #%d:\n",++c);
		node * t=search(&root,txt);
		if(t==NULL || t->prefix==0)
			printf("No match.\n");
		else
		{
			vector<char> s;
			for(int i=0;txt[i]!=NULL;i++)
				s.push_back(txt[i]);
			f(t,s,false);
		}
	}
}







