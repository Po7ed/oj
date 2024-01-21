#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;//!
constexpr int N=114514,INF=0x3f3f3f3f;
int n,m;
int a[N];

int bel[N],S,R;
struct query{int l,r,id;};
query q[N];
ll ans[N],now,tmp;
int cnt[N];
int ct;
unordered_map<int,int> id;
void rbmt()
{
	S=int(ceil(pow(n,.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	sort(q+1,q+m+1,[](query x,query y)->bool
	{return (bel[x.l]^bel[y.l]?bel[x.l]<bel[y.l]:x.r<y.r);});
	bel[q[0].l=0]=INF;
	for(int i=1,l,r;i<=m;i++)
	{
		if(bel[q[i].l]^bel[q[i-1].l])fill(cnt,cnt+N,0),now=-INF,R=bel[q[i].l]*S,r=R,l=r+1;
		#define q q[i]
		if(q.r<R)
		{
			tmp=-INF;
			for(int j=q.l;j<=q.r;j++)tmp=max(tmp,1ll*(++cnt[id[a[j]]])*a[j]);
			ans[q.id]=tmp;
			for(int j=q.l;j<=q.r;j++)cnt[id[a[j]]]--;
		}
		else
		{
			while(r<q.r)now=max(now,1ll*(++cnt[id[a[++r]]])*a[r]);
			tmp=now;
			while(q.l<l)now=max(now,1ll*(++cnt[id[a[--l]]])*a[l]);
			ans[q.id]=now;
			now=tmp;// rollback
			while(l<=R)--cnt[id[a[l++]]];
		}
		#undef q
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i),id.count(a[i])||(id[a[i]]=++ct);
	for(int i=1;i<=m;i++)scanf("%d %d",&q[i].l,&q[i].r),q[i].id=i;
	rbmt();
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}