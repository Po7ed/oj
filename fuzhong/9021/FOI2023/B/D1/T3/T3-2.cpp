#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000001
#define mod 11
#define div 4

typedef long long ll;

int main()
{
	int n;
	scanf("%d",&n);
	ll _log2[n+1];
	_log2[1]=0;
	for(int i=2;i<=n;i++)
	{
		_log2[i]=_log2[i>>1]+1;
	}
	ll a[n+1];
	char st[n/div+1][_log2[n/div]+1];
	fill(*st,*st+(n/div+1)*(_log2[n/div]+1),1ll);
	// int L=1,R=n/div;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		st[i][0]=a[i]/* %mod */;
	}
	int q;
	scanf("%d",&q);
	int l,r,L=1,R=n/div;
	ll tmp;
	for(int i=0;i<q;i++)
	{
		tmp=0;
		scanf("%d %d",&l,&r);
		if(L<=l&&l<=R&&R<r)
		{
			tmp=__gcd(st[l-L][_log2[R-l+1]],st[R-L-(1<<(_log2[R-l+1]))+1][_log2[R-l+1]]);
			l=
		}
		if(r>R)
		{
			L+=n/div;
			R+=n/div;
			if(R>n&&L<=n)
			{
				R=n;
			}
			/* else if(R>n&&L>n)
			{

			} */
			for(int j=1;j<=_log2[R-L+1];j++)
			{
				for(int i=L;i<=R-(1<<j)+1;i++)
				{
					st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1])/* %mod */;
				}
				// for(int i=n-(1<<j)+2;i<=n;i++)
				// {
				// 	st[i][j]=1;
				// }
			}
		}
		#define len _log2[r-l+1]
		printf("%d\n",__gcd(st[l-L][len],st[r-L-(1<<(len))+1][len])%mod);
	}
	return 0;
}