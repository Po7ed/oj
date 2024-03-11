#include <iostream>
#include <algorithm>
#include <cmath>

constexpr int N=514114;
int n,m,a[N],b[N];

struct qry{int l,r,id;};

int S,bel[N];
qry q[N];
int cnt[N],now;
int ans[N];
void mt()
{
	S=int(ceil(n*pow(m,-.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	std::sort(q+1,q+m+1,[](qry x,qry y)->bool
	{
		return bel[x.l]!=bel[y.l]?
		bel[x.l]<bel[y.l]:
		x.r<y.r;
	});
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)++cnt[a[--l]],(cnt[a[l]]==2)&&(now++),(cnt[a[l]]==3)&&(now--);
		while(r<q.r)++cnt[a[++r]],(cnt[a[r]]==2)&&(now++),(cnt[a[r]]==3)&&(now--);
		while(l<q.l)--cnt[a[l]],(cnt[a[l]]==1)&&(now--),(cnt[a[l]]==2)&&(now++),l++;
		while(q.r<r)--cnt[a[r]],(cnt[a[r]]==1)&&(now--),(cnt[a[r]]==2)&&(now++),r--;
		ans[q.id]=now;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::copy(a+1,a+n+1,b+1);
	std::sort(b+1,b+n+1);
	int tot=std::unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=std::lower_bound(b+1,b+tot+1,a[i])-b;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q.l,&q.r);
		q.id=i;
	}
	mt();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}