#include<iostream>
#include<deque>
int data[1000002];

using namespace std;

void alg(int k,int n);

int main()
{
	int n,k;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);

	scanf("%d",&k);
	alg(k,n);

	return 0;

}

void alg(int k,int n)
{
	deque <int> q(k);

	for(int i=0;i<k;i++)
	{
		while((!q.empty()) && data[i] >= data[q.back()])
			q.pop_back();

		q.push_back(i);
	}


	for(int i=k;i<n;i++)
	{
		printf("%d ",data[q.front()]);



		while((!q.empty()) && q.front() <= i-k)
			q.pop_front();

		
		while((!q.empty()) && data[i] >= data[q.back()])
			q.pop_back();

		q.push_back(i);
	}

	printf("%d\n",data[q.front()]);

	
}


