#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	int m=-1;
	int a[100000],dp[100000],len=1;
	int i=0;
	vector<int> sys={0x3f3f3f3f};
	while(scanf("%d",&a[i])!=EOF)
	{
		if(i==0){dp[0]=a[0];goto con;}
		/* dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[j]>=a[i])
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		} */
		if(a[i]<=dp[len-1])
		{
			dp[len++]=a[i];
		}
		else
		{
			*lower_bound(dp,dp+len,a[i],cmp)=a[i];
		}
		con:
		// m=max(m,dp[i]);
		auto p=lower_bound(sys.begin(),sys.end(),a[i]);
		if(p!=sys.end())
		{
			*p=a[i];
		}
		else
		{
			sys.push_back(a[i]);
		}
		i++;
	}
	printf("%d\n%d",len,sys.size());
	return 0;
}