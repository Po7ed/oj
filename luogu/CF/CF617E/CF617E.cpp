#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
constexpr int N=114514,A=1145141;
int n,m,k;
int a[N];

int bel[N],S;
struct query
{
	int l,r,id;
	inline bool operator < (query y)
	{return (bel[l]^bel[y.l]?bel[l]<bel[y.l]:(bel[l]&1?r<y.r:y.r<r));}
};
query q[N];
int cnt[A];
ll now,ans[N];
void mt()
{
	S=int(ceil(pow(n,.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;bel[0]=1;
	sort(q+1,q+m+1);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)now+=cnt[k^a[--l]],cnt[a[l]]++;
		while(r<q.r)now+=cnt[k^a[++r]],cnt[a[r]]++;
		while(l<q.l)cnt[a[l]]--,now-=cnt[k^a[l++]];
		while(q.r<r)cnt[a[r]]--,now-=cnt[k^a[r--]];
		ans[q.id]=now;
		// #undef q
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]^=a[i-1];
	for(int i=1;i<=m;i++)scanf("%d %d",&q.l,&q.r),q.l--,q.id=i;
	mt();
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}