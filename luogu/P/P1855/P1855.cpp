#include <iostream>
using namespace std;

int n,M,T;
int m[101],t[101];
int dp[201][201];
int main()
{
	scanf("%d %d %d",&n,&M,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&m[i],&t[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=M;j>=m[i];j--)
			for(int k=T;k>=t[i];k--)
				dp[j][k]=max(dp[j][k],dp[j-m[i]][k-t[i]]+1);
	return 0;
}