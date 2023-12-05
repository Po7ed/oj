#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MN 100002
vector<pair<int,int>> G[MN];
int low[MN],dfn[MN],bel[MN],st[MN<<1],top=0,cnt=0,bcc=0;
void tarjan(int x, int par=0) {
    low[x] = dfn[x] = ++cnt;
    st[++top] = x;
    for(auto &[y, w] : G[x]) if(y != par) {
        if(dfn[y]) low[x] = min(low[x], dfn[y]); // 返祖边
        else {
            tarjan(y, x);
            low[x] = min(low[x], low[y]); // 树边
        }
    }
    if(dfn[x] == low[x]) { // 达到边双连通分量条件
        ++bcc; // 新建一个边双
        while(st[top + 1] != x) bel[st[top]] = bcc, --top; // 出栈
    }
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int u,v,w;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	tarjan(1,0);
	int mma[bcc+1],mmi[bcc+1];
	memset(mma,-0x3f3f3f3f,sizeof(mma));
	memset(mmi,0x3f3f3f3f,sizeof(mmi));
	for(int i=1;i<=n;i++)
	{
		for(pair<int,int> t:G[i])
		{
			if(bel[i]!=bel[t.first])
			{
				continue;
			}
			mma[bel[i]]=max(mma[bel[i]],t.second);
			mmi[bel[i]]=min(mmi[bel[i]],t.second);
		}
	}
	int ans=-1;
	for(int i=1;i<=bcc;i++)
	{
		ans=max(ans,(mma[i]-mmi[i]));
	}
	printf("%d",ans);
	return 0;
}
