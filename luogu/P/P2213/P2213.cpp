#include <iostream>
using namespace std;

#define inc(_i,_b,_e) for(int _i=(_b);_i<=(_e);_i++)
#define dec(_i,_b,_e) for(int _i=(_b);_i>=(_e);_i--)
#define inc_(_i,_b,_e) for(int _i=(_b);_i<(_e);_i++)
#define dec_(_i,_b,_e) for(int _i=(_b);_i>(_e);_i--)
#define _inc(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i<=(_e);_i++)
#define _dec(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i>=(_e);_i--)
#define _inc_(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i<(_e);_i++)
#define _dec_(_i,_b,_e,...) for(int _i=(_b),__VA_ARGS__;_i>(_e);_i--)

constexpr int N=2145;
int a[N][N],s[N][N];
int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	_inc(i,1,n,t)
	{
		inc(j,1,n)
		{
			scanf("%d",&t);
			a[i+j-1][n-i+j]=t;
		}
	}
	inc(i,1,2*n+1)
	{
		inc(j,1,2*n+1)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
		}
	}
	int ans=-1,i_,j_,t,ipk,jpk,imk,jmk;
	inc(i,1,n)
	{
		inc(j,1,n)
		{
			i_=i+j-1;j_=n-i+j;
			ipk=min(2*n-1,i_+k);jpk=min(2*n-1,j_+k);
			imk=max(0,i_-k-1);jmk=max(0,j_-k-1);
			t=s[ipk][jpk]-s[ipk][jmk]-s[imk][jpk]+s[imk][jmk];
			ans=max(ans,t);
		}
	}
	printf("%d",ans);
	return 0;
}