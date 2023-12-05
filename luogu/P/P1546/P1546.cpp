#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge
{
	int v=0;
	int a,b;
};

struct cmp
{
	bool operator()(edge x,edge y)
	{
		return x.v>y.v;
	}
};

int f[101];
int father(int a)
{
	if(f[a]==a)return a;
	else return father(f[a]);
}

int main()
{
	int n,c=0;
	scanf("%d",&n);
	int e[n+1][n+1];
	memset(e,0,sizeof(edge));
	priority_queue<edge,vector<edge>,cmp> epq;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&e[i][j]);
			if(i==j)continue;
			epq.push({e[i][j],i,j});
		}
	}
	// memset(f,0,sizeof(f));
	while(!epq.empty())
	{
		edge t=epq.top();
		epq.pop();
		if(father(t.a)!=father(t.b))
		{
			f[father(t.b)]=t.a;
			c+=t.v;
		}
	}
	printf("%d",c);
	return 0;
}