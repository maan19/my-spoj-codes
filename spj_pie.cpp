#include<stdio.h>
#include<iostream>
#include<algorithm>
#define PIE 3.14159265358979323846264338327950

using namespace std;
double pie[10008];

long double mx;
int main()
{
	int t,N,F,r;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d""%d",&N,&F);
		F=F+1;
		mx = -1.1;

		for(int i=0;i<N;i++)
		{
			scanf("%d",&r);
			pie[i] = PIE * r*r;
		}

		sort(pie,pie+N);

		cout<<"soretd \n";
		for(int i=0;i<N;i++)
			cout<<pie[i]<<endl;
		int c=0,x=0,f;

		for(int i=0;i<N;i++)
		{
			c=1;
			for(long double  j=pie[i],f=1;c!=F && j>mx;j=j/f)
			{
				c=f;
				cout<<"j is "<<j<<endl;

				for(int k=i+1;k<N && c!=F;k++)
				{
					x = pie[k]/j;
					if(x==0)
						break;
					c =c+x;
					cout<<"c is " <<c<<endl;
					cout<<"x s "<<x<<endl;
				}

				if(c==F)
					mx = j;
				cout<<"mx is "<<mx<<endl;
				f++;
			}
		}

		cout<<mx<<endl;
	}
}

			


