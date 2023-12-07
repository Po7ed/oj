#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr int N=51411;

int n,m,a[N];
int bel[N],S;
struct query
{
	int l,r,id,t;
	friend inline bool operator < (query x,query y)
	{
		return (bel[x.l]^bel[y.l]?bel[x.l]<bel[y.l]:(bel[x.l]&1?x.r<y.r:y.r<x.r));
	}
};
query q[N<<2];

void init()
{
	S=int(ceil(pow(n,0.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
}

int cl[N],cr[N],now,ans[N];
void mt()
{
	init();
	sort(q+1,q+(m<<2)+1);
	for(int i=1,l=0,r=0;i<=(m<<2);i++)
	{
		#define q q[i]
		while(l<q.l)++cl[a[++l]],now+=cr[a[l]];
		while(r<q.r)++cr[a[++r]],now+=cl[a[r]];
		while(q.l<l)--cl[a[l]],now-=cr[a[l--]];
		while(q.r<r)--cr[a[r]],now-=cl[a[r--]];
		ans[q.id]+=(q.t*now);
		#undef q
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1,l1,r1,l2,r2,p=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		q[p++]={min(l1-1,l2-1),max(l1-1,l2-1),i,1 };
		q[p++]={min(l1-1,r2),  max(l1-1,r2),  i,-1};
		q[p++]={min(l2-1,r1),  max(l2-1,r1),  i,-1};
		q[p++]={min(r1,r2),    max(r1,r2),    i,1 };
	}
	mt();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}