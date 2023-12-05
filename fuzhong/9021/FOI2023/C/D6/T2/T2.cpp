#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> e[n+1],e_[n+1];
	int u,v,d[n+1];//rudu
	fill(d,d+(n+1),0);
	unordered_set<int> l[n+1],h[n+1];
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e_[v].push_back(u);
		d[v]++;
		l[u].insert(v);
		h[v].insert(u);
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!d[i])
		{
			q.push(i);
		}
	}
	vector<int> topo;
	int t;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		topo.push_back(t);
		for(int to:e[t])
		{
			d[to]--;
			if(!d[to])
			{
				q.push(to);
			}
		}
	}
	int lt=topo.size();
	for(int i=0;i<lt;i++)
	{
		for(int fr:e_[topo[i]])
		{
			if(!h[fr].empty())
			{
				h[topo[i]].insert(h[fr].begin(),h[fr].end());
			}
		}
	}
	for(int i=lt-1;i>=0;i--)
	{
		for(int to:e[topo[i]])
		{
			if(!l[to].empty())
			{
				l[topo[i]].insert(l[to].begin(),l[to].end());
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(l[i].size()>(size_t)(n/2)||h[i].size()>(size_t)(n/2))
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}