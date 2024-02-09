#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
constexpr int N=114514;
int n,m;

struct seg{int x,y1,y2,v;};
seg s[N<<1];
int y[N<<1];

namespace sgt
{
	struct node{int sum,len;node():sum(0),len(0){}};
	node t[N<<4];
	#define ls (pos<<1)
	#define rs (pos<<1|1)
	#define mid ((l+r)>>1)
	inline void update(int pos=1,int l=1,int r=m-1)
	{
		if(t[pos].sum)t[pos].len=y[r+1]-y[l];
		else t[pos].len=t[ls].len+t[rs].len;
	}
	void modify(int yl,int yr,int v,int pos=1,int l=1,int r=m-1)
	{
		if(yl<=y[l]&&y[r+1]<=yr)return t[pos].sum+=v,update(pos,l,r);
		if(yl<y[mid+1])modify(yl,yr,v,ls,l,mid);
		if(y[mid+1]<yr)modify(yl,yr,v,rs,mid+1,r);
		update(pos,l,r);
	}
} // namespace sgt


int main()
{
	scanf("%d",&n);
	int x1,y1,x2,y2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		s[i]={x1,y1,y2,1};
		s[i+n]={x2,y1,y2,-1};
		y[i]=y1,y[i+n]=y2;
	}
	n<<=1;
	std::sort(s+1,s+n+1,[](seg a,seg b)->bool {return a.x<b.x;});
	std::sort(y+1,y+n+1);
	m=std::unique(y+1,y+n+1)-y-1;
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		sgt::modify(s[i].y1,s[i].y2,s[i].v);
		ans+=1ll*sgt::t[1].len*(s[i+1].x-s[i].x);
	}
	printf("%lld",ans);
	return 0;
}