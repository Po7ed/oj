#include <iostream>
using namespace std;
int a[1000111];

int sum[7]={0,18,18,14,14,10,10};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=sum[a[i]];
	}
	ans+=a[n];
	cout<<ans;
	return 0;
}