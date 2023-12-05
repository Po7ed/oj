#include <iostream>
using namespace std;
typedef long long ll;

ll a,k,m;

struct mat
{
	ll a[2][2];
	mat()
	{
		a[0][0]=a[0][1]=a[1][0]=a[1][1]=0ll;
	}
	inline void init1()
	{
		a[0][0]=a[1][1]=1ll;
		a[0][1]=a[1][0]=0ll;
	}
	inline mat operator * (mat b)
	{
		mat res;
		res.a[0][0]=(a[0][0]*b.a[0][0]+a[0][1]*b.a[1][0])%m;
		res.a[0][1]=(a[0][0]*b.a[0][1]+a[0][1]*b.a[1][1])%m;
		res.a[1][0]=(a[1][0]*b.a[0][0]+a[1][1]*b.a[1][0])%m;
		res.a[1][1]=(a[1][1]*b.a[1][1]+a[1][0]*b.a[0][1])%m;
		return res;
	}
};
mat qpow(mat A,ll x)
{
	mat ans;
	ans.init1();
	while(x)
	{
		if(x&1)
		{
			ans=ans*A;
		}
		A=A*A;
		x>>=1ll;
	}
	return ans;
}

int main()
{
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	mat A,B,C;
	scanf("%lld %lld %lld",&a,&k,&m);
	B.a[0][0]=a;
	B.a[1][0]=B.a[1][1]=A.a[0][0]=A.a[0][1]=1ll;
	C=(A*qpow(B,k));
	printf("%lld",C.a[0][0]%m);
	return 0;
}