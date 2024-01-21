#include <iostream>
using namespace std;

typedef long long ll;
constexpr int mod=1e9+7,N=40;

int mem[N][2],a[N];
#define now mem[i][small]
int dfs(int i,int k,int small=false)// cnt 0
{
	if(~now)return now;
	if(!i)return now=1;
	now=0;
	if(i==k)now=dfs(i-1,k,small||a[i]);// only 0
	else now=dfs(i-1,k,small||a[i])+(small||a[i]?dfs(i-1,k,small):0);// 0/1
	return now;
}

int calc(int x,int k)
{
	if(x==-1)return 0;
	int cnt=0;
	while(x)a[++cnt]=x&1,x>>=1;
	fill(*mem,*mem+(N<<1),-1);
	return dfs(cnt,k+1);
}

int main()
{
	int T,l,r,ans;
	ll tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&l,&r);
		ans=0;
		for(int k=0;(1<<k)<=r;k++)
		{
			tmp=calc(r,k)-calc(l-1,k);
			tmp=tmp*((r-l+1)-tmp)%mod;
			ans=(ans+(tmp<<k)%mod)%mod;
		}
		printf("%d\n",(ans<<1)%mod);
	}
	return 0;
}