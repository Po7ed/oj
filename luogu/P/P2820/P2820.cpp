#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f[101];
/* int father(int x)
{
	while(f[x]!=x)
	{
		x=f[x];
	}
	return x;
} */
int father(int a)
{
	if(f[a]==a)return a;
	else return father(f[a]);
}

struct edge
{
	int u,v,w;
};

struct cmp
{
	bool operator()(edge x,edge y)
	{
		return x.w>y.w;
	}
};

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	priority_queue<edge,vector<edge>,cmp> e;
	for(int i=0;i<=101;i++)
	{
		f[i]=i;
	}
	int u,v,w,s=0,ss=0;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e.push({u,v,w});
		s+=w;
	}
	while(!e.empty())
	{
		edge t=e.top();
		e.pop();
		if(father(t.u)!=father(t.v))
		{
			f[father(t.u)]=t.v;
			ss+=t.w;
		}
	}
	printf("%d",s-ss);
}