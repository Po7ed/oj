#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<>> q;
	int t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		q.push(t);
	}
	int ans=0;
	while(q.size()!=1)
	{
		int a,b;
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		ans+=(a+b);
		q.push(a+b);
	}
	printf("%d",ans);
	return 0;
}