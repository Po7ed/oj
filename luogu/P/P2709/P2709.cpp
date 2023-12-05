#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N=51145;

int n,m,k,S;
int a[N];

inline int bel(int x){return (x-1)/S+1;}

struct query
{
	int l,r,id;
	friend inline bool operator < (query x,query y)
	{
		if(bel(x.l)!=bel(y.l))return bel(x.l)<bel(y.l);
		if(bel(x.l)&1)return x.r<y.r;
		else return y.r<x.r;
	}
};
query q[N];

int c[N],s,ans[N];
void mt()
{
	S=int(ceil(pow(n,0.5)));
	sort(q+1,q+m+1);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		#define q q[i]
		if(abs(q.l-l)+abs(q.r-r)>(r-l+1)+(q.r-q.l+1))
		{
			while(l<=r)s+=(-2*(c[a[r--]]--)+1);//clr
			r=(l=q.l)-1;
		}
		while(q.l<l)s+=(2*(c[a[--l]]++)+1);
		while(r<q.r)s+=(2*(c[a[++r]]++)+1);
		while(l<q.l)s+=(-2*(c[a[l++]]--)+1);
		while(q.r<r)s+=(-2*(c[a[r--]]--)+1);
		ans[q.id]=s;
		#undef q
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	mt();
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}