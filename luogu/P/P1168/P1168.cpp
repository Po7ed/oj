#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int n,a,k;
	scanf("%d",&n);
	priority_queue<int,vector<int>,less<int>> b;// smaller then kth
	priority_queue<int,vector<int>,greater<int>> s;// biger then kth
	for(int i=1;i<=n;i++)
	{
		k=(i+1)/2;
		scanf("%d",&a);
		if(s.size()&&a<s.top())
		{
			b.push(a);
		}
		else
		{
			s.push(a);
		}
		while(s.size()>k&&s.size())
		{
			b.push(s.top());
			s.pop();
		}
		while(s.size()<k&&s.size())
		{
			s.push(b.top());
			b.pop();
		}
		if(i&1)
		{
			printf("%d\n",s.top());
		}
	}
	return 0;
}