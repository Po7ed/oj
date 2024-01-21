#include <iostream>
using namespace std;

constexpr int mod=1e9+7;

int main()
{
	int T,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&l,&r);
		ans=0;
		// if(r<=1e3)
		// {
			for(int i=l;i<=r;i++)
			{
				for(int j=l;j<=r;j++)
				{
					ans=(ans+(i^j))%mod;
				}
			}
		// }
		// else
		// {
		// 	ans=1ll*r*(r+1)/2ll%mod*(r+1)%mod;
		// }
		printf("%d\n",ans);
	}
	return 0;
}