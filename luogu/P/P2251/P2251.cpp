#include <iostream>
#include <deque>
using namespace std;

const int N=1145141;
int a[N];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		while(!q.empty()&&a[q.back()]>a[i])
		{
			q.pop_back();
		}
		if(!q.empty()&&q.front()<i-m+1)
		{
			q.pop_front();
		}
		q.push_back(i);
		if(i>=m)
		{
			printf("%d\n",a[q.front()]);
		}
	}
	return 0;
}