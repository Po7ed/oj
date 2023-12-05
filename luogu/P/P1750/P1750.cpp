#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	vector<int> v;
	deque<int> q;
	int l=1,r=m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i<=m)
		{
			while(!q.empty()&&a[i]<a[q.back()])
			{
				q.pop_back();
			}
			q.push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!q.empty()&&(v.empty()||a[q.front()]<v.back()))
		{
			while(l<=q.front())
			{
				v.push_back(a[l++]);
			}
		}
		// 比较两种操作，必须是 < 而不是 <=
		// 入栈一堆元素
		printf("%d ",v.back());
		v.pop_back();// 出栈并输出
		while(r<n&&r<l+m-(int)v.size()-1)
		{// 移动 r
			r++;
			while(!q.empty()&&a[r]<a[q.back()])
			{
				q.pop_back();
			}
			q.push_back(r);
			// 入队
		}
		while(!q.empty()&&q.front()<l)
		{
			q.pop_front();
		}// 移动 l，出队
	}
	return 0;
}