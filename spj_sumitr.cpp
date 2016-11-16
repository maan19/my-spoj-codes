#include<iostream>
int data[101][101];unsigned long long int memo[101][101];int rows;

unsigned  long long int max(int row,int col)
{if(row==(rows-1))
return data[row][col];
if(memo[row][col] !=-1)return memo[row][col];
unsigned long long int x=max(row+1,col);
unsigned long long int y = max(row+1,col+1);
return( memo[row][col] = data[row][col] + (x>y?x:y));}

int main(){int t;scanf("%d",&t);
while(t--)
{scanf("%d",&rows);
for(int i=0;i<rows;i++)
	for(int j=0;j<=i;j++)
		scanf("%d",&data[i][j]);
for(int i=0;i<rows;i++)
	for(int j=0;j<rows;j++)
		memo[i][j]=-1;
printf("%llu\n",max(0,0));}}



