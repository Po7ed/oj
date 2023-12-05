#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// typedef pair<int,int>

int k;

bool cmp1(int x,int y)
{
	return (x==y?x/2<y/2:x>y);
}
bool cmp2(int x,int y)
{
	return (x==y?x-k<y-k:x>y);
}

int main()
{
	// freopen("G:\\zjd\\C++Code\\oj\\luogu\\contest\\137\\T3\\genshin4.in","r",stdin);
	// freopen("G:\\zjd\\C++Code\\oj\\luogu\\contest\\137\\T3\\out.txt","w",stdout);
	int n,m;
	scanf("%d %d %d",&n,&m,&k);
	deque<int> a,b;
	int t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		a.push_back(t*2);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&t);
		b.push_back(t+k);
	}
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	int p,q;
	unsigned long long ans=0;
	while(!(a.empty()||b.empty()))
	{
		if(a.front()==b.front())
		{

		}
		if(a.front()==b.front()?((a.front()/2)<=(b.front()-k)):(a.front()>b.front()))
		{
			p=a.front();
			a.pop_front();
			q=b.back()-k;
			b.pop_back();
		}
		else
		{
			p=b.front();
			b.pop_front();
			q=a.back()/2;
			a.pop_back();
		}
		ans+=(p+q);
	}
	if(!a.empty())
	{
		for(int tt:a)
		{
			ans+=(tt/2);
		}
	}
	if(!b.empty())
	{
		for(int tt:b)
		{
			ans+=(tt-k);
		}
	}
	printf("%llu",ans);
	return 0;
}