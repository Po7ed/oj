#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;
int T,n;
ll mod,seg[N<<2];
inline void init()
{
	fill(seg,seg+(N<<2),1);
}
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)
inline void update(int pos)
{
	seg[pos]=seg[ls]*seg[rs]%mod;
}
void modify(int pos,int l,int r,int mpos,ll m)
{
	if(l==r)
	{
		seg[pos]=m%mod;
		return;
	}
	if(mpos<=mid)
	{
		modify(ls,l,mid,mpos,m);
	}
	else
	{
		modify(rs,mid+1,r,mpos,m);
	}
	update(pos);
}

int main()
{
	scanf("%d",&T);
	int op,x;
	while(T--)
	{
		init();
		scanf("%d %lld",&n,&mod);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&op,&x);
			if(op==1)
			{
				modify(1,1,n,i,(ll)x);
			}
			else
			{
				modify(1,1,n,x,1ll);
			}
			printf("%lld\n",seg[1]%mod);
		}
	}
	return 0;
}
