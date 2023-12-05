#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

typedef struct cases
{
	// mc:min v,cnt sum of d,ans sum of d*v
	short mc;
	unsigned int cnt;
	ll ans;
}c;

short d[1000001],v[1000001];

vector<int> son[1000001];
c dfs(int now)
{
	c res,t;
	res.ans=0;
	res.cnt=0;
	res.mc=v[now];
	for(int s:son[now])
	{
		t=dfs(s);
		res.ans+=t.ans;
		res.cnt+=t.cnt;
		res.mc=min(res.mc,t.mc);
	}
	if(res.cnt<d[now])
	{
		res.ans+=(res.mc*(d[now]-res.cnt));
		res.cnt+=(d[now]-res.cnt);
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	int f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&f,d+i,v+i);
		son[f].push_back(i);
	}
	printf("%lld",dfs(1).ans);
	return 0;
}