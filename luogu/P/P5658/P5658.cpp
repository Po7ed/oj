#include <iostream>
#include <vector>
using namespace std;

const int mn=514114;
int f[mn];
long long s[mn],ans,dp[mn]/* ,dp_[mn] */;

struct Stk
{
	int _s[mn],tail;
	Stk():tail(0)
	{
		fill(_s,_s+mn,0);
	}
	inline int pop()
	{
		if(tail)
		{
			tail--;
			return 0;
		}
		return 1;
	}
	inline bool empty()
	{
		return !tail;
	}
	inline void push(int x)
	{
		_s[tail++]=x;
	}
	inline int back()
	{
		if(empty())
		{
			return -0x3f3f3f3f;
		}
		return _s[tail-1];
	}
	inline int back_pop()
	{
		if(pop())
		{
			return -0x3f3f3f3f;
		}
		return _s[tail];
	}
}stk;

char a[mn];

vector<int> e[mn];

void dfs(int now=1)
{
	int le=0;
	if(a[now]==')')
	{
		if(!stk.empty())
		{
			le=stk.back();
			stk.pop();
			dp[now]=dp[f[le]]+1;
		}
	}
	else
	{
		stk.push(now);
	}
	s[now]=s[f[now]]+dp[now];
	ans^=(s[now]*now);
	for(int to:e[now])
	{
		dfs(to);
	}
	if(le)
	{
		stk.push(le);
	}
	else
	{
		stk.pop();
	}
}

int main()
{
	// freopen("P5658_3.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>f[i];
		e[f[i]].push_back(i);
	}
	dfs();
	cout<<ans<<"\n";
	#ifndef ONLINE_JUDGE
	for(int i=1;i<=n;i++)
	{
		printf("%lld\n",dp[i]);
	}
	#endif
	return 0;
}