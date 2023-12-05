#include <iostream>
#include <vector>
using namespace std;

int n,m,s;

typedef struct node
{
	int dep;
	vector<int> s;
}*tree;

//tree t;

//#define x *t.id
void dfs(tree t,int f[][21],int x,int from)
{
	if(x!=s)
	{
		t[x].dep=t[from].dep+1;
		f[x][0]=from;
	}
	for(int i=1;i<=20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int son:t[x].s)
	{
		if(son!=from)
		{
			dfs(t,f,son,x);
		}
	}
	return;
}

int lca(tree t,int f[][21],int a,int b)
{
	if(t[a].dep<t[b].dep)
	{
		swap(a,b); 
	}
	for(int i=20;i>-1&&(t[a].dep!=t[b].dep&&t[a].dep!=-114514);i--)
	{
		if(t[f[a][i]].dep>=t[b].dep)
		{
			a=f[a][i];
		}
	}
	if(a==b)
	{
		return a;
	}
	for(int i=20;i>-1;i--)
	{
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}

int main()
{
	s=1;
	scanf("%d",&n);
	node t[n+1];
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		t[y].s.push_back(x);
		t[x].s.push_back(y);
		// t[x].f=y;
	}
	scanf("%d",&m);
	int f[n+1][21];
	for(int i=0;i<21;i++)
	{
		f[s][i]=0;
		f[0][i]=0;
	}
	t[0].dep=-114514;
	t[s].dep=1;
	dfs(t,f,s,-1);
	int a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		if(a==b)
		{
			puts("0");
		}
		else
		{
			printf("%d\n",t[a].dep+t[b].dep-2*t[lca(t,f,a,b)].dep); 
		}
	}
	return 0;
}
