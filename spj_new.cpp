#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define	gi(a)		scanf("%d",&a)
#define	Int(a)		int a;ri(a);
#define Pair		pair <int,int>
#define mp		make_pair
#define ll		long long
#define INF		2147483647
#define clear(a)	memset(a,0,sizeof(a))
#define dbg(x) 		cerr<<#x<<" ="<<(x)<<endl
#define max(a,b)	(a>b)?a:b
#define min(a,b)	(a<b)?a:b
#define min3(a,b,c)	(a<min(b,c))?a:min(b,c)
#define pb		push_back

template <class T>
inline void ri(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}
struct node{
	int x,y,d;
};
int main(){
	int i,j,k=1;
	Int(h);Int(b);
	char map[55][55];
	int maxdepth=-1;
	while(h!=0 && b!=0){
		maxdepth=-1;
		queue<node> Aq;
		for(i=0;i<h;i++){
			scanf("%s",map[i]);
			for(j=0;j<b;j++){
				if(map[i][j]=='A'){
					Aq.push((node){i,j,1});
				}
			}
		}
		while(!Aq.empty()){
			queue<node> bfsq;
			bool visits[55][55]={{0}};
			node X=Aq.front();
			bfsq.push(X);
			Aq.pop();
			while(!bfsq.empty()){
				node tmp=bfsq.front();
				bfsq.pop();
				if(tmp.x<0 || tmp.y<0 || tmp.x>=h || tmp.y>=b)	continue;
				if(visits[tmp.x][tmp.y])	continue;			
				visits[tmp.x][tmp.y]=1;
				//cout<<"visited "<<tmp.x<<" "<<tmp.y<<endl;
				maxdepth=(tmp.d>maxdepth)?tmp.d:maxdepth;
				for(i=-1;i<=1;i++)
					for(j=-1;j<=1;j++)
						if(tmp.x+i>=0 && tmp.y+j>=0 && tmp.x+i<h && tmp.y+j<b)
							if(map[tmp.x+i][tmp.y+j]==(map[tmp.x][tmp.y]+1)){
								//cout<<"pusher"<<tmp.x+i<<" "<<tmp.y+j<<endl;
								bfsq.push((node){tmp.x+i,tmp.y+j,tmp.d+1});
							}
			}
		}
		if(maxdepth==-1)printf("Case %d: %d\n",k++,0);
		else		printf("Case %d: %d\n",k++,maxdepth);
		ri(h);ri(b);
	}
	return 0;
}