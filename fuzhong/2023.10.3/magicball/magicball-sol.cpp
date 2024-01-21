#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
ll A[55],l[55];
int n;
ll k;
inline void init()
{
	A[0]=A[1]=1;
	l[0]=1;
	l[1]=3;
	for(int i=2;i<=n;i++)
	{
		A[i]=2*A[i-2]+A[i-1];
		l[i]=2*l[i-2]+l[i-1];
	}
}

ll sol(int nn,ll kk)
{
	if(nn==0)
	{
		return 1;
	}
	if(nn==1)
	{
		return 3;
	}
	if(kk<=A[nn-2])
	{
		return sol(nn-2,kk);
	}
	if(kk<=A[nn-2]*2)
	{
		return l[nn-2]+sol(nn-2,kk-A[nn-2]);
	}
	return l[nn-2]*2+sol(nn-1,kk-A[nn-2]*2);
}

int main()
{
	// freopen("magicball3.in","r",stdin);
	// freopen("magicball.out","w",stdout);
	scanf("%d %lld",&n,&k);
	init();
	printf("%lld",sol(n,k));
	return 0;
}