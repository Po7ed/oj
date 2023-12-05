#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

/* typedef pair<int,int> p;
#define i first
#define j second */
typedef struct point
{
	int i,j,t;
}p;
inline bool cmp(p a,p b)
{
	return a.t<b.t;
}

int main()
{
	int n,m;
	scanf("%d %d\n",&n,&m);
	char c;
	vector<p> e[n+1][m+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			// scanf("%c",&c);
			c=getchar();
			if(c=='/')
			{
				e[i+1][j].push_back({i,j+1,0});
				e[i][j+1].push_back({i+1,j,0});
				e[i][j].push_back({i+1,j+1,1});
				e[i+1][j+1].push_back({i,j,1});
			}
			if(c=='\\')
			{
				e[i][j].push_back({i+1,j+1,0});
				e[i+1][j+1].push_back({i,j,0});
				e[i+1][j].push_back({i,j+1,1});
				e[i][j+1].push_back({i+1,j,1});
			}
		}
		getchar();
	}
	if((n+m)&1)
	{
		puts("NO SOLUTION");
		return 0;
	}
	deque<p> q;
	int vis[n+1][m+1];
	fill(vis[0],vis[0]+(n+1)*(m+1),1919810);
	q.push_back({0,0,0});
	vis[0][0]=0;
	p t/* ,d */;
	// int l,cnt=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop_front();
		// sort(e[t.i][t.j].begin(),e[t.i][t.j].end(),cmp);
		for(p /* d */d:e[t.i][t.j])
		{
			// d=dd;
			if(vis[d.i][d.j]>d.t+t.t)
			{
				if(d.i==n&&d.j==m)
				{
					printf("%d",d.t+t.t);
					return 0;
				}
				if(d.t)
				{
					d.t+=t.t;
					q.push_back(d);
				}
				else
				{
					d.t=t.t;
					q.push_front(d);
				}
				vis[d.i][d.j]=d.t;
			}
		}
	}
	// puts("NO SOLUTION");
	return 114514;
}