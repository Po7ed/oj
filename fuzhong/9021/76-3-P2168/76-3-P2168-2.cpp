#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;
#define d first
#define w second

struct cmp
{
	bool operator () (p a,p b)
	{
		return (a.w==b.w?/* l[a.d]>l[b.d] */a.d>b.d:a.w>b.w);
	}
};

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	ll wi;
	priority_queue<p,vector<p>,cmp> q;
	// fill(l,l+n,0);
	for(int i=0;i<n;i++)//d from:0
	{
		scanf("%lld",&wi);
		q.push({1,wi});
	}
	int nn=n;
	while((q.size()-1)%(k-1))q.push({1,0});
	ll t,dd;
	// int c=0,last=-1,li;
	// bool plus;
	// vector<int> pops;
	ll ans=0;
	while(q.size()!=1)
	{
		t=0;
		dd=-1;
		// pops.clear();
		for(int i=0;i<k&&!q.empty();i++)
		{
// printf("#%d(%lld) ",q.top().d,q.top().w);
			// if(q.top().d!=-1&&q.top().d<n)
				// pops.push_back(q.top().d);
			t+=q.top().w;
			dd=max(dd,q.top().d);
			// plus=(q.top().d==-1)||plus;
			q.pop();
		}
// puts((plus?"plus":"no"));
		ans+=t;
		/* c+=((int)plus);
		for(int tt:pops)
		{
			l[tt]=c;
		} */
		q.push({dd+1,t});
	}
	/* for(int i=0;i<n;i++)
	{
		ans+=((c-l[i]+1)*wi[i]);
	} */
	printf("%lld\n%lld",ans,q.top().d-1);
	return 0;
}