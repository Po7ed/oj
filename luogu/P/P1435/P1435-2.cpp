#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
string s;
int n,m;

int main()
{
	cin>>s;
	n=s.length();
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=n;i>0;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[i-1]==s[j-1])
			{
				dp[i][j]=dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}