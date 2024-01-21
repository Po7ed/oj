#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N=114514,D=11;
int a[N],n;
ll bit[N],s[N],ts[N];

#define lowbit(x) (x&(-x))
inline void modify(int x)
{
	for(;x<=n;x+=lowbit(x))
	{
		bit[x]++;
	}
}
inline ll query(int x)
{
	ll res=0;
	for(;x;x-=lowbit(x))
	{
		res+=bit[x];
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	ll ans=0;
	// puts("end of input");
	for(int j=1;j<D;j++)
	{
		fill(bit,bit+(n+1),0);
		for(int i=1;i<=n;i++)
		{
			if(j==a[i])
			{
				s[i]=s[i-1]+1;
			}
			else
			{
				s[i]=s[i-1]-1;
			}
			ts[i]=s[i];
		}
		sort(ts,ts+n);
		int pos;
		for(int i=0;i<=n;i++)
		{
			pos=lower_bound(ts,ts+n+1,s[i])-ts+1;
			ans+=query(pos-1);
			modify(pos);
		}
	}
	printf("%lld",ans);
	return 0;
}