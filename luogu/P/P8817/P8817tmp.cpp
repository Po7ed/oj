#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

const int N=2545;
int val[N];
vector<int> e[N];
struct node
{
	int u,a,b,w,d,da;
	// node():u(0),a(0),b(0),w(0),d(0){}
};
struct node2
{
	int a,b,w;
	friend inline bool operator < (node2 x,node2 y)
	{
		return x.w>y.w;
	}
};
vector<node2> ma;
bitset<N> go[N];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",val+i);
	}
	int uu,vv;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&uu,&vv);
		e[uu].push_back(vv);
		e[vv].push_back(uu);
	}
	queue<node> q;
	int siz;
	node t;
	q.push({1,0,0,0,0,0});
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(!t.a&&t.d>=1&&t.d<=k+1)
		{
			for(int v:e[t.u])
			{
				if(v==1||v==t.a||v==t.b)continue;
				q.push({v,t.u,0,t.w+val[t.u],t.d+1,t.d});
				q.push({v,0,0,t.w,t.d+1,0});
			}
		}
		else if(t.a&&!t.b&&t.d>=2&&t.d<=2*(k+1)&&t.d-t.da<=k+1)
		{
			for(int v:e[t.u])
			{
				if(v==1||v==t.a||v==t.b)continue;
				if(t.a!=t.u)
				{
					q.push({v,t.a,t.u,t.w+val[t.u],t.d+1});
				}
				q.push({v,t.a,0,t.w,t.d+1});
			}
		}
		else
		{
			for(int v:e[t.u])
			{
				if(v==1||v==t.a||v==t.b)continue;
				q.push({v,0,0,t.w,t.d+1});
			}
		}
		if(t.d>=2*(k+1))
		{
			if(t.a&&t.b)
			{
				ma.push_back({t.a,t.b,t.w});
				go[1][t.a]=go[t.a][1]=go[t.a][t.b]=go[t.b][t.a]=true;
			}
		}
	}
	sort(ma.begin(),ma.end());
	siz=ma.size();
	for(int i=0;i<siz;i++)
	{
		for(int j=i+1;j<siz;j++)
		{
			if(ma[i].a!=ma[j].a&&ma[i].a!=ma[j].b
			&&ma[i].b!=ma[j].a&&ma[i].b!=ma[j].b
			&&go[ma[i].b][ma[j].b])
			{
				printf("%d",ma[i].w+ma[j].w);
				return 0;
			}
		}
	}
	return 114514;
}