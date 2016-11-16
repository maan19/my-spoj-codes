#include<stdio.h>
int f(int n,int psum);
int str_len();
char a[30];
int memo[30][230];


int main()
{
	int k=1;

	while(1)
	{
		

		scanf("%s",a);

		if(a[0]=='b')
			break;

		for(int i=0;i<30;i++)
			for(int j=0;j<230;j++)
				memo[i][j]=-1;

		printf("%d. %d\n",k++,f(str_len()-1,226));

	}
}

int f(int n,int psum)
{
	if(n==-1)
		return 1;

	if(memo[n][psum]!=-1)
		return memo[n][psum];
		

	int x=0,sum=0;

	for(int i=n;i>=0;i--)
	{
		sum = sum + (a[i]-'0');
		if(sum<=psum)
			x = x+f(i-1,sum);
		else
			break;
	}
	
	return memo[n][psum]= x;
}

int str_len()
{
	int k=0;

	while(a[k]!=NULL)
	{k++;}
	return k;
}