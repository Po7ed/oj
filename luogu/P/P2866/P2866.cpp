#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	int h;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&h);
		while(!v.empty()&&v.back()<=h)
		{
			v.pop_back();
		}
		ans+=v.size();
		v.push_back(h);
	}
	printf("%lld",ans);
	return 0;
}