#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


typedef long long ll;
// #define LLM -9223372036854775807ll
#define LLM -0x3f3f3f3f3f3f3f3f

typedef struct programme
{
	// qingkuang
	ll id;
	// money
	ll u;
	// jingli
	ll v;
}p;
// money first
bool cmp_u(p a,p b)
{
	return (a.u==b.u?a.v>b.v:a.u>b.u);
}
// jingli first
bool cmp_v(p a,p b)
{
	return (a.v==b.v?a.u>b.u:a.v>b.v);
}

int main()
{
	ll n,w;
	scanf("%lld %lld",&n,&w);
	ll u[n+1],v[n+1];//u:money,v:~~jl~~
	string s[n+1];
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
		scanf("%lld %lld",&u[i],&v[i]);
	}
	ll ans=LLM/* ,c1,c2 */,res;
	vector<ll> vv;
	vector<p> a,b;
	for(ll i=0;i<(1ll<<(n/2));i++)
	{
		// c1=0;
		// c2=0;
		a.push_back({i,0,0});
		for(ll j=0;j<(n/2);j++)
		{
			if((i>>j)&1)
			{
				a.back().u+=u[(n-j-1)];
				a.back().v+=v[(n-j-1)];
			}
		}
	}
	for(ll i=0;i<(ll)(1ll<<(n));i+=(ll)(1ll<<(n/2)))
	{
		b.push_back({i,0,0});
		for(ll j=(n/2);j<n;j++)
		{
			if((i>>j)&1)
			{
				b.back().u+=u[(n-j-1)];
				b.back().v+=v[(n-j-1)];
			}
		}
	}
	sort(a.begin(),a.end(),cmp_u);
	sort(b.begin(),b.end(),cmp_v);
	/* for(p t:a)
	{
		printf("id:%lld u:%lld v:%lld\n",t.id,t.u,t.v);
	}
	puts("");
	for(p t:b)
	{
		printf("id:%lld u:%lld v:%lld\n",t.id,t.u,t.v);
	} */
	int la=a.size(),lb=b.size();
	for(int i=0,j=0;i<la&&j<lb;i++)
	{
		if(i&&a[i-1].v>a[i].v)
		{
			continue;
		}
		while((a[i].v+b[j].v+w)>=0&&j<lb)
		{
			// printf("%d %d\n",i,j);
			if(ans<(a[i].u+b[j].u))
			{
				ans=(a[i].u+b[j].u);
				res=(a[i].id|b[j].id);
			}
			j++;
		}
	}
	printf("%lld\n",ans);
	for(ll j=0;j<n;j++)
	{
		if((res>>j)&1)
		{
			cout<<s[(n-j-1)]<<'\n';
		}
	}
	/* sort(vv.begin(),vv.end());
	for(int a:vv)
	{
		cout<<s[a]<<"\n";
	} */
	return 0;
}
