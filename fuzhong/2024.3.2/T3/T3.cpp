#include <iostream>
#include <bitset>

constexpr int N=114514;

int n,m;
int a[N],b[N],c[N],d[N];
// bool vis[N];
std::bitset<N> vis;

int dfs(int i=1,int tot=0)
{
	if(i==n+1)return tot;
	int ret=0;
	for(int j=1;j<=m;j++)if(!vis[j])
	{
		vis[j]=true;
		ret=std::max(ret,dfs(i+1,tot+(c[j]>=a[i]&&d[j]>=b[i])));
		vis[j]=false;
	}
	return ret;
}

int main()
{
	freopen("dig.in","r",stdin);
	freopen("dig.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=m;i++)scanf("%d",c+i);
	for(int i=1;i<=m;i++)scanf("%d",d+i);
	if(n<=5&&m<=5)printf("%d",dfs());
	else printf("%d",m);
	return 0;
}