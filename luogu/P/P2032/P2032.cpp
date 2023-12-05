#include <iostream>
#include <deque>
using namespace std;
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	// puts("0");
	int a[n+1];
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(!q.empty()&&a[q.back()]<=a[i])
			q.pop_back();
		q.push_back(i);
		if(!q.empty()&&q.front()<=i-k)
			q.pop_front();
		if(!q.empty()&&i>=k)
			printf("%d\n",a[q.front()]);
	}
	return 0;
}