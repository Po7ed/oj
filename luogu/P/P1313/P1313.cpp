#include <iostream>
using namespace std;

const int mod=10007;

int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ans%mod;
}

int inv(int a)
{
	return qpow(a,mod-2)%mod;
}

int fac[1145];
inline void init()
{
	fac[0]=1;
	for(int i=1;i<=1000;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
}

inline int C(int n,int m)
{
	return ((fac[n]*inv(fac[m]))%mod*inv(fac[n-m]))%mod;
}

int main()
{
	init();
	int a,b,k,n,m;
	scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
	printf("%d",C(k,n)*qpow(a%mod,n)%mod*qpow(b%mod,m)%mod);
	return 0;
}