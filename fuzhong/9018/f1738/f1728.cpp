#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,e;

struct node
{
	vector<int> sons;
	bool color;
};

bool bfs(node p[])
{
	queue<int> q;
	q.push(1);
	bool vis[n+1];
	memset(vis,0,sizeof(vis));
	vis[1]=true;
	while(!q.empty())
	{
		int r=q.front();
		q.pop();
		int l=p[r].sons.size();
		for(int i=0;i<l;i++)
		{
			if(!vis[p[r].sons[i]])
			{
				vis[p[r].sons[i]]=true;
				p[p[r].sons[i]].color=!p[r].color;
				q.push(p[r].sons[i]);
			}
			else
			{
				if(p[p[r].sons[i]].color==p[r].color)
				{
// cout<<p[r].sons[i]<<"Óë"<<r<<"Ë®»ð²»ÈÝ"<<endl;
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&e);
	node p[n+1];
	int u,v;
	for(int i=1;i<=e;i++)
	{
		scanf("%d %d",&u,&v);
		p[u].sons.push_back(v);
		p[v].sons.push_back(u);
	}
	puts(bfs(p)?"YES":"NO");
	return 0;
}