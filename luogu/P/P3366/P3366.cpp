#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge
{
	int v=0;
	int a,b;
};

struct cmp
{
	bool operator()(edge x,edge y)
	{
		return x.v>y.v;
	}
};

int f[5001];
int father(int a)
{
	if(f[a]==a)return a;
	else return father(f[a]);
}

int main()
{
	int n,m,c=0,o=0;
	scanf("%d %d",&n,&m);
	priority_queue<edge,vector<edge>,cmp> epq;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		epq.push({z,x,y});
	}
	for(int i=0;i<=n;i++)
	{
		f[i]=i;
	}
	while(!epq.empty())
	{
		edge t=epq.top();
		epq.pop();
		if(father(t.a)!=father(t.b))
		{
			f[father(t.b)]=t.a;
			c+=t.v;
			o++;
		}
	}
	if(o==n-1)
		printf("%d",c);
	else
		puts("orz")/* ,cout<<o<<c; */;
	return 0;
}