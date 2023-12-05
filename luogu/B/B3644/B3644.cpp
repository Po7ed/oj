#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N=114;
vector<int> e[N],ans;
int deg[N];

int main()
{
	int n;
	scanf("%d",&n);
	int to;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&to);
		while(to)
		{
			e[i].push_back(to);
			deg[to]++;
			scanf("%d",&to);
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!deg[i])
		{
			q.push(i);
		}
	}
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		ans.push_back(u);
		for(int v:e[u])
		{
			deg[v]--;
			if(!deg[v])
			{
				q.push(v);
			}
		}
	}
	for(int t:ans)
	{
		printf("%d ",t);
	}
	return 0;
}