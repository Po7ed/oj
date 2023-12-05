#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

struct edge
{
	int v,w;
};

int n,m,ss,tt;
vector<edge> e[11451];

bitset<11456> vis;
int mw=-1,t;
queue<int> q;
int bsans(int l=0,int r=mw)
{
	// printf("%d %d\n",l,r);
	if(r<l)
	{
		return l;
	}
	int mid=((l+r)>>1),ret;
	// printf("mid:%d\n",mid);
	q.push(ss);
	vis.reset();
	vis[ss]=true;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(edge to:e[t])
		{
			if(!vis[to.v]&&to.w<=mid)
			{
				vis[to.v]=true;
				q.push(to.v);
			}
		}
	}
	if(vis[tt])
	{
		// OK,too big,get smaller
		// puts("OK");
		if(l==r)
		{
			return l;
		}
		return bsans(l,mid);
		// ret=bsans(l,mid);
		/* if(ret==-1)
		{
			return mid;
		} */
		// return ret;
	}
	// NO,too small,get bigger
	// puts("NO");
	return bsans(mid+1,r);
}

int main()
{
	// freopen("out.txt","w",stdout);
	scanf("%d %d %d %d",&n,&m,&ss,&tt);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		mw=max(mw,w);
	}
	printf("%d",bsans());
	return 0;
}