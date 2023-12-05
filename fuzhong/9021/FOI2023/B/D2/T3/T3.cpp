#include <iostream>
#include <deque>
using namespace std;
int main()
{
	// freopen("midori.in","r",stdin);
	// freopen("midori.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1],ans[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	deque<int> q;
	for(int i=n;i>0;i--)
	{
		while(!q.empty()&&a[q.back()]<=a[i])
		{
			q.pop_back();
		}
		while(!q.empty()&&q.front()>i+m-1)
		{
			q.pop_front();
		}
		q.push_back(i);
		ans[i]=q.size();
	}
	for(int i=1;i<=n-m+1;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}