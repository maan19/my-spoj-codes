#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int seq[21];
int n,k;
bool check(char * a);
int fun(int i,char * a);



int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
	
		scanf("%d %d",&n,&k);
		

		for(int i=0;i<k;i++)
			scanf("%d",&seq[i]);
		char *a = new char [2*n+1];

		for(int i=1;i<=2*n;i++)
			a[i]='[';
		
		printf("%d\n",fun(1,a));
	}
}

int  fun(int i,char * a)
{

	int sum=0;


	for(int j=i+1;j<=(2*n);j++)
	{
		char * b =new char [2*n+1];
		if(binary_search(seq,seq+k,j))
			continue;
		for(int k=1;k<=2*n;k++)
			b[k] = a[k];
		b[j] = ']';

		/*printf("passing :\n");
		for(int i=1;i<=2*n;i++)
			printf("%c",b[i]);
		printf("\n");*/

		sum = sum +(fun(j,b));
		
	}
	return sum + check(a);
}

bool check(char * a)
{
	int cnt1=0,cnt2=0,flag =1;

	for(int i=1;i<=(2*n) &&flag ;i++)
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





