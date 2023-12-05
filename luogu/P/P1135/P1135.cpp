#include <iostream>
#include <queue>
using namespace std;

#define dd t-k[t]
#define du t+k[t]

int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int k[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
	}
	if(a==b)
	{
		puts("0");
		return 0;
	}
	queue<int> q;
	q.push(a);
	bool vis[n+1];
	fill(vis,vis+n+1,false);
	vis[a]=true;
	int t,l,cnt=0;
	while(!q.empty())
	{
		cnt++;
		l=q.size();
		for(int i=0;i<l;i++)
		{
			t=q.front();
			q.pop();
			if(dd>0&&!vis[dd])
			{
				if(dd==b)
				{
					printf("%d",cnt);
					return 0;
				}
				q.push(dd);
				vis[dd]=true;
			}
			if(du<=n&&!vis[du])
			{
				if(du==b)
				{
					printf("%d",cnt);
					return 0;
				}
				q.push(du);
				vis[du]=true;
			}
		}
	}
	puts("-1");
	return 0;
}