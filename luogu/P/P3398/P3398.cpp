#include <iostream>
#include <vector>
using namespace std;

const int N=114514,lN=20;
int n,q;
vector<int> e[N];
int jmp[N][lN],dep[N];
void dfs(int u=1,int f=0)
{
	jmp[u][0]=f;
	dep[u]=dep[f]+1;
	for(int v:e[u])
	{
		if(v==f)
		{
			continue;
		}
		dfs(v,u);
	}
}
inline void init()
{
	dfs();
	for(int j=1;j<lN;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}
}
int lca(int a,int b)// lca of a and b:O(log n)
{
	if(dep[a]>dep[b])
	{
		swap(a,b);
	}
	for(int j=lN-1;j>=0;j--)
	{
		if(dep[a]<=dep[jmp[b][j]])
		{
			b=jmp[b][j];
		}
	}
	if(a==b)
	{
		return a;
	}
	for(int j=lN-1;j>=0;j--)
	{
		if(jmp[a][j]!=jmp[b][j])
		{
			a=jmp[a][j];
			b=jmp[b][j];
		}
	}
	return jmp[a][0];
}

inline bool isanc(int a,int b)// a is b's anc:O(log n)
{
	for(int j=lN-1;j>=0;j--)
	{
		if(dep[a]<=dep[jmp[b][j]])
		{
			b=jmp[b][j];
		}
	}
	return a==b;
}

inline bool on(int x,int a,int l,int b)
{
	return (dep[l]<=dep[x])&&(isanc(x,a)||isanc(x,b));
}

int main()
{
	scanf("%d %d",&n,&q);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	init();
	int a,b,c,d,l1,l2;
	while(q--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		l1=lca(a,b);
		l2=lca(c,d);
		// l1 on c-d or l2 on a-b
		if(on(l1,c,l2,d)||on(l2,a,l1,b))
		{
			puts("Y");
		}
		else
		{
			puts("N");
		}
	}
	return 0;
}