#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int mod = 10007;
int a[maxn],vis[maxn],d[maxn];
int b,n;
long long m,ans=1;
long long Dfs(long long x,long long bb,int k)
{
    d[k] = 1;
    if(d[a[k]]) return bb;
    long long xx = bb;
	bb = x*(m-1)%mod+bb*(m-2)%mod;
    return Dfs(xx,bb%mod,a[k]);
}
void dfs(int k)
{
    if(vis[a[k]] == b)
    {
        ans = ans*Dfs(1,0,k)%mod*m%mod;
        d[k] = 2;
        vis[k] = b;
        return;
    }
    vis[k] = b;
    if(!vis[a[k]]) dfs(a[k]);
}
int main()
{
    scanf("%d %lld",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++)
    {
        b = i;
        if(!vis[i]) dfs(i);
        if(!d[i]) ans = ans*(m-1)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}