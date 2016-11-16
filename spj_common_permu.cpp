#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;





int main()
{
	char d[1010];
	char a[1010];
	char b[1010];

	while(scanf("%s %s",a,b) ==2)
	{
	
	
	
	sort(a,a+strlen(a));
	sort(b,b+strlen(b));

	int i=0,j=0,k=0;
	
	while(i<strlen(a) && j<strlen(b))
	{
		if(a[i]<b[j])
			i++;
			
		else if(a[i] > b[j])
			j++;

		else
		{
			d[k++]=a[i];
			i++;j++;
		}
	}
	d[k] = NULL;

	
	for(int i=0;i<strlen(d);i++)
		printf("%c",d[i]);
	printf("\n");
	}
	
}

