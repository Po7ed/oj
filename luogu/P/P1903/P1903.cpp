#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr int N=214514,A=1145141;
int n,m,S,qm;
int a[N];

inline int bel(int x){return (x-1)/S+1;}

struct query
{
	int l,r,t,id;
	friend inline bool operator < (query x,query y)
	{
		return (bel(x.l)^bel(y.l)?bel(x.l)<bel(y.l):(bel(x.r)^bel(y.r)?bel(x.r)<bel(y.r):x.t<y.t));
	}
};
query q[N];

struct modify
{
	int p,v;
};
modify mo[N];

int cnt[A],bt,ans[N];
void mt()
{
	S=int(ceil(pow(n,0.66)));
	sort(q+1,q+qm+1);
	for(int i=1,l=1,r=0,t=0;i<=qm;i++)
	{
		#define q q[i]
		#define p mo[t].p
		#define v mo[t].v
		while(q.l<l)bt+=(!(cnt[a[--l]]++));
		while(r<q.r)bt+=(!(cnt[a[++r]]++));
		while(l<q.l)bt-=(!(--cnt[a[l++]]));
		while(q.r<r)bt-=(!(--cnt[a[r--]]));
		while(t<q.t){t++;if(l<=p&&p<=r)bt-=(!(--cnt[a[p]])-!(cnt[v]++));swap(a[p],v);}
		while(q.t<t){if(l<=p&&p<=r)bt-=(!(--cnt[a[p]])-!(cnt[v]++));swap(a[p],v);t--;}
		ans[q.id]=bt;
		#undef q
		#undef p
		#undef v
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	char o;scanf("\n");
	int cnt=0;
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%c %d %d\n",&o,&a,&b);
		if(o=='R')
		{
			mo[++cnt]={a,b};
		}
		else
		{
			q[i-cnt]={a,b,cnt,i-cnt};
		}
	}
	qm=m-cnt;
	mt();
	for(int i=1;i<=qm;i++)printf("%d\n",ans[i]);
	return 0;
}