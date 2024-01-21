#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[3114],t[3114],ans[3114];
int dp[3114][3114];
int main()
{
	scanf("%s\n%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	// fill(*dp,*dp+3114*3114,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(s[i]==t[j])
			{
				dp[i][j]=(dp[i][j],dp[i-1][j-1]+1);
			}
		}
	}
	int a=n,b=m;
	while(dp[a][b]>0&&a>0&&b>0)
	{
		// printf("%d %d\n",a,b);
		// system("pause");
		if(s[a]==t[b])
		{
			ans[dp[a][b]]=s[a];
			a--;
			b--;
		}
		else if(dp[a][b-1]==dp[a][b])
		{
			b--;
		}
		else
		{
			a--;
		}
	}
	printf("%s",ans+1);
	return 0;
}
