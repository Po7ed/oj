#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;
int n,m;

ll bit[N];
#define lb (x&-x)
inline void modify(int x,int y)
{
	for(;x<=n;x+=lb)
	{
		bit[x]+=y;
	}
}
inline ll query(int x)
{
	ll res=0;
	for(;x;x-=lb)
	{
		res+=bit[x];
	}
	return res;
}

int main()
{
	scanf("%d\n%d",&n,&m);
	char opt;
	int l,r;
	while(m--)
	{
		do opt=getchar();while(opt!='x'&&opt!='y');
		scanf("%d %d",&l,&r);
		if(opt=='x')
		{
			modify(l,r);
		}
		else
		{
			printf("%lld\n",query(r)-query(l-1));
		}
	}
	return 0;
}
