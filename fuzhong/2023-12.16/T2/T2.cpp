#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
constexpr int N=114514;
int a[N],na,b[N],nb,c[N],nc;
ll ans=5147483647;
map<int,int> cnt;

inline ll dis(int x,int y,int z){return abs(x-y)+abs(x-z)+abs(y-z);}

int main()
{
	// freopen("smoke.in","r",stdin);
	// freopen("smoke.out","w",stdout);
	scanf("%d",&na);for(int i=1;i<=na;i++)scanf("%d",a+i);sort(a+1,a+na+1);
	scanf("%d",&nb);for(int i=1;i<=nb;i++)scanf("%d",b+i);sort(b+1,b+nb+1);
	scanf("%d",&nc);for(int i=1;i<=nc;i++)scanf("%d",c+i);sort(c+1,c+nc+1);
	int *pb,*pc;
	for(int i=1;i<=na;i++)
	{
		pb=lower_bound(b+1,b+nb+1,a[i]);
		pc=lower_bound(c+1,c+nc+1,a[i]);
		if(pb!=b+nb+1&&pc!=c+nc+1)ans=min(ans,dis(a[i],pb[0],pc[0]));
		if(pb!=b+1&&pc!=c+nc+1)ans=min(ans,dis(a[i],pb[-1],pc[0]));
		if(pb!=b+nb+1&&pc!=c+1)ans=min(ans,dis(a[i],pb[0],pc[-1]));
		if(pb!=b+1&&pc!=c+1)ans=min(ans,dis(a[i],pb[-1],pc[-1]));
		// if(l<r)ans=min(ans,2ll*(ma-mi));
	}
	printf("%lld",ans);
	return 0;
}