#include <iostream>
#include <bitset>
using namespace std;

constexpr int N=1145;
int n,m;
int ans;

#define inchar(c) do c=getchar(); while(c!='F'&&c!='E');

#include <numeric>
int f[3*N];
inline void init(){iota(f,f+3*N,0);}
int Find(int x){return ((f[x]==x)?x:f[x]=Find(f[x]));}


int main()
{
	init();
	scanf("%d %d",&n,&m);
	char o;
	for(int i=1,p,q;i<=m;i++)
	{
		inchar(o)
		scanf("%d %d",&p,&q);
		if(o=='F')
		{
			f[Find(p)]=Find(q);
		}
		else
		{
			f[Find(p+n)]=Find(q);
			f[Find(q+n)]=Find(p);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)ans++;
	}
	printf("%d",ans);
	return 0;
}