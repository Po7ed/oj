#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a;
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(v.empty())
		{
			v.push_back(a);
			// puts("empty");
		}
		else if(v.size()==m)
		{
			printf("%d ",v.back());
			v.pop_back();
			while(!v.empty()&&v.back()<a)
			{
				printf("%d ",v.back());
				v.pop_back();
			}
			v.push_back(a);
		}
		else if(v.back()<a)
		{
			// if(v.size()==m)
			// while(!v.empty()&&v.back()<a)
			// {
			// 	printf("%d ",v.back());
			// 	v.pop_back();
			// }
			v.push_back(a);
		}
		else if(v.back()>=a)
		{
			v.push_back(a);
			// puts("push");
		}
	}
	while(!v.empty())
	{
		printf("%d ",v.back());
		v.pop_back();
	}
	return 0;
}