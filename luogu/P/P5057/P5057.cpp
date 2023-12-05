#include <iostream>
using namespace std;

int sum[114514];
int n,m;

#define lowbit(x) ((-x)&x)
inline int query(int x)
{
	int res=0;
	for(;x;x-=lowbit(x))
	{
		res^=sum[x];
	}
	return res;
}

inline void _m(int x)
{
	for(;x<=n;x+=lowbit(x))
	{
		sum[x]^=1;
	}
}

inline void modify(int x,int y)
{
	_m(x);
	_m(y+1);
}

int main()
{
	scanf("%d %d",&n,&m);
	int opt,l,r;
	while(m--)
	{
		scanf("%d %d",&opt,&l);
		if(opt-1)
		{
			printf("%d\n",query(l));
		}
		else
		{
			scanf("%d",&r);
			modify(l,r);
		}
	}
	return 0;
}