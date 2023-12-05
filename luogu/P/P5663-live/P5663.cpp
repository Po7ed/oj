#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> e[114514];
int diso[114514],dise[114514];

void bfs()
{
	queue<int> q;
	q.push(1);
	int len,u,dep=0;
	while(!q.empty())
	{
		dep++;
		len=q.size();
		for(int i=0;i<len;i++)
		{
			u=q.front();
			q.pop();
			for(int v:e[u])
			{
				if((dep&1)&&!diso[v])// odd
				{
					diso[v]=dep;
					q.push(v);
				}
				else if(!(dep&1)&&!dise[v])// even
				{
					dise[v]=dep;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs();
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&u,&v);
		if(v&1)
		{
			if(!diso[u]||diso[u]>v)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
		}
		else
		{
			if(!dise[u]||dise[u]>v)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
		}
	}
	return 0;
}