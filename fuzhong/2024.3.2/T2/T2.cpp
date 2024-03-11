#include <iostream>
#include <algorithm>

typedef long long ll;
constexpr int N=114514,INF=0x3f3f3f3f;
int l,n,t,k;
int v[N],m[N];

struct oven
{
	int w,id;
	friend inline bool operator < (oven x,oven y){return x.w>y.w;}
};
oven o[N];

inline int get(int id,int time)
{
	return int(std::min(ll(m[id]),1ll*time*v[id]));
}

bool check(int time)
{
	for(int i=1;i<=n;i++)o[i].w=get(i,time),o[i].id=i;
	std::sort(o+1,o+n+1);
	ll tot=0;
	for(int i=1;i<=k;i++)
	{
		tot+=get(o[i].id,time);
	}
	return tot>=l;
}

int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	scanf("%d %d %d %d",&l,&n,&t,&k);
	for(int i=1;i<=n;i++)scanf("%d %d",v+i,m+i);
	for(int i=1;i<=n;i++)o[i].w=get(i,t),o[i].id=i;
	std::sort(o+1,o+n+1);
	ll tot=0;
	for(int i=1;i<=k;i++)
	{
		tot+=o[i].w;
	}
	if(tot<l)
	{
		puts("No");
		printf("%lld",tot);
	}
	else
	{
		puts("Yes");
		int l=1,mid,r=t,ans=INF;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		printf("%d",ans);
	}
	return 0;
}