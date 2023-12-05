#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
vector<int> e[154];
int main()
{
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	bitset<152> vis;
	queue<int> q;
	int t;
	for(int u=1;u<=n;u++)
	{
		sort(e[u].begin(),e[u].end());
		for(int v:e[u])// for each edge
		{
			if(u>=v)
			{
				continue;
			}
			vis.reset();
			vis[u]=true;
			q.push(u);
			while(!q.empty())
			{
				t=q.front();
				q.pop();
				if(t!=u)
				{
					for(int to:e[t])
					{
						if(!vis[to])
						{
							vis[to]=true;
							q.push(to);
						}
					}
				}
				else
				{
					for(int to:e[t])
					{
						if(to!=v)
						{
							vis[to]=true;
							q.push(to);
						}
					}
				}
			}
			if(vis.count()!=(size_t)n)
			{
				printf("%d %d\n",u,v);
			}
		}
	}
	return 0;
}