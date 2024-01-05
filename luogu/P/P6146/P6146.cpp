#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N=114514,A=N<<1,mod=1e9+7;

int n,m;
struct seg
{
	int l,r;
	void input(){scanf("%d %d",&l,&r);}
	friend inline bool operator < (seg x,seg y){return x.l<y.l;}
};
seg a[N];

int dp[N],s[A];

int p[N];
void init()
{
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=(p[i-1]<<1)%mod;
	}
}

int main()
{
	scanf("%d",&n);m=n<<1;
	init();
	for(int i=1;i<=n;i++)a[i].input(),s[a[i].r]++;
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)s[i]+=s[i-1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=((dp[i-1]<<1)%mod+p[s[a[i].l-1]])%mod;
		// printf("%d,%d:%d\n",i,p,dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}