#include <iostream>
#include <queue>
using namespace std;

struct road
{
	int u,v,t;
	friend bool operator < (road x,road y)
	{
		return x.t>y.t;
	}
};

/* struct cmp
{
	bool operator < (road x,road y)
	{
		return x.t>y.t;
	}
}; */

int f[1001],siz[1001];

int Find(int k)
{
	if(f[k]==k)
	{
		return k;
	}
	else
	{
		return f[k]=Find(f[k]);
	}
	return 114514;
}

void Union(int u,int v)
{
	u=Find(u);
	v=Find(v);
	if(u!=v)
	{
		if(siz[u]>siz[v])
		{
			f[v]=u;
			siz[u]+=siz[v];
		}
		else
		{
			f[u]=v;
			siz[v]+=siz[u];
		}
	}
	return;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y,t;
	for(int i=0;i<=n;i++)
	{
		f[i]=i;
		siz[i]=1;
	}
	priority_queue<road> q;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&t);
		q.push({x,y,t});
	}
	road r;
	// int fx,fy;
	int root;
	while(!q.empty())
	{
		r=q.top();
		q.pop();
		Union(r.u,r.v);
		root=-1;
		for(int i=1;i<=n;i++)
		{
			if(root==-1)
			{
				root=Find(i);
			}
			else
			{
				if(Find(i)!=root)
				{
					// break;
					goto con;
				}
			}
		}
		printf("%d",r.t);
		return 0;
		con:;
		/* fx=Find(x);
		fy=Find(y);
		if(fx!=fy)
		{
			
		} */
	}
	puts("-1");
	return 0;
}