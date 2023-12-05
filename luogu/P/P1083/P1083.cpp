#include <iostream>
using namespace std;

typedef long long ll;
const int N=1145141;
ll a[N],b[N],c[N];
int n,m,l[N],r[N];

inline bool check(int pos)
{
	fill(c,c+N,0);
	for(int i=1;i<=pos;i++)
	{
		c[l[i]]-=b[i];
		c[r[i]+1]+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i]+=c[i-1];
		if(c[i]+a[i]<0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld %d %d",b+i,l+i,r+i);
	}
	// l[m+1]=r[m+1]=b[m+1]=0;
	int ans=0,L=1,R=m,Mid;
	while(L<=R)
	{
		Mid=(L+R)>>1;
		// printf("mid:%d\n",Mid);
		if(check(Mid))
		{
			L=Mid+1;
			// puts("Y");
		}
		else
		{
			R=Mid-1;
			// puts("N");
			ans=Mid;
		}
	}
	if(!ans)
	{
		puts("0");
	}
	else
	{
		printf("-1\n%d",ans);
	}
	return 0;
}
