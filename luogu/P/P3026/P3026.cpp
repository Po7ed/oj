#include <iostream>
#include <bitset>
using namespace std;

int last[31451],f[11451];
bitset<11456> vis;

int Find(int x){if(f[x])return f[x]=Find(f[x]);else return x;}

void Union(int x,int y)
{
	if(Find(x)!=Find(y))
	{
		f[Find(x)]=Find(y);
	}
	return;
}

int Plus(int x){if(!x)return 1;if(vis[x])return 0;else {vis[x]=true;return Plus(f[x]);}}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int k,l;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&l);
			if(last[l])
			{
				Union(i,last[l]);
			}
			last[l]=i;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt+=Plus(i);
		}
	}
	printf("%d",cnt-1);
}