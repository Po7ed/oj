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
inline void add(int pos)
{
    cnt[a[pos]]++;
    if(cnt[a[pos]]==2)cf++;
}
inline void del(int pos)
{
    cnt[a[pos]]--;
    if(cnt[a[pos]]==1)cf--;
}

void mt()
{
	S=int(ceil(pow(n,0.5)));// S=sqrt(n)
	sort(q+1,q+m+1);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)add(--l);
		while(r<q.r)add(++r);
		while(l<q.l)del(l++);
		while(q.r<r)del(r--);
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