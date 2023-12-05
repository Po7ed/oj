#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
string s,_s;
int n,_n,m;

int main()
{
	cin>>s;
	_s=s;
	n=s.length();
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	reverse(_s.begin(),_s.end());
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==_s[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	m=dp[n][n];
	printf("%d",n-m);
	return 0;
}