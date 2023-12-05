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

int main()
{
	ll n,w;
	scanf("%lld %lld",&n,&w);
	ll u[n+1],v[n+1];//u:money,v:~~jl~~
	string s[n+1];
	// bool tx=true;
	for(ll i=0;i<n;i++)
	{
		cin>>s[i];
		scanf("%lld %lld",&u[i],&v[i]);
		// if(v[i]<0)
		// {
			// tx=false;
		// }
	}
//	if(tx)
//	{
//		ll c=0;
//		for(int i=0;i<n;i++)
//		{
//			if(u[i]>=0)
//			{
//				c+=u[i];
//			}
//		}
//		printf("%lld\n",c);
//		for(int i=0;i<n;i++)
//		{
//			if(u[i]>=0)
//			{
//				cout<<s[i]<<"\n";
//			}
//		}
//	}
	bool tmp;
	ll ans=LLM,c1,c2;
	vector<ll> vv;
	unordered_map<ll,pair<ll,ll>> m;
	unordered_map<ll,vector<int>> mm;



	for(ll i=0;i<(1<<(n/2));i++)
	{
		c1=0;
		c2=w;
		for(ll j=0;j<(n/2);j++)//////
		{
			tmp=(i&(1<<j))>>j;
			// tmp=(i>>j)&1;
			//if(i==7)printf("&%d&\n",tmp);
			if(tmp)
			{
				c1+=u[(n-j-1)];
				c2+=v[(n-j-1)];
				mm[i].push_back((n-j-1));
			}
		}
		/* if(c2>=0)
		{
			if(ans<c1)
			{
				vv.clear();
				ans=c1;
				for(ll j=0;j<(n/2);j++)
				{
					tmp=(i&(1<<j))>>j;
					if(tmp)
					{
						vv.push_back((n-j-1));
					}
				}
			}
		} */
		m[i]={c1,c2-w};
	}

/* if(n==31)
{
// puts("114514");
printf("%lld %lld",(1<<(n)),(1<<(n/2)));
} */
//////////////////////////////////////////////////////////////

	for(ll i=0;i<(ll)(1ll<<(n));i+=(ll)(1ll<<(n/2)))
	{
/* if(n==31)
{
puts("114514");
} */
		c1=0;
		c2=w;
		for(ll j=(n/2);j<n;j++)
		{
			tmp=(i&(1<<j))>>j;//
            //if(i==7)printf("&%d&\n",tmp);
			if(tmp)
			{
				c1+=u[(n-j-1)];
				c2+=v[(n-j-1)];
			}
		}
		for(ll ii=0;ii<(1<<(n/2));ii++)
		{
			c1+=m[ii].first;
			c2+=m[ii].second;
			// if(n==31&&w==1)
				// /* printf("%d %d\n",c1,c2), */puts("114514");
			if(c2>=0)
			{
				if(ans<c1)
				{
					vv.clear();
					ans=c1;
					for(ll j=(n/2);j<n;j++)
					{
						tmp=(i&(1<<j))>>j;
						if(tmp)
						{
							vv.push_back((n-j-1));
						}
					}
					vv.insert(vv.end(),mm[ii].begin(),mm[ii].end());
				}
			}
			c1-=m[ii].first;
			c2-=m[ii].second;
		}
		// int ii=i&((1<<(n/2))-1);
		// c1+=m[ii].first;
		// c2+=m[ii].second;
	}
	printf("%lld\n",ans);
	sort(vv.begin(),vv.end());
	for(int a:vv)
	{
		cout<<s[a]<<"\n";
	}
	return 0;
}
