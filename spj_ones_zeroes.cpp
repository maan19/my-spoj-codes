#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct data
{
	char b;
	int m;
};

vector<data> g;
vector<char> s;


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		int k;
		for(k=n;k!=0;k=k/10)
		{
			if((k%10) > 1)
				break;
		}

		if(k==0)
			printf("%d\n",n);

		else
		{
			data a,b,c;
			a.b='1';a.m = 1%n;
			b.b='0';b.m=(10%n);
			c.b ='1';c.m=(b.m)+1;
			
			g.push_back(a);
			g.push_back(b);
			g.push_back(c);



			int i;
			for(i=1;;i++)
			{
				if(g[i].m==0)
				{
						//cout<< "for i " << i << "m is "<<g[i].m << " bit is "<<g[i].b<<endl;
						break;
				}

				data left,right;
				left.b='0';left.m = ((g[i].m)%n * (10%n))%n;
				right.b='1';right.m  = (left.m + 1)%n;
				g.push_back(left);
				g.push_back(right);
			}

			//printf("here\n");
			for(int j=i;j>=1;j=(j-1)/2)
				s.push_back(g[j].b);
			s.push_back(g[0].b);

			//printf("ggg\n");
			for(int j=s.size()-1;j>=0;j--)
				printf("%c",s[j]);
			printf("\n");
		}

		g.clear();s.clear();
	}
}
			








