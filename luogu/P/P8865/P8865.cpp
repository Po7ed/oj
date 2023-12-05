#include <iostream>
using namespace std;

typedef long long ll;
const int N=1145;
const ll mod=998244353;
int a[N][N];
ll u[N][N],r[N][N],d[N][N];

int main()
{
	int T,id;
	scanf("%d %d",&T,&id);
	while(T--)
	{
		int n,m,c,f;
		ll ans1=0,ans2=0;
		scanf("%d %d %d %d\n",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=getchar()-'0';
			}
			getchar();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j;j--)
			{
				if(a[i][j])
				{
					r[i][j]=0;
				}
				else
				{
					r[i][j]=r[i][j+1]+1;
				}
			}
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]||a[i-1][j]||a[i-2][j])
				{
					u[i][j]=0;
				}
				else
				{
					u[i][j]=(u[i-1][j]+r[i-2][j]-1)%mod;
				}
				ans1=(ans1+u[i][j]*(r[i][j]-1)%mod)%mod;
			}
		}
		for(int i=n;i;i--)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j])
				{
					d[i][j]=0;
				}
				else
				{
					d[i][j]=d[i+1][j]+1;
				}
				ans2=(ans2+(u[i][j]*(r[i][j]-1)%mod)*(d[i][j]-1))%mod;
			}
		}
		printf("%lld %lld\n",ans1*c,ans2*f);
		fill(*a,*a+N*N,0);
		fill(*u,*u+N*N,0);
		fill(*r,*r+N*N,0);
		fill(*d,*d+N*N,0);
	}
	return 0;
}