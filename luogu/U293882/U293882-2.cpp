#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m,k=0;
	scanf("%d %d",&n,&m);
	int a[n+1];
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])
		{
			v.push_back(i);
			k++;
		}
	}
	int dp[k+1][m+1];
	fill(dp[0],dp[0]+(k+1)*(m+1),0);
	int ans=-1;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=m;j++)
		{
			
		}
	}
	printf("%d",ans);
	return 0;
}