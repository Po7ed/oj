#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
const int N=114514;

//vector<int> e[N];
ll a[N],b[N],c[N];

inline ll gettime(int beg,int id)
{
	double B,A;
	#define a a[id]
	#define b b[id]
	#define c c[id]
	if(c==0)
	{
		A=ceil(1.0*a/b);
		return (ll)A;
	}
	else
	{
		B=1.0*b+1.0*beg*c+1.0*c/2.0;
//		printf("B:%lf\n",B);
		A=sqrt(B*B+2.0*c*a)-B;
		A=A/(1.0*c);
//		printf("A:%lf\n",A);
		return beg+(ll)ceil(A);
	}
	#undef a
	#undef b
	#undef c
}

//int dp[N];
//void dfs(int u,int f)
//{
//	if(e[u].size()==1)
//	{
//		dp[u]=ettime()
//		return;
//	}
//	vector<int> p;
//	for(int v:e[u])
//	{
//		if(v!=f)
//		{
//			dfs(v,u);
//			p.push_back()
//		}
//	}
//}

bitset<N> vis;

int main()
{
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	ll ma=-1,tmp,tt;
	bool B=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",a+i,b+i,c+i);
	}
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		if(u!=i||v!=i+1)
		{
			B=false;
		}
//		e[u].push_back(v);
//		e[v].push_back(u);
	}
	if(B)
	{
		for(int i=1;i<=n;i++)
		{
			tmp=gettime(i,i);
//			printf("%lld\n",tmp);
			ma=max(ma,tmp);
		}
	}
	else
	{
		srand(*(new char));
		for(int i=1;i<=n;i++)
		{
			tt=rand()%n+1;
			while(vis[tt])tt=rand()%n+1;
			tmp=gettime(tt,tt);
			ma=max(ma,tmp);
		}
	}
	printf("%lld",ma);
	return 0;
}
