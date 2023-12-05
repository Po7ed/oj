#include <iostream>
using namespace std;

typedef long long ll;
const ll mod=ll(1e9+7);
const size_t MN=114;

ll n,k;

/* template<typename T>
inline void _mod(T& a)
{
	a=(a%mod+mod)%mod;
} */

struct matrix
{
	ll a[MN][MN];
	matrix()
	{
		// fill(*a,*a+MN*MN,0);
		memset(a,0,sizeof(a));
	}
	matrix(int opt)
	{
		// fill(*a,*a+MN*MN,0);
		memset(a,0,sizeof(a));
		if(opt)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][i]=1;
			}
		}
	}
	void input()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",a[i]+j);
			}
		}
		return;
	}
	void output()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%lld ",a[i][j]);
			}
			puts("");
		}
		return;
	}
	matrix operator * (matrix B) const
	{
		matrix res;
		for(int i=1;i<=n;i++)
		{
			for(int k=1;k<=n;k++)
			{
				for(int j=1;j<=n;j++)
				{
					res.a[i][j]=(res.a[i][j]+((this->a[i][k])*B.a[k][j])%mod)%mod;
					// _mod(res.a[i][j]);
				}
			}
		}
		return res;
	}
	matrix qpow(ll k)
	{
		matrix ans(1),tmp=*this;
		do
		{
			if(k&1)
			{
				ans=ans*tmp;
			}
			tmp=tmp*tmp;
			k>>=1;
		}
		while(k);
		return ans;
	}
};

int main()
{
	scanf("%lld %lld",&n,&k);
	matrix A;
	A.input();
	A.qpow(k).output();
	return 0;
}