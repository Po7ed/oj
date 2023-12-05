#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	// puts("0");
	int a[n+1];
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!q.empty())
			printf("%d\n",a[q.front()]);
		else
			puts("0");
		scanf("%d",&a[i]);
		while(!q.empty()&&a[q.back()]>=a[i])
			q.pop_back();
		q.push_back(i);
		if(!q.empty()&&q.front()<=i-m)
			q.pop_front();
	}
	return 0;
}