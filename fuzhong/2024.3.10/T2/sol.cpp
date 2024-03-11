#include <iostream>
//#include <map>
#include <algorithm>
#include <vector>

#define fo(x)\
freopen(#x ".in","r",stdin);\
freopen(#x ".out","w",stdout);

#define fod(x)\
freopen(#x ".in","r",stdin);\
freopen("my.out","w",stdout);

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::vector<pii> vpii;

constexpr int S=200014,N=7,M=11451,T=20,A=1e8;
int n,m,s;
int c[N],d[N],f[S];

int main()
{
	fo(fft);
	// fod(fft4);
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
		for(int j=c[i];j<S;j++)f[j]+=f[j-c[i]];
	}
	for(int j=0;j<=10;j++)printf("%d ",f[j]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",d+j);
		}
		scanf("%d",&s);
		// puts("");
	}
	return 0;
}