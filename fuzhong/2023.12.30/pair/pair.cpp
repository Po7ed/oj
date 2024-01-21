#include <iostream>
#include <cctype>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
constexpr int N=214514;
/* 
10:26 开打
10:49 啊，10pts。
long long!
11:30 45pts
 */

#define fo(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)

int n;
int a[N];

namespace I
{
	int read()
	{
		int res=0,f=1;
		char c=getchar();
		while(!isdigit(c))
		{
			if(c=='-')f=-1;
			c=getchar();
		}
		while(isdigit(c))
		{
			res=res*10+c-'0';
			c=getchar();
		}
		return res*f;
	}
	void solve()
	{
		n=read()<<1;
		for(int i=1;i<=n;i++)a[i]=read();
	}
}// namespace I

namespace t1{void solve(){printf("%d",int(a[1]>a[2]));}}

namespace t2
{
	void solve()
	{
		while(1)new ll;
		return;
	}
}

namespace t3
{
	bool check(){int x=abs(a[1]);for(int i=2;i<=n;i++)if(x!=abs(a[i]))return false;return true;}
	void solve()
	{
		int cnt=1;
		ll ans=0ll;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<0)
			{
				ans+=ll(abs(cnt-i));
				cnt+=2;
			}
		}
		printf("%lld",ans);
	}
}

namespace t4
{
	bool check(){int x=n>>1;for(int i=1;i<=x;i++)if(a[i]>0||(-a[i])!=a[i+x])return false;return true;}
	void solve(){n>>=1;printf("%lld",(1ll*(n-1)*n)>>1ll);}
}

int main()
{
	fo(pair);
	I::solve();
	if(n==2)t1::solve();
	else if(t3::check())t3::solve();
	else if(t4::check())t4::solve();
	else if(n<=16)t2::solve();
	else t2::solve();
	return 0;
}
