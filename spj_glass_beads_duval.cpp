#include<stdio.h>
#include<string.h>
char str[10009];
int duval();

int main()
{
	int n;
	scanf("%d",&n);

	while(n--)
	{
		scanf("%s",str);
		printf("%d\n",duval()+1);
	}
}

int duval()
{
	int i=0,j=1,k=0,n,len;
	len = strlen(str);
	n = len<<1;

	while(i+k<n && j+k<n)
	{
		char a,b;
		a = i+k>=len ? str[i+k-len]:str[i+k];
		b = j+k>=len? str[j+k-len]:str[j+k];

		if(a==b)
			k++;

		else if(a>b)
		{
			i = i + k + 1;
			if(i<=j)
				i = j+1;
			k=0;
		}

		else
		{
			j = j + k +1;
			if(j<=i)
				j = i+1;
			k=0;
		}
	
	}

	return i>j?j:i;
}
		
	