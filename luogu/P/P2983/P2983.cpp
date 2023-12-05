#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll w[100114],v[100114];

struct thing
{
	int id;
	ll val;
	friend bool operator < (thing a,thing b)
	{
		return a.val>b.val;
	}
};

int main()
{
	int n;
	ll m;
	scanf("%d %lld",&n,&m);
	priority_queue<thing> q;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",w+i,v+i);
		q.push({i,w[i]});
	}
	thing t;
	ll c;// buy how much
	ll ans=0;
	while(!q.empty()&&m)
	{
		t=q.top();
		q.pop();
		c=min(v[t.id],m/w[t.id]);
		ans+=c;
		m-=c*w[t.id];
		// printf("%d %lld\n",t.id,c);
	}
	printf("%lld",ans);
	return 0;
}