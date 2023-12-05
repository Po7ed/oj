#include <iostream>
#include <vector>
using namespace std;

const int N=51451,L=20;
int ord[N],dep[N],dif[N],ans[N];
vector<int> e[N];
int n,q;

int jmp[N][L];
void dfs(int u=1,int f=0)
{
	jmp[u][0]=f;
	dep[u]=dep[f]+1;
	for(int v:e[u])
	{
		if(v!=f)
		{
			dfs(v,u);
		}
	}
}

inline void init()
{
	dfs();
	for(int j=1;j<L;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}
}

int lca(int a,int b)
{
	if(dep[a]>dep[b])
	{
		swap(a,b);
	}
	for(int j=L-1;j+1;j--)
	{
		if(dep[jmp[b][j]]>=dep[a])
		{
			b=jmp[b][j];
		}
	}
	if(a==b)
	{
		return a;
	}
	for(int j=L-1;j+1;j--)
	{
		if(jmp[a][j]!=jmp[b][j])
		{
			a=jmp[a][j];
			b=jmp[b][j];
		}
	}
	return jmp[a][0];
}

inline void modify(int a,int b)
{
	int l=lca(a,b);
	dif[a]++;
	dif[b]++;
	dif[l]--;
	dif[jmp[l][0]]--;
}

void query(int u=1,int f=0)
{
	int res=0;
	for(int v:e[u])
	{
		if(v!=f)
		{
			query(v,u);
			res+=ans[v];
		}
	}
	ans[u]=res+dif[u];
	return;
}

int main()
{
	scanf("%d %d",&n,&q);
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	init();
	while(q--)
	{
		scanf("%d %d",&x,&y);
		modify(x,y);
	}
	query();
	int ma=-1;
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,ans[i]);
	}
	printf("%d",ma);
	return 0;
}