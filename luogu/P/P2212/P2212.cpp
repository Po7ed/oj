#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct dot
{
	int x,y;
};
struct edge
{
	int u,v,w;
	friend inline bool operator < (edge x,edge y)
	{
		return x.w<y.w;
	}
};
const int N=2145;
dot a[N];

inline int dis(int i,int j)
{
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

int f[N];
inline void init(){iota(f,f+N,0);}
int Find(int x){return (f[x]==x?x:f[x]=Find(f[x]));}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<edge> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		for(int j=1;j<i;j++)
		{
			if(dis(i,j)>=m)
			{
				v.push_back({i,j,dis(i,j)});
			}
		}
	}
	sort(v.begin(),v.end());
	// m=q.size();
	init();
	int fu,fv,ans=0,cnt=0;
	for(edge e:v)
	{
		// printf("{%d,%d,%d}\n",e.u,e.v,e.w);
		fu=Find(e.u);
		fv=Find(e.v);
		if(fu==fv)continue;
		cnt++;
		f[fv]=fu;
		ans+=e.w;
	}
	if(cnt==n-1)
	{
		printf("%d",ans);
	}
	else
	{
		puts("-1");
	}
	return 0;
}