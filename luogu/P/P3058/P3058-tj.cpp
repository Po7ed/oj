#include <iostream>
#include <cstring>
using namespace std;

constexpr int N=1145,p=2012;
int n;
char s[N];
int dp[N][N],pre[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+(s[i]=='('?1:-1);//! +1&-1,not only +1
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=pre[i];j++)
		{
			if(s[i]=='(')
			{
				dp[i][j]=((!j?0:dp[i-1][j-1])+dp[i-1][j])%p;
			}
			else
			{
				dp[i][j]=(dp[i-1][j+1]+dp[i-1][j])%p;
			}
		}
	}
	printf("%d",dp[n][0]);
	return 0;
}