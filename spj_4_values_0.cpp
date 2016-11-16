#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int c=0;
int data[4000][4];
int b[4000*4000];



int main()
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
			scanf("%d %d %d %d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
	
	int k=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			b[k++] = data[i][2] + data[j][3];

	
	sort(b,b+(n*n));

	for(int i=0;i<(n);i++)
		for(int j=0;j<n;j++)
			c = c + upper_bound(b,b+(n*n),(-(data[i][0] + data[j][1])))-lower_bound(b,b+(n*n),(-(data[i][0]+data[j][1])));
	
	printf("%d\n",c);

	return 0;
}