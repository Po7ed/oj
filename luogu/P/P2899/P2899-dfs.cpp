#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N=11451;
int n;
vector<int> e[N];

int ans;
bitset<N> lev;

int dfs(int u=1,int f=0)
{
	int ret=-1,son;
	for(int v:e[u])if(v!=f)
	{
		son=dfs(v,u);
		if(son==-1)ret=0;
		else if(son==0&&ret!=0)ret=1;
	}
	if(!ret)ans++;
	return ret;
}

int main()
{
	// freopen("P2899_5.in","r",stdin);
	// freopen("out","w",stdout);
	// freopen("log","w",stderr);
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	printf("%d",ans+!(~dfs()));
	return 0;
}