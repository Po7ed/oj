#include <iostream>
using namespace std;

int a[250];
size_t dp[250][250],le[250][250],re[250][250];

int log(size_t num)
{
	for(size_t i=63ull;i!=-1ull;i--)
	{
		if((num>>i)&1ll)
		{
			return i+1;
		}
	}
	return 0;
}

size_t p(size_t a,size_t b)
{
	/* size_t res=0;
	for(size_t i=63ull;i!=-1ull;i--)
	{
		res|=((((a>>i)&1ll)&((b>>i)&1ll))<<(i+1));
	}
	return res; */
	return /* a|b| */((a&b)<<1);
}

int main()
{
	int n;
	scanf("%d",&n);
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=le[i][i]=re[i][i]=(1ull<<(a[i]-1));
		ans=max(ans,a[i]);
	}
	// size_t now;
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		#define L [i][k]
		#define R [k+1][j]
		#define N [i][j]
		for(int i=1;j<=n;i++)
		{
			for(int k=i;k<j;k++)
			{
				le N|=(le L|(((le L&re L)&le R))<<1);
				re N|=(re R|(((le R&re R)&re L))<<1);
				dp N|=(p(re L,le R)|le N|re N);
			}
			ans=max(ans,log(dp N));
				// printf("(%d,%d) dp:%llu le:%llu re:%llu\n",i,j,dp[i][j],le[i][j],re[i][j]);
		}
	}
	printf("%d",ans);
	return 0;
}