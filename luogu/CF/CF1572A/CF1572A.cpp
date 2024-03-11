#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <algorithm>
using std::priority_queue;
using std::vector;
using std::bitset;
using std::fill;
using std::max;
constexpr int N=214514;

vector<int> e[N];
int n,k;
int dep[N],deg[N];
bitset<N> vis;

int main()
{
	// freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	int p;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)e[i].clear();
		vis.reset();
		fill(dep+1,dep+n+1,0);
		priority_queue<int,vector<int>,std::greater<int>> q;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&k);deg[i]=k;
			if(!k)q.push(i),dep[i]=1;
			else while(k--)scanf("%d",&p),e[p].push_back(i);
		}
		int u,ans=-1;
		while(!q.empty())
		{
			u=q.top(),q.pop();
			ans=max(ans,dep[u]);
			vis[u]=true;
			for(int v:e[u])
			{
				if(!--deg[v])q.push(v);
				dep[v]=max(dep[v],dep[u]+(v<u));
			}
		}
		for(int i=1;i<=n;i++)if(!vis[i]){puts("-1");goto next;}
		printf("%d\n",ans);
		next:;
	}
	return 0;
}