#include <iostream>
#include <vector>
using namespace std;

constexpr int N=1145;
int n,m,k;
vector<int> e[N];

int mch[N],vis[N];
bool dfs(int u,const int tag)
{
	if(vis[u]==tag)return false;
	vis[u]=tag;
	for(int v:e[u])if(!mch[v]||dfs(mch[v],tag))return mch[v]=u,true;
	return false;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1,u,v;i<=k;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(n+v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=dfs(i,i);
	printf("%d",ans);
	return 0;
}