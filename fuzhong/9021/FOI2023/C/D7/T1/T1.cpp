#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct change
{
	// w:time
	int fr,to,w;
	friend bool operator < (change a,change b)
	{
		return a.fr<b.fr;
		// return (a.to-a.fr)/a.w>(b.to-b.fr)/b.w;
	}
};
struct condition
{
	int v,time;
	friend bool operator < (condition a,condition b)
	{
		return a.time>b.time;
	}
};
priority_queue<condition> q;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	// int fr,to,w;
	change a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].to,&a[i].fr,&a[i].w);
	}
	sort(a+1,a+(n+1));
	// int now=1,mi=0x3f3f3f3f,cnt=0;
	condition t;
	q.push({1,0});
	int i=1;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.v>=m)
		{
			printf("%d",t.time);
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].fr>t.v)
			{
				break;
			}
			else
			{
				q.push({a[i].to,t.time+a[i].w});
			}
		}
	}
	// printf("%d",(now>=m?cnt:-114));
	puts("-1");
	return 0;
}
