#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX ((2*131072)-1)

typedef long long ll;

ll tree[MAX];
ll lazy[MAX];

ll query(ll id,ll a,ll b,ll i,ll j);
void update(ll id,ll a,ll b,ll i,ll j,ll v);

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,c;
		cin >> n >> c;

		for(ll i =1;i<=MAX;i++)
		{
			tree[i]=0;
			lazy[i]=0;
		}

		for(ll i=1;i<=c;i++)
		{
			ll p,q,v,k;

			cin >> k;

			if(k)
			{
				cin >> p>>q;
				cout<<query(1,1,n,p,q)<<endl;
			}

			else
			{
				cin >> p >> q>> v;
				update(1,1,n,p,q,v);
			}
		}
	}
}

void update(ll id,ll a,ll b,ll i,ll j,ll v)
{
	if(lazy[id])
	{
		tree[id] += lazy[id] * (b-a+1);

		if(a!=b)
		{
			lazy[2*id] += lazy[id];
			lazy[2*id + 1] += lazy[id];
		}

		lazy[id] = 0;
	}

	if(a > b || j < a || i > b)
		return;

	if(a>=i && b<=j)
	{
		tree[id] += v*(b-a+1);
		if(a!=b)
		{
			lazy[2*id] += v;
			lazy[2*id+1] += v;
		}

		return;
	}

	ll mid = (a + b)/2;

	update(2*id,a,mid,i,j,v);
	update(2*id+1,mid+1,b,i,j,v);

	tree[id] = tree[2*id] + tree[2*id+1];
}

ll query(ll id,ll a,ll b,ll i,ll j)
{
	if(a > b || a > j || b < i)
		return 0;

	if(lazy[id])
	{
		tree[id] += (b-a+1)*lazy[id];

		if(a!=b)
		{
			lazy[2*id] += lazy[id];
			lazy[2*id+1] += lazy[id];
		}

		lazy[id] =0;
	}

	if(a>=i && b<=j)
		return tree[id];

	ll mid = (a+b)/2;

	ll ret1,ret2;

	ret1 = query(2*id,a,mid,i,j);
	ret2 = query(2*id+1,mid+1,b,i,j);

	return ret1 + ret2;
}




	
