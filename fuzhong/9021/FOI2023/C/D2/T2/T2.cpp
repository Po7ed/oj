#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
using namespace std;

typedef long long ll;

int n;
ll h,r;
struct hole
{
	int id;
	ll x,y,z;
	inline bool connect(hole other)
	{
		return (sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y)+(z-other.z)*(z-other.z))<=2*r);
	}
};

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %lld %lld",&n,&h,&r);
		hole a[n+2];
		a[0].id=0;
		a[n+1].id=n+1;
		bitset<1002> e[n+2],vis;
		e[0].reset();
		for(int i=1;i<=n;i++)
		{
			e[i].reset();
			a[i].id=i;
			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
		}
		e[n+1].reset();
		for(int i=1;i<=n;i++)
		{
			if(a[i].z-r<=0)
			{
				e[0][i]=true;
			}
			if(a[i].z+r>=h)
			{
				e[i][n+1]=true;
			}
			for(int j=i+1;j<=n;j++)
			{
				e[i][j]=a[i].connect(a[j]);
				e[j][i]=a[j].connect(a[i]);
			}
		}
		queue<hole> q;
		q.push(a[0]);
		vis.reset();
		vis[0]=true;
		hole t;
		while(!q.empty())
		{
			t=q.front();
			q.pop();
			if(t.id==n+1)
			{
				puts("Yes");
				goto bre;
			}
			for(int i=1;i<=n+1;i++)
			{
				if(!vis[i]&&e[t.id][i])
				{
					vis[i]=true;
					q.push(a[i]);
				}
			}
		}
		puts("No");
		bre:;
	}
	return 0;
}