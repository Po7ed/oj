#include <iostream>
#include <queue>
using namespace std;

struct oier
{
	int id,p,acs;
	friend bool operator < (oier x,oier y)
	{
		return (x.p==y.p?(x.acs==y.acs?x.id>y.id:x.acs<y.acs):x.p<y.p);
	}
};

int main()
{
	int n,t,p;
	scanf("%d %d %d",&n,&t,&p);
	int fail[t],ac[n+1][t],point/* [n+1] */;
	fill(fail,fail+t,0);
	// fill(point,point+n+1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<t;j++)
		{
			scanf("%d",&ac[i][j]);
			if(!ac[i][j])
				fail[j]++;
		}
	}
	priority_queue<oier> q;
	int cacs;
	for(int i=1;i<=n;i++)
	{
		cacs=0;
		point=0;
		for(int j=0;j<t;j++)
		{
			if(ac[i][j])
			{
				point/* [i] */+=fail[j];
				cacs++;
			}
		}
		q.push({i,point,cacs});
	}
	int ans=1;
	while(q.top().id!=p)
	{
		ans++;
		q.pop();
	}
	printf("%d %d",q.top().p,ans);
	return 0;
}