#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
typedef std::unordered_map<int,int> mii;

constexpr int N=514114,INF=0x3f3f3f3f;
int n,a[N],m;

int pre[N],suf[N],lst[N];

struct qry{int l,r,id;};

qry q[N];

int S,bel[N];
int mi,R,ans[N],tmp;
void rbmt()
{
	S=int(ceil(n*pow(m,-.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	std::sort(q+1,q+m+1,[](qry x,qry y)->bool
		{return bel[x.l]!=bel[y.l]?bel[x.l]<bel[y.l]:x.r<y.r;});
	bel[q[0].l=0]=0;
	for(int i=1,l,r;i<=m;i++)
	{
		if(bel[q[i].l]!=bel[q[i-1].l])
		{
			mi=INF;
			R=bel[q[i].l]*S;
			l=(r=R)+1;
		}
		#define q q[i]
		if(q.r<R)
		{
			tmp=INF;
			for(int j=q.l;j<=q.r;j++)if(q.l<=pre[j])
			{
				tmp=std::min(tmp,j-pre[j]);
			}
			ans[q.id]=tmp;
		}
		else
		{
			while(r<q.r)(l<=pre[++r])&&(mi=std::min(mi,r-pre[r]));
			tmp=mi;
			while(q.l<l)(suf[--l]<=r)&&(mi=std::min(mi,suf[l]-l));
			ans[q.id]=mi;
			l=R+1;
			mi=tmp;
		}
	}
}

mii id;
int cnt;
int main()
{
	// freopen("data","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(!id.count(a[i]))id[a[i]]=++cnt;
		a[i]=id[a[i]];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q.l,&q.r);
		q.id=i;
	}
	for(int i=1;i<=n;i++) // pre
	{
		pre[i]=lst[a[i]],lst[a[i]]=i;
		// printf("%d:%d,",i,pre[i]);
	}
	// puts("");
	std::fill(lst,lst+N,INF);
	for(int i=n;i;i--) // suf
	{
		suf[i]=lst[a[i]],lst[a[i]]=i;
		// printf("%d:%d,",i,suf[i]);
	}
	// return 0;
	rbmt();
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]==INF?-1:ans[i]);
	}
	return 0;
}