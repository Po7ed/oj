#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,a,x,ans=0;
	scanf("%d",&n);
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&a);
		while(!v.empty()&&v.back()>a)
		{
			v.pop_back();
		}
		if(!v.empty()&&v.back()==a)
		{
			ans++;
		}
		else
		{
			v.push_back(a);
		}
	}
	printf("%d",n-ans);
	return 0;
}