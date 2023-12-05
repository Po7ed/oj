#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d\n",&n,&m);
	char a[n+1];
	for(int i=1;i<=n;i++)
	{
		a[i]=getchar();
	}
	vector<int> e[n+1];
	int u,v;
	int f[n+1];
	iota(f,f+(n+1),0);
	auto Find=[&](int x){function<int(int)>F=[&](int x){return (f[x]==x?x:f[x]=F(f[x]));};return F(x);};
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		if(a[u]==a[v]&&Find(u)!=Find(v))
		{
			f[Find(u)]=Find(v);
		}
	}
	char type;
	int fu,fv;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %c\n",&u,&v,&type);
		fu=Find(u);
		fv=Find(v);
		// if(i==3)
		// printf("%d %d\n",fu,fv);
		if(fu==fv)
		{
			if(a[u]==type)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			printf("1");
		}
	}
	return 0;
}