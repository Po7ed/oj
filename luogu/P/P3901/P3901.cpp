#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

/*
 * CheckList
 * "Yes" & "No"
 */

constexpr int N=114514;
int n,m;
int a[N];

int S;

inline int bel(int x)// 1~S: 1
{
	return (x-1)/S+1;
}

struct query
{
	int l,r,id;
	friend inline bool operator < (query x,query y)
	{
		return (bel(x.l)==bel(y.l)?x.r<y.r:bel(x.l)<bel(y.l));
	}
};
query q[N];
bitset<N> ans;

int cnt[N],cf=0;
inline void mov(int pos,int sgn)
{
	cnt[a[pos]]+=sgn;
	if(sgn==1&&cnt[a[pos]]==2)
	{
		cf++;
	}
	else if(sgn==-1&&cnt[a[pos]]==1)
	{
		cf--;
	}
}

void mt()
{
	S=int(ceil(pow(n,0.5)));// S=sqrt(n)
	sort(q+1,q+m+1);
	for(int i=1,l=0,r=0;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)mov(--l,1);
		while(r<q.r)mov(++r,1);
		while(l<q.l)mov(l++,-1);
		while(q.r<r)mov(r--,-1);
		ans[q.id]=!cf;
		#undef q
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	mt();
	for(int i=1;i<=m;i++)
	{
		puts(ans[i]?"Yes":"No");
	}
	return 0;
}