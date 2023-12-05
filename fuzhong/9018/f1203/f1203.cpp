#include <iostream>
#include <string.h>
char a[2000],b[2000];
int dp[2000][2000];
using namespace std;
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	scanf("%s %s",a+1,b+1);
	int la=strlen(a),lb=strlen(b);
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d",dp[la][lb]);
	return 0;
}