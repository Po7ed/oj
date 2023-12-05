#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,e,c[2];

struct node
{
	vector<int> sons;
	bool color;
};

bool bfs(node p[])
{
	c[0]=1;c[1]=0;
	p[1].color=false;
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
				c[(int)(p[p[r].sons[i]].color)]++;
// cout<<(int)(p[p[r].sons[i]].color)<<endl;
				q.push(p[r].sons[i]);
			}
			else
			{
				if(p[p[r].sons[i]].color==p[r].color)
				{
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
	printf("%d",(bfs(p)?max(c[0],c[1]):(-1)));
	// cout<<"#"<<c[0]<<c[1]<<endl;
	return 0;
}