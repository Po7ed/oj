#include <iostream>
#include <vector>
using std::vector;
constexpr int N=1145141,mod=1e8+7;
int n,t;
vector<int> e[N];
int cnt[N],sum[N],siz[N];
int inv(int a)
{
	int res=1,p=mod-2;
	while(p)(p&1)&&(res=1ll*res*a%mod),a=1ll*a*a%mod,p>>=1;
	return res;
}
void dfs(int u=1,int f=0)
{
	cnt[u]=1;
	sum[u]=t?u:1;
	for(int v:e[u])if(v!=f)
	{
		dfs(v,u);
		cnt[u]=1ll*cnt[u]*(cnt[v]+1)%mod;
	}
	for(int v:e[u])if(v!=f)
	sum[u]=(sum[u]+1ll*cnt[u]*inv((cnt[v]+1)%mod)%mod*sum[v]%mod)%mod;
	// printf("%d:%d %d\n",u,sum[u],cnt[u]);
}
int main()
{
	scanf("%d %d",&n,&t);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs();
	printf("%d",sum[1]);
	return 0;
}