#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const ll mod=ll(1e9+7);
const size_t MN=3;

ll n,k;

/* template<typename T>
inline void _mod(T& a)
{
	a=(a%mod+mod)%mod;
} */

struct matrix
{
	ll a[MN][MN];
	int r,c;
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
			for(int i=1;i<=2;i++)
			{
				a[i][i]=1;
			}
		}
	}
	matrix operator * (matrix B) const
	{
		matrix res;
		for(int i=1;i<=2;i++)
		{
			for(int k=1;k<=2;k++)
			{
				for(int j=1;j<=2;j++)
				{
					res.a[i][j]=(res.a[i][j]+((this->a[i][k])*B.a[k][j])%mod)%mod;
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
	scanf("%lld",&n);
	if(n==1||n==2)
	{
		puts("1");
		return 0;
	}
	matrix A,B;
	A.a[1][1]=1ll;
	A.a[1][2]=1ll;
	B.a[1][1]=1ll;
	B.a[1][2]=1ll;
	B.a[2][1]=1ll;
	B.a[2][2]=0ll;
	A=A*(B.qpow(n-2));
	printf("%lld",(A.a[1][1])%mod);
	return 0;
}