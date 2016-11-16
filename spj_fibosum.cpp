#include <stdio.h>
#include<malloc.h>
#include<iostream>
#define MOD 1000000007

using namespace std;

unsigned long long int (* mtx(unsigned long long int (*A)[2],unsigned long long int (*B)[2]))[2];
unsigned long long int (*exp(unsigned long long int (*M)[2],int n))[2];

void print_mtc(unsigned long long int(*A)[2]);


unsigned long  long int M[2][2] ={{1,1},{1,0}};
unsigned long long int I[2][2] = {{1,0},{0,1}};


int main()
{
	int t;
	
	unsigned long long int (*A)[2];
	unsigned long long int (*B)[2];
	
	scanf("%d",&t);

	while(t--)
	{
	int n,m;
	scanf("%d""%d",&n,&m);

	A = exp(M,m+1);
	B= exp(M,n);

	

	unsigned long long int c= ((A[0][0]%MOD) - (B[0][0]%MOD)  + MOD)%MOD;
	printf("%llu\n",c);

}
	return 0;
}

	
unsigned long long int (* mtx(unsigned long long int (*A)[2],unsigned long long int (*B)[2]))[2]
{
	unsigned long long int(*C)[2] = (unsigned long long int (*)[2])malloc(sizeof(unsigned long long int)*4);
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			
			C[i][j]=0;
			for(int k=0;k<2;k++)
			{
				C[i][j] = C[i][j] + ((A[i][k]*B[k][j])%MOD);
			}
			
		}
		
	}

	return C;
	
}

unsigned long long int (* exp(unsigned long long int (*M)[2],int n))[2]
{
	unsigned long long int (*D)[2];
	
	if(n==1)
		return M ;
	if(n==0)
		return I;

	if(n%2==0)
	{
		D=exp(M,n/2);
		
		//print_mtc(D);
		
	
		D=mtx(D,D);    
		//printf("m*%d\n",n);
		//print_mtc(D);
		return(D);
	}

	else

	{
		D=exp(M,n-1);
		//printf("m*%d\n",n-1);
		//print_mtc(D);
		D=mtx(M,D);
		//printf("m*%d\n",n);
		//print_mtc(	D);
		return(D);
	}
	
}

void print_mtc(unsigned long long int(*A)[2])
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			printf("%llu  ",A[i][j]);
		printf("\n");
	}
}


