#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n;
	priority_queue<int,vector<int>,greater<int>> q;
	int op,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			q.push(x);
		}
		if(op==2)
		{
			printf("%d\n",q.top());
		}
		if(op==3)
		{
			q.pop();
		}
	}
}