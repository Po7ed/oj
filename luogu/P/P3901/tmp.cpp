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

int bel[N];
inline void initbel()// 1~S: 1
{
	S=int(ceil(pow(n,0.5)));// S=sqrt(n)
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
}

struct query
{
	int l,r,id;
	friend inline bool operator < (query x,query y)
	{
		if(bel[x.l]!=bel[y.l])return bel[x.l]<bel[y.l];
		if(bel[x.l]&1)return x.r<y.r;
		else return x.r>y.r;
	}
};
query q[N];
bitset<N> ans;

int cnt[N],cf=0;

void mt()
{
	initbel();
	sort(q+1,q+m+1);
	for(int i=1,l=0,r=0;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)cf+=(++cnt[a[--l]]==2);
		while(r<q.r)cf+=(++cnt[a[++r]]==2);
		while(l<q.l)cf-=(--cnt[a[l++]]==1);
		while(q.r<r)cf-=(--cnt[a[r--]]==1);
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