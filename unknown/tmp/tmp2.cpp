#include <iostream>
#include <cmath>
#include <algorithm>

constexpr int N=214514,B=514,A=N,INF=0x3f3f3f3f;
int a[N],b[N];
int n,m;
struct qry{int l,r,id;};
qry q[N];
int S,bel[N],maxb;
int ans[N];

int cnt;
void mt()
{
	S=int(ceil(pow(n,.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	maxb=bel[n];
	std::sort(q+1,q+m+1,[](const qry &x,const qry &y)->bool
	{
		printf("%d,%d\n",&x-q,&y-q);/* cnt++; */
		// if(cnt==2989661)
		// {
		// 	for(int i=1;i<=m;i++)
		// printf("%d %d %d\n",q[i].l,q[i].r,q[i].id);
		// 	exit(114514);
		// }
		return (bel[x.l]!=bel[y.l])?
			(bel[x.l]<bel[y.l]):
			(x.r<=y.r);
	});
}

int main()
{
	freopen("in","r",stdin);
	freopen("out2","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	// std::copy(a+1,a+n+1,b+1);
	// std::sort(b+1,b+n+1);
	// int tot=std::unique(b+1,b+n+1)-b-1;
	// for(int i=1;i<=n;i++)a[i]=std::lower_bound(b+1,b+tot+1,a[i])-b;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);q[i].id=i;
	}
	mt();

	
	// for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}