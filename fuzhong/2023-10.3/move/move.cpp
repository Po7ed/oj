#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;


struct pos
{
	int x,y,stp;
	char vis[51][51];
	pos():x(0),y(0),stp(0)
	{
		fill(*vis,*vis+51*51,'\0');
	}
	friend inline bool operator < (pos a,pos b)
	{
		return (a.x==b.x?a.y<b.y:a.x<b.x);
	}
	friend inline bool operator == (pos a,pos b)
	{
		return (a.x==b.x&&a.y==b.y);
	}
};

pos d[256];
inline void init()
{
	d['R'].x=1;
	d['L'].x=-1;
	d['U'].y=1;
	d['D'].y=-1;
}

int main()
{
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	init();
	int n;
	scanf("%d",&n);
	string opt;
	cin>>opt;
	queue<pos> q;
	pos t,dt;
	t.vis[21][21]='.';
	q.push(t);
	#define dx t.x+d[opt[t.stp]].x
	#define dy t.y+d[opt[t.stp]].y
	#define ds t.stp+1
	while(q.front().stp<n)
	{
		t=q.front();
		// printf("%d %d %d\n",t.x,t.y,t.stp);
		q.pop();
		if(t.vis[dx+21][dy+21]!='#')
		{
			dt=t;
			dt.x=dx;
			dt.y=dy;
			dt.stp=ds;
			dt.vis[dx+21][dy+21]='.';
			// printf(" %d %d %d\n",dt.x,dt.y,dt.stp);
			q.push(dt);
		}
		if(t.vis[dx+21][dy+21]!='.')
		{
			t.vis[dx+21][dy+21]='#';
			t.stp++;
			// printf(" %d %d %d\n",t.x,t.y,t.stp);
			q.push(t);
		}
	}
	vector<pos> ans;
	while(!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}
	sort(ans.begin(),ans.end());
	auto p=unique(ans.begin(),ans.end());
	printf("%llu\n",p-ans.begin());
	for(int i=0;ans.begin()+i<p;i++)
	{
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}