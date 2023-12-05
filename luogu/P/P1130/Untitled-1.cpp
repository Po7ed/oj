#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    // freopen("P1130.in","r",stdin);
    // freopen("out.txt","w",stdout);
    int n,m;//n step;m group.
    scanf("%d %d",&n,&m);
    int a[n+1][m+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int dp[n+1][m+1],ans=0x3f3f3f3f;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=min(dp[i-1][1],dp[i-1][m])+a[1][i];
        for(int j=2;j<=m;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+a[j][i];
        }
    }
    for(int i=1;i<=m;i++)
        ans=min(ans,dp[n][i]);
    printf("%d",ans);
    return 0;
}
