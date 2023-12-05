#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	vector<int> v,ans;
	for(int i=n;i>=1;i--)
	{
		while(!v.empty()&&a[v.back()]<=a[i])
			v.pop_back();
		if(!v.empty())
			// printf("%d",v.front());
			ans.push_back(v.back());
		else
			ans.push_back(0);
		v.push_back(i);
	}
	while(!ans.empty())
	{
		printf("%d\n",ans.back());
		ans.pop_back();
	}
	return 0;
}