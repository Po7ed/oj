#include <iostream>
#include <cctype>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef long long ll;
constexpr int N=214514;
/* 
8:32 开打
如果 i in S，必然有操作奇数个在祖先。
同时若 i 操作后为 1，必然要以 i 为根操作。
dfs，额外记录祖先操作次数 o，如果 o+[u in S] 为奇数，要翻转。
以上 O(nq)。可拿 1~6。
8:42 开打 O(n^2)
9:09 打完，测完，30pts 到手。
9:13 特 A，|S|=1，显然需要反转以 u 为底的子树。
同时需要反转 u 的所有儿子的子树。
答案为 e[u].size()+1。
9:20 打完，测完，40pts 到手。
特 B，无直接连接。
9:37 寄。
特 C，链。
9:49 B 又懂了。打！
10:16 B、C 都打完了，样例除 7 外全过。

xor：70pts

检查。
 */

vector<int> e[N];


#define fo(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)

int sid,n,q;
int f[N];

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
		sid=read(),n=read(),q=read();
		for(int i=2;i<=n;i++)e[f[i]=read()].push_back(i);
	}
}// namespace I

namespace F
{
	bitset<N> s;
	int a[N],ans;
	void dfs(int u=1,int opt=0)
	{
		if((opt+s[u])&1)ans++,opt++;
		for(int v:e[u])if(v!=f[u])dfs(v,opt);
	}
	void solve()
	{
		int sz;
		while(q--)
		{
			ans=0;
			sz=I::read();
			for(int i=1;i<=sz;i++)s[a[i]=I::read()]=true;
			dfs();
			printf("%d\n",ans);
			for(int i=1;i<=sz;i++)s[a[i]]=false;
		}
	}
}// namespace F

namespace A
{
	void solve()
	{
		int sz,x;
		while(q--)
		{
			sz=I::read(),x=I::read();
			printf("%d\n",e[x].size()+1);
		}
	}
}// namespace A

namespace B
{
	ll ans;
	/* void test()
	{
		int sz;
		while(q--)
		{
			int x;
			sz=I::read();
			for(int i=1;i<=sz;i++)
			{
				scanf("%d",a+i);
				x=a[i];
				s[a[i]]=true;
				while(x)
				{
					if(s[x])
					{
						puts("?");
						exit(0);
					}
					x=f[x];
				}
			}
			for(int i=1;i<=sz;i++)
			{
				s[a[i]]=false;
			}
		}
	} */
	void solve()
	{
		int sz;
		while(q--)
		{
			ans=0ll;
			int x;
			sz=I::read();
			for(int i=1;i<=sz;i++)
			{
				x=I::read();
				ans+=ll(e[x].size()+1ll);
			}
			printf("%lld\n",ans);
		}
	}
}// namespace B

namespace C
{
	int a[N];
	void solve()
	{
		int sz;
		ll ans;
		while(q--)
		{
			ans=0ll;
			sz=I::read();
			for(int i=1;i<=sz;i++)a[i]=I::read();
			sort(a+1,a+sz+1);
			a[0]=-114514;
			for(int i=1;i<=sz;i++)ans+=ll(a[i]!=a[i-1]+1);
			printf("%lld\n",(ans<<1)-(a[sz]==n));
		}
	}
}// namespace C

int main()
{
	fo(xor);
	I::solve();
	// B::test();
	if(sid<=6)F::solve();
	else if(sid<=8)A::solve();
	else if(sid<=11)B::solve();
	else if(sid<=14)C::solve();
	else F::solve();
	return 0;
}
