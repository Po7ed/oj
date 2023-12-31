#include <iostream>
#include <cctype>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef long long ll;
constexpr int N=214514;
int n,q,m;
int f[N],siz[N],a[N];

int read()
{
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res*f;
}

int main()
{
	n=read(),q=read();
	for(int i=2;i<=n;i++)siz[f[i]=read()]++;
	int ans;
	while(q--)
	{
		m=read();
		ans=m;
		for(int i=1;i<=m;i++)siz[f[a[i]=read()]]-=2;
		for(int i=1;i<=m;i++)
		{
			ans+=siz[a[i]];
		}
		for(int i=1;i<=m;i++)
		{
			siz[f[a[i]]]+=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
