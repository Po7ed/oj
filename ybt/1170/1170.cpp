#include <iostream>
using namespace std;
int main()
{
	int n=0;
	int ans[64]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<64;j++)
		{
			int x;
			ans[j]*=2;ans[j]+=x;
			x=ans[j]/10;
			if(ans[j]>9)
			{
				ans[j]%=10;
			}
		}
	}
	int i=63;
	while(!ans[i])i--;
	for(;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
}