#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr int N=1145;
int n;
vector<int> e[N];

int siz[N];
inline bool cmp(int x,int y)
{
	return siz[x]>siz[y];
}
void init(int u=1,int f=0)
{
	siz[u]=1;
	for(int v:e[u])
	{
		if(v==f)continue;
		init(v,u);
		siz[u]+=siz[v];
	}
	sort(e[u].begin(),e[u].end(),cmp);
}

int res;
int dfn[N];
void dfs(int u,int f=0,int ord=1)
{
	res=max(res,dfn[u]=dfn[f]+ord);
	int cnt=1;
	for(int v:e[u])
	{
		if(v==f)continue;
		dfs(v,u,cnt++);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2,f;i<=n;i++)
	{
		scanf("%d",&f);
		e[i].push_back(f);
		e[f].push_back(i);
	}
	init();
	vector<int> ans;
	int mi=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		res=0;
		// fill(dfn,dfn+N,0);
		dfs(i);
		if(res==mi)
		{
			ans.push_back(i);
		}
		else if(res<mi)
		{
			mi=res;
			ans.clear();
			ans.push_back(i);
		}
	}
	printf("%d\n",mi);
	for(int t:ans)
	{
		printf("%d ",t);
	}
	return 0;
}