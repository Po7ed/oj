#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	deque<pair<int,int>> d;
	for(int i=1;i<=n;i++)
	{
		while(!d.empty()&&d.back().second>=a[i])
			d.pop_back();
		if(!d.empty()&&d.front().first<=i-k)
			d.pop_front();
		d.push_back({i,a[i]});
		if(i>=k)
			printf("%d ",d.front().second);
	}
	puts("");
	d.clear();
	for(int i=1;i<=n;i++)
	{
		while(!d.empty()&&d.back().second<=a[i])
			d.pop_back();
		if(!d.empty()&&d.front().first<=i-k)
			d.pop_front();
		d.push_back({i,a[i]});
		if(i>=k)
			printf("%d ",d.front().second);
	}
	return 0;
}