#include <iostream>
using namespace std;

typedef long long ll;

ll pls(ll x)
{
	ll res=0;
	while(x)
	{
		res+=(x%10);
		x/=10;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	ll m,tm,t,s;
	for(int i=1;i<=n;i++)
	{
		s=0;
		scanf("%lld",&m);
		tm=m;
		for(int cnt=1;tm;cnt++)
		{
			t=tm%10;
			if(cnt&1)
			{
				t*=7;
				while(t>9)
				{
					t=pls(t);
				}
			}
			s+=t;
			tm/=10;
		}
		if(s%8==0)
		{
			puts("T");
		}
		else
		{
			puts("F");
		}
	}
	return 0;
}