#include <iostream>
using namespace std;

typedef long long ll;
const int N=1145141,M=1145141;
ll a[M],c[M],k[N],pre[M],suf[M],all;
int l[N],r[N];

int main()
{
	// freopen("virus.in","r",stdin);
	// freopen("virus.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %lld",l+i,r+i,k+i);
		c[l[i]]+=k[i];
		c[r[i]+1]-=k[i];
	}
	for(int i=1;i<=m;i++)
	{
		a[i]=a[i-1]+c[i];
		// printf("%lld ",a[i]);
	}
	// puts("");
	for(int i=1;i<=m;i++)
	{
		pre[i]=max(pre[i-1],a[i]);
	}
	for(int i=m;i>0;i--)
	{
		suf[i]=max(suf[i+1],a[i]);
	}
	all=pre[m];
	ll tmp;
	for(int i=1;i<=n;i++)
	{
		tmp=max(pre[l[i]-1],suf[r[i]+1]);
		if(all==tmp)
		{
			printf("%lld\n",tmp);
		}
		else
		{
			printf("%lld\n",max(tmp,all-k[i]));
		}
	}
	return 0;
}