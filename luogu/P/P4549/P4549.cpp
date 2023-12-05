#include <iostream>
#include <numeric>
using namespace std;

int gcd(int x,int y)
{
	return (y?gcd(y,x%y):x);
}

int main()
{
	int n;
	scanf("%d",&n);
	int t,ans;
	scanf("%d",&ans);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&t);
		t=abs(t);
		ans=gcd(ans,t);
	}
	printf("%d",ans);
	return 0;
}