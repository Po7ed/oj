#include <iostream>
#include <bitset>
using namespace std;

typedef long long ll;
const int N=1145141;
ll a[N],c[N];
bitset<N> neg;
int n,q;

#define lowbit (x&(-x))
int bit[N];
inline void modify(int x)
{
	int xx=x;
	if(neg[x])for(;x<=n;x+=lowbit)bit[x]--;
	else for(;x<=n;x+=lowbit)bit[x]++;
	neg[xx]=!neg[xx];
}
inline int query(int x)
{
	int res=0;
	for(;x;x-=lowbit)res+=bit[x];
	return res;
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		c[i]=a[i]-a[i-1];
		if(c[i]<0)
		{
			modify(i);
			// neg[i]=true;
		}
	}
	int opt,l,r;
	ll x;
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d",&opt,&l,&r);r=(r==n+1?n:r);
		if(opt-1)
		{
			puts(query(r)-query(l)?"No":"Yes");
		}
		else
		{
			scanf("%lld",&x);
			if((c[l]<0)==(c[l]+x>=0))
			{
				modify(l);
			}
			c[l]+=x;
			if((c[r+1]<0)==(c[r+1]-x>=0))
			{
				modify(r+1);
			}
			c[r+1]-=x;
		}
	}
	return 0;
}