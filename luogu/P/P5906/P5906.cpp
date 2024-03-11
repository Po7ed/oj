#include <iostream>
#include <cmath>
#include <algorithm>


constexpr int N=214514,B=514,A=N,INF=0x3f3f3f3f;
int a[N],b[N];
int n,m;
int S,bel[N],maxb;
struct qry{int l,r,id;
friend inline bool operator < (qry &x,qry &y)
{
	return (bel[x.l]^bel[y.l])?
		(bel[x.l]<bel[y.l]):
		((bel[x.l]&1)==(x.r<y.r));
}};
qry q[N];
// qry t[N];
// void ms(int l,int r)
// {
// 	if(l==r)return;
// 	int m=(l+r)>>1;
// 	ms(l,m),ms(m+1,r);
// 	int i=l,j=m+1,k=l;
// 	while(i<=m&&j<=r)
// 	{
// 		if(q[i]<q[j])t[k++]=q[i++];
// 		else t[k++]=q[j++];
// 	}
// 	if(i>m)while(j<=r)t[k++]=q[j++];
// 	else while(i<=m)t[k++]=q[i++];
// 	std::copy(t+l,t+r+1,q+l);
// }
int dis[A];
int cnt[N],sum[B];
inline void del(int d){cnt[d]--,sum[bel[d]]--;}
inline void add(int d){cnt[d]++,sum[bel[d]]++;}
inline void mdf(int &d,int x){del(d),d+=x,add(d);}
int ans[N];
int lst[N],pre[N],nxt[N];
void mt()
{
	S=int(ceil(pow(n,.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	maxb=bel[n];
	std::sort(q+1,q+m+1);
	// ms(1,m);
	for(int i=1,l=1,r=0,j,k;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l){l--;if(l+nxt[l]<=r)mdf(dis[a[l]],nxt[l]);}
		while(r<q.r){r++;if(r-pre[r]>=l)mdf(dis[a[r]],pre[r]);}
		while(l<q.l){if(l+nxt[l]<=r)mdf(dis[a[l]],-nxt[l]);l++;}
		while(q.r<r){if(r-pre[r]>=l)mdf(dis[a[r]],-pre[r]);r--;}
		for(j=maxb;!sum[j];j--);/* (~j)&& */
		for(k=j*S;!cnt[k];k--);
		ans[q.id]=k;
		#undef q
	}
}

int main()
{
	// freopen("P5906_16.in","r",stdin);
	// freopen("out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::copy(a+1,a+n+1,b+1);
	std::sort(b+1,b+n+1);
	int tot=std::unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(b+1,b+tot+1,a[i])-b;
	for(int i=1;i<=n;i++)
	{
		pre[i]=nxt[lst[a[i]]]=i-lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=tot;i++)nxt[lst[i]]=(n+1)-lst[i];
	sum[0]=cnt[0]=tot;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);q[i].id=i;
	}
	mt();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}