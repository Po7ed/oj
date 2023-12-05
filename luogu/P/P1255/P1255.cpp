#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
const ull mod=(ull)1e18;
#define SIZ 60

struct int114
{
	ull a[SIZ];
	void operator = (int n)
	{
		a[0]=(ull)n;
		for(int i=1;i<SIZ;i++)
		{
			a[i]=0;
		}
	}
	int114 operator + (int114 y)
	{
		int114 ans;
		for(int i=0;i<SIZ;i++)
		{
			ans.a[i]=0;
		}
		for(int i=0;i<SIZ-1;i++)
		{
			ans.a[i]+=(a[i]+y.a[i]);
			if(ans.a[i]>mod)
			{
				ans.a[i+1]+=(ans.a[i]/mod);
				ans.a[i]%=mod;
			}
		}
		return ans;
	}
	inline void print()
	{
		bool first=true;
		for(int i=SIZ-1;i>=0;i--)
		{
			if(a[i])
			{
				if(first)
				{
					printf("%llu",a[i]);
					first=false;
				}
				else
				{
					int len=18-log10(a[i]);
					for(int i=0;i<len;i++)
					{
						printf("0");
					}
					printf("%llu",a[i]);
				}
			}
		}
	}
};

int main()
{
	// freopen("out.txt","w",stdout);
	// printf("%llu",mod);
	int n;
	scanf("%d",&n);
	if(!n)
	{
		puts("0");
	}
	int114 dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	// printf("%d",dp[n]);
	dp[n].print();
	return 0;
}