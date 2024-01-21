#include <iostream>
#include <string>
using namespace std;

#define delta f[l][r-1]+(s[r]=='('?1:-1)

int main()
{
	freopen("direct.in","r",stdin);
	freopen("direct.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int dp[n][n],f[n][n],ans=0;
	fill(dp[0],dp[0]+n*n,0);
	fill(f[0],f[0]+n*n,0);
	for(int l=0;l<n;l++)
	{
		dp[l][l]=1;
		f[l][l]=(s[l]=='('?1:0);
		ans++;
		for(int r=l+1;r<n;r++)
		{
			// f[l][r]=(f[l][r-1]+(s[r]=='('?1:-1));
			if(delta<0)
			{
				// dp[l][r]++;
				dp[l][r]=dp[l][r-1]+1;
				f[l][r]=0;
			}
			if(delta==0)
			{
				// dp[l][r]--;
				dp[l][r]=dp[l][r-1]-1;
				f[l][r]=0;
			}
			if(delta>0)
			{
				dp[l][r]=dp[l][r-1]+(s[r]=='('?1:-1);
				f[l][r]=delta;
			}
			ans+=(dp[l][r]*(r-l+1));
			// dp[l][r]+=(dp[l][r-1]+f[l][r]);
		}
	}
	printf("%d",ans);
	return 0;
}
// (())
/* 
1+4+3+1+3+1+4+1
 */