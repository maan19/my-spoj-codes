#include<stdio.h>
#include<iostream>
using namespace std;

char clue[100];
int d[100];
int str_len();
unsigned long long int lcm();
int mn=0,j=1;

int main()
{
	cin>>clue+1;
	
	while(clue[1]!='*')
	{
		int s=str_len();
		j=1;
		
		for(int i=2;i<=s;i++)
		{
			
			if(clue[i]=='Y')
			{
					d[j++]=i;
			}
					
		}


		/*for(int i=1;i<j;i++)
			printf("%d ",d[i]);
		printf("\n");*/
		
		unsigned long long int l=lcm();
		//printf("lcm %d\n",l);
		int i;
		for( i=1;i<=s;i++)
		{
			if(clue[i]=='N' && l%i==0)
				break;
		}

		if(i==s+1)
			cout<<l<<endl;
		else
			cout<<-1<<endl;
		cin>>clue+1;
	}
}

unsigned long long int lcm()
{
	int flag=1,g=1;
	unsigned long long int ans =1;
	mn= d[1];
	while(g!=40)
	{
		flag=0;
		g=40;
	for(int i=1;i<j;i++)
	{
		if(d[i]%mn==0)
		{
				d[i]=d[i]/mn;
				flag=1;
		}
		if(d[i]!=1)
			g = g<d[i]?g:d[i];
		
	}

	ans = ans * (unsigned long long  )mn;
	mn=g;

	}

	return ans;


}

int str_len()
{
	int i;
	for(i=1;clue[i]!=NULL;i++)
	{}
	return i-1;

}