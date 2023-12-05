#include <iostream>
#include <algorithm>
using namespace std;

struct edge
{
	int u,v,w;
	friend bool operator < (edge x,edge y)
	{
		return x.w>y.w;
	}
};

int n,m;
edge e[114514];

int f[41145];
int Find(int x){printf("%d\n",x);return ((f[x]==0)?x:(f[x]=Find(f[x])));}
int fx,fx_,fy,fy_;
inline bool Ununion(int x,int y)
{
	fx=Find(x),fx_=Find(x+n),fy=Find(y),fy_=Find(y+n);
	if(fx==fy||fx_==fy_)
	{
		return false;
	}
	if(fx!=fy_)
	{
		f[fx]=fy_;
	}
	if(fy!=fx_)
	{
		f[fy]=fx_;
	}
	return true;
}

int main()
{
	freopen("out0.txt","w",stdout);
	freopen("P1525_2.in","r",stdin);
	scanf("%d %d",&n,&m);
	// int u,v,w;
	/* for(int i=1;i<=2*n;i++)
	{
		f[i]=i;
	} */
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		if(!Ununion(e[i].u,e[i].v))
		{
			printf("%d",e[i].w);
			return 0;
		}
	}
	puts("0");
	return 0;
}