#include <iostream>
#include <cstring>
using namespace std;

int n,m,p;
int f[5001];
int father(int a)
{
	if(f[a]!=-1&&f[a]!=a)
	{
		return father(f[a]);
	}
	else
	{
		return a;
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&p);
	int u,v;
	for(int i=0;i<=n;i++)
	{
		f[i]=-1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);
		f[father(u)]=father(v);
	}
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&u,&v);
		if(father(u)==father(v))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
/*
6 5 4
1 2
2 3
2 6
3 6
4 5
1 6
1 5
4 6
5 2
*/