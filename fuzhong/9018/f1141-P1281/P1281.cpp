#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int m,k;//m本书;k个人.
	scanf("%d %d",&m,&k);
	int b[m+1],dp[m+1][k+1],s[m+1];//dp[i][j]:将前i个([1,i]区间)分成j份
	memset(dp,0x3f3f3f3f,sizeof(dp));
	s[0]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		s[i]=s[i-1]+b[i];
	}
	for(int i=0;i<=m;i++)dp[i][0]=0;
	for(int i=0;i<=k;i++)dp[0][i]=0;
	dp[1][1]=b[1];
	/* for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=min(i,k);j++)
	}
	} */
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int l=1;l<=j-(i-1);l++)//s[j-l,j]
		  //for(int l=1;l<=2-(1-1);l++)
			{
				if(i-1==0&&j-l!=0)continue;
				dp[j][i]=min(dp[j][i],max(dp[j-l][i-1],s[j]-s[j-l]));
			  //dp[2][1]=min(dp[2][1],max(dp[1][0],    s[2]-s[2-1]))   l=1
			  //dp[2][1]=min(dp[2][1],max(dp[0][0],    s[2]-s[2-2]))   l=2
			}
		}
	}
	int n=dp[m][k],c=0;
	vector<int> v;
	for(int i=m;i>=1;i--)
	{
		c+=b[i];
		if(c>n)
		{
			v.push_back(i);
			c=b[i];
		}
	}
	reverse(v.begin(),v.end());
	printf("1 ");
	for(int t:v)
	{
		printf("%d\n%d ",t,t+1);
	}
	printf("%d",m);
	return 0;
}