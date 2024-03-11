#include <iostream>
#include <vector>

using std::vector;
typedef long long ll;
ll n;
struct op{ll o,x,y;};
vector<op> ans;

#define lb(x) (x&(-x))

inline void opt(ll o,ll x,ll y){return ans.push_back({o,x,y});}

int main()
{
	freopen("blackboard.in","r",stdin);
	freopen("blackboard.out","w",stdout);
	scanf("%lld",&n);
	if(!(n&1)){puts("-1");return 0;}
	ll t,x,p,k,kk;
	while(n^1)
	{
		if((n&3)==3)
		{
			opt(0,n,n);
			opt(1,n,n<<1);
			n=n^(n<<1);
		}
		t=n;
		while((lb(t)<<1)<=n)opt(0,t,t),t<<=1;
		p=n+t,opt(0,n,t);
		x=n^t,opt(1,n,t);
		kk=k=p^x,opt(1,p,x);
		// n^=k,opt(1,n,k);
		while(x>kk)
		{
			if(x&k)opt(1,x,k),x^=k;
			opt(0,k,k),k<<=1;
		}
		n=x;
	}
	printf("%d\n",int(ans.size()));
	for(op a:ans)
	{
		printf("%lld %lld %lld\n",a.o,a.x,a.y);
	}
	return 0;
}