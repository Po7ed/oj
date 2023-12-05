#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N=45;
int n;
ull ql,qr,cnt;
ull f[N]

inline ull init()
{
	f[1]=2ull;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]*3ull+2ull;
	}
	return f[n];
}

void solve(int k,ull l,ull r)
{
	if(r<ql||qr<l)
	{
		return;
	}
	if(ql<=l)
	{
		printf("(");
	}
	if(k>1)
	{
		solve(k-1,l+1,l+f[k-1]);
		solve(k-1,l+f[k-1]+1,r-f[k-1]-1);
		solve(k-1,r-f[k-1],r-1);
	}
	if(r<=qr)
	{
		printf(")");
	}
}

int main()
{
//	freopen("zhou.in","r",stdin);
//	freopen("zhou.out","w",stdout);
	scanf("%d %llu %llu",&n,&ql,&qr);
	ull len=init();
	solve(n,1,len);
	return 0;
 } 
