#include <iostream>
#include <vector>
using namespace std;

// #define first a
// #define second b
// typedef pair<int,int> p
vector<int> e[100001];
int in[100001],out[100001];
int r[100001];

int dfs(int t)
{
	if(r[t])
	{
		return r[t];
	}
	int cnt=0;
	if(out[t]==0)
	{
		return 1;
	}
	for(int i=0;i<out[t];i++)
	{
		cnt+=dfs(e[t][i]);
	}
	return r[t]=cnt;
}

int main()
{
	// freopen("chain.in","r",stdin);
	// freopen("chain.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	// p e[m+1];
	int a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a].push_back(b);
		in[b]++;
		out[a]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]&&out[i])
		{
			ans+=dfs(i);
		}
	}
	printf("%d",ans);
	return 0;
}