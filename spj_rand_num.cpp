#include<stdio.h>
#include<algorithm>
using namespace std;
int data[100000000];

int main()
{
	int n,k,count =0;
	scanf("%d""%d",&n,&k);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	sort(data,data+n);
	for(int i=0;i<n;i++)
	{
		if(binary_search(data,data+n,data[i]+k))
			count++;
	}

	printf("%d\n", count);
}

