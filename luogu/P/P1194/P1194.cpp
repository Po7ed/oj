#include <iostream>
#include <queue>
using namespace std;

struct edge
{
	int u,v,k;
	friend bool operator < (const edge a,const edge b)
	{
		return a.k>b.k;
	}
};


int f[5001];
int Find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=Find(f[x]);
}

void Union(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	f[fx]=fy;
	return;
}

int main()
{
	int n,m;
	scanf("%d %d",&m,&n);
	priority_queue<edge> q;
	int k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&k);
			if(i!=j&&k&&k<m)
			{
				q.push({i,j,k});
			}
		}
	}
	int c=0,v=0;
	edge t;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(Find(t.u)!=Find(t.v))
		{
			Union(t.u,t.v);
			c++;
			v+=t.k;
		}
	}
	printf("%d",(v+m*(n-c)));
	return 0;
}
