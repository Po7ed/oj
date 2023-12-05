#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;

const int N=414514;
vector<int> e[N],ans;
bitset<N> ban;
int b[N];
int n,m,k;

struct ufs
{
	int f[N];ufs(){iota(f,f+N,0);}
	int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}
	inline bool Union(int x,int y){x=Find(x),y=Find(y);if(x!=y)return f[y]=x;return false;}
	inline int Count(){int res=0;for(int i=0;i<n;i++)if(!ban[i]&&f[i]==i)res++;return res;}
};

int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",b+i);
		ban[b[i]]=true;
	}
	ufs s;
	for(int u=0;u<n;u++)
	{
		if(ban[u])continue;
		for(int v:e[u])
		{
			if(ban[v])continue;
			s.Union(u,v);
		}
	}
	// printf("*%d\n",s.Count());
	int all=s.Count();
	ans.push_back(all);
	set<int> t;
	for(int i=k;i;i--)
	{
		ban[b[i]]=false;
		t.clear();
		for(int v:e[b[i]])
		{
			if(ban[v])continue;
			t.insert(s.Find(v));
		}
		for(int v:e[b[i]])
		{
			if(ban[v])continue;
			s.Union(b[i],v);
		}
		// printf("*%d\n",s.Count());
		// ans.push_back(s.Count());
		all-=(t.size()-1);
		ans.push_back(all);
	}
	reverse(ans.begin(),ans.end());
	for(int t:ans)
	{
		printf("%d\n",t);
	}
	return 0;
}
