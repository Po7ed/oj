#include <iostream>
#include <bitset>

constexpr int N=1145141,mod=10007;
int nxt[N];
int n,m;
int dfn[N],bel[N];
int f[N];

int main()
{
	scanf("%d %d",&n,&m);m%=mod;
	for(int i=1;i<=n;i++)scanf("%d",nxt+i);
	int ans=1,cnt=1,tot=0;
	f[2]=m*(m-1)%mod;
	for(int i=3;i<=n;i++)
	{
		f[i]=(f[i-2]*(m-1)%mod+f[i-1]*(m-2)%mod)%mod;
	}
	for(int i=1,j,len;i<=n;i++)if(!dfn[i])
	{
		for(j=i;!dfn[j];dfn[j]=cnt++,bel[j]=i,j=nxt[j]);
		if(bel[j]==i)
		{
			len=cnt-dfn[j];
			tot+=len;
			ans=ans*f[len]%mod;
		}
	}
	int rem=n-tot;
	while(rem--)ans=ans*(m-1)%mod;
	printf("%d",ans);
	return 0;
}