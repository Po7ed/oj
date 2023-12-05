#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

typedef long long ll;
const int N=2545;
int n,m,k;
ll w[N];
vector<int> e[N],f[N];
bitset<N> rch[N];

int dis[N];
queue<int> q;
void bfs(int s)
{
	fill(dis,dis+N,0x3f3f3f3f);
	q.push(s);
	dis[s]=0;
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(s!=u)
		{
			rch[s][u]=true;
			if(s!=1&&rch[1][u])
			{
				f[s].push_back(u);
				sort(f[s].begin(),f[s].end(),[](int x,int y){return w[x]>w[y];});
				if(f[s].size()>3)
				{
					f[s].pop_back();
				}
			}
		}
		if(dis[u]>k)
		{
			continue;
		}
		for(int v:e[u])
		{
			if(dis[v]==0x3f3f3f3f)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",w+i);
	}
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	ll ans=-1;
	for(int b=2;b<=n;b++)
	{
		for(int c=2;c<=n;c++)
		{
			if(rch[b][c])
			{
				for(int a:f[b])
				{
					for(int d:f[c])
					{
						if(a!=c&&b!=d&&a!=d)
						{
							ans=max(ans,w[a]+w[b]+w[c]+w[d]);
						}
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}