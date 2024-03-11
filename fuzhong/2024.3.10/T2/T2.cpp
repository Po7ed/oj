#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

#include <iostream>
// #include <map>
#include <algorithm>
#include <vector>

#define fo(x)\
freopen(#x ".in","r",stdin);\
freopen(#x ".out","w",stdout);

#define fod(x)\
freopen(#x ".in","r",stdin);\
freopen("my.out","w",stdout);

/*
 * dfs.
 */
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::vector<pii> vpii;
// typedef std::map<int,int> mii;

constexpr int S=200014,N=7,M=11451,T=20,A=1e8;
int n,m,s;
//typedef std::map<int,ll> mill;

int c[N],d[N],ma[N],suf[N];
//ll dp[A];

//int p[]={1,21,441,9261,194481,4084101,85766121};

// mii l,r;
//int ch[N];
//mill mem[N];
int mem[N][S];
vpii sd;
#define now mem[i][sum]
//#define ud(x,y) int((x)/(y)+bool((x)%(y)))
int dfs(int i=1,int sum=0)
{
//	if(sum>s)return now=0;
//	printf("i:%d\n",i);
	if(i==n+1)
	{
//		printf("%lld\n",sum);
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",ch[j]);
//		}
//		puts("");
		if(sum==s)
		{
			return 1;
		}
		return 0;
	}
	if(~now)return now;
	ll res=0;
	int k;
	if(s-suf[i+1]-sum>0)k=(s-suf[i+1]-sum)/c[i];
	else k=0;
	for(int j=k,t=j*c[i];j<=d[i]&&sum+t<=s;j++) // &&sum+t+suf[i+1]>=s
	{
//		ch[i]=j;
		res+=dfs(i+1,sum+t);
		t+=c[i];
	}
	return sd.emplace_back(i,sum),now=res;
}

int main()
{
	fo(fft);
	sd.reserve(100000);
	// fod(fft4);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
	}
	scanf("%d",&m);
//	printf("m:%d\n",m);
//	dp[0]=1;
	std::fill(*mem,*mem+(N*S),-1);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",d+j);
			ma[j]=d[j]*c[j];
//			printf("suf[%d]=%d",j,suf[j]);
//			mem[j].clear();
		}
		for(int j=n;j;j--)suf[j]=suf[j+1]+ma[j];
		scanf("%d",&s);
		/*************/
//		puts("");
		printf("%d\n",dfs());
//		puts("");
		for(pii p:sd)
		{
			mem[p.first][p.second]=-1;
		}
		sd.clear();
	}
	return 0;
}