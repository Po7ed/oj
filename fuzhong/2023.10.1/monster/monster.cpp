#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
//#include <map>
using namespace std;

int a,b,p,q,s,k;

struct life
{
	int a,b,stp;
};

bitset<1145141> vis;

int main()
{
	scanf("%d %d %d %d %d %d",&a,&b,&p,&q,&s,&k);
	queue<life> que;
	que.push({a,b,0});
	life t;
//	puts("aaaa");
	while(!que.empty())
	{
		t=que.front();
		que.pop();
		// printf("a:%d b:%d\n",t.a,t.b);
		if(t.a<=0)
		{
			continue;
		}
		if(t.b-p<=0)
		{
			if(t.a==k)
			{
				printf("%d",t.stp+1);
				return 0;
			}
			if(t.b<=0)
			{
				continue;
			}
		}
		int ta,tb;
		ta=t.a-p;
		tb=min(b,t.b-p+q);
		if(!vis[ta*1000+tb+500500])
		{
			vis[ta*1000+tb+500500]=true;
			que.push({ta,tb,t.stp+1});
		}
		ta=min(a,t.a+s)-p;
		tb=min(b,t.b+q);
		if(!vis[ta*1000+tb+500500])
		{
			vis[ta*1000+tb+500500]=true;
			que.push({ta,tb,t.stp+1});
		}
	}
	puts("-1");
	return 0;
 } 