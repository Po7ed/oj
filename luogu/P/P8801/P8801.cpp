#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=20,O=114,INF=0x3f3f3f3f;

ll pow[N];
inline void init_pow()
{
	pow[0]=1ll;
	for(int i=1;i<N;i++)pow[i]=pow[i-1]*10ll;
}

int d[N];

// ll mem[N][O][O];
// #define now mem[i][a][b]
#define A (9-d[i])
#define B (1+d[i])
ll dfs(int i,ll x,int a,int b)
{
	if(!i)return x;
	ll now=-INF;
	if(A<=a)now=max(now,dfs(i-1,x+A*pow[i-1],a-A,b));
	else now=max(now,dfs(i-1,x+a*pow[i-1],0,b));
	if(B<=b)now=max(now,dfs(i-1,x+A*pow[i-1],a,b-B));
	return now;
}

ll n;
int a,b;
ll calc()
{
	// fill(**mem,**mem+(N*O*O),-1ll);
	ll t=n;
	int cnt=0;
	while(t)
	{
		d[++cnt]=t%10ll;
		t/=10ll;
	}
	return dfs(cnt,n,a,b);
}

int main()
{
	init_pow();
	scanf("%lld %d %d",&n,&a,&b);
	printf("%lld",calc());
	return 0;
}