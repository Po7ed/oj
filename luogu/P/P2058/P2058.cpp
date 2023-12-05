#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	queue<int> q;
	vector<int> c,v;
	int t[n],k,x,r[n],ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&t[i],&k);
		c.clear();
		for(int j=0;j<k;j++)
		{
			scanf("%d",&x);
			if(find(c.begin(),c.end(),x)==c.end())
			{
				c.push_back(x);
			}
		}
		// r[i]=c.size();
		q.push(i);
		ans+=r[i];
		while(!q.empty()&&!(t[i]-86400<t[q.front()]<=t[i]))
		{
			ans-=r[q.front()];
			q.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
