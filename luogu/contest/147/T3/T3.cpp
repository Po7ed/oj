#include <iostream>
#include <vector>
#include <algorithm>
// #include <map>
#include <bitset>
using namespace std;

// typedef long long ll;

#define N 100000005

bool vis[N];
int pri[51000000],cnt;
// vector<int> ys[N];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			pri[cnt++]=i;
		}
		for(int j=0;j<cnt;j++)
		{
			if(1ll*i*pri[j]>n)
			{
				break;
			}
			vis[i*pri[j]]=true;
			// ys[i*pri[j]].push_back(pri[j]);
			if(i%pri[j]==0)
			{
				break;
			}
		}
	}
	return;
}

bitset<51000000> v;

bool fj(int x)
{
	for(int i=0;i<cnt;i++)
	{
		int c=0;
		while(x%pri[i]==0)
		{
			// if(x==8)
			// printf("*%d\n",pri[i]);
			c++;
			x/=pri[i];
		}
		if(c&&v.test(pri[i]))
		{
			return false;
		}
		else if(c)
		{
			v.set(pri[i]);
		}
		if(x==1)
		{
			return true;
		}
		/* if(c)
		{
			ys[x].push_back(pri[i]);
		} */
	}
	return true;
}

/* inline ll __lcm(ll x,ll y)
{
	return x*y/__gcd(x,y);
} */

int main()
{
	init(N-1);
	int t;
	scanf("%d",&t);
	// puts("114514");
	while(t--)
	{
		int n,f;
		scanf("%d",&n);
		if(n==2)
		{
			while(n--)scanf("%d",&f);
			puts("Yes");
			continue;
		}
		v.reset();
		// int g,l,a,m;
		// scanf("%d",&a);
		// m=g=l=a;
		int a;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(!fj(a))
			{
				puts("No");
				// printf("%d",a);aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
				for(int j=i+1;j<=n;j++)
				{
					scanf("%d",&f);
				}
				goto bre;
			}
		}
		puts("Yes");
		bre:;
	}
	return 0;
}