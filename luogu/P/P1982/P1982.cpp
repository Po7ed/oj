#include <iostream>
using namespace std;

typedef long long ll;

// Num n=n.a*base+n.b

const ll base=1e18;

struct Num
{
	bool neg;
	ll a,b;
	Num():neg(false),a(0),b(0){}
	inline void input()
	{
		scanf("%lld",&b);
		if(b<0)
		{
			neg=true;
			b=-b;
		}
	}
	inline void output()
	{
		if(neg)printf("-");
		if(!a)
		{
			printf("%lld ",b);
		}
		else
		{
			printf("%lld",a);
			string tmp=to_string(b);
			int len=tmp.length();
			for(int i=0;i<18-len;i++)printf("0");
			printf("%lld ",b);
		}
	}
	inline void operator = (ll x)
	{
		b=x;
	} 
	friend inline bool operator < (Num x,Num y)
	{
		if(x.neg&&!y.neg)return true;
		if(!x.neg&&y.neg)return false;
		if(x.neg&&y.neg)return (x.a==y.a?x.b>y.b:x.a>y.a);
		else return (x.a==y.a?x.b<y.b:x.a<y.a);
	}
	friend inline Num max(Num x,Num y)
	{
		return (x<y?y:x);
	}
	friend inline Num operator + (Num x,Num y)
	{
		Num res;
		if(x.neg==y.neg)
		{
			res.neg=x.neg;
			res.b=x.b+y.b;
			res.a=res.b/base+x.a+y.a;
			res.b%=base;
		}
		else
		{
			if(x.neg)// x-y
			{
				swap(x,y);
			}
			Num tx=x,ty=y;
			tx.neg=false;ty.neg=false;
			if(tx<ty)
			{
				res.neg=true;
				res.b=y.b-x.b;
				res.a=-res.b/base+y.a-x.a;
				res.b=(res.b%base+base)%base;
			}
			else
			{
				res.neg=false;
				res.b=x.b-y.b;
				res.a=-res.b/base+x.a-y.a;
				res.b=(res.b%base+base)%base;
			}
		}
		return res;
	}
};

const int mn=11;

Num di[mn],dp[mn],pr[mn],sc[mn],pma,ans;

int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		di[i].input();
	}
	pr[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		if(dp[i-1].neg)
		{
			dp[i]=di[i];
		}
		else
		{
			dp[i]=dp[i-1]+di[i];
		}
		pr[i]=max(pr[i-1],dp[i]);
	}
	sc[1]=pr[1];
	pma=sc[1]+pr[1];
	ans=sc[1];
	for(int i=2;i<=n;i++)
	{
		sc[i]=pma;
		pma=max(pma,sc[i]+pr[i]);
		ans=max(ans,sc[i]);
	}
	/* for(int i=1;i<=n;i++)
	{
		a[i].output();
		t[i].output();
		f[i].output();
		puts("");
	} */
	if(ans.neg)printf("-");
	// (ans.a*base+ans.b)%p
	printf("%lld",((ans.a%p)*(base%p)+ans.b%p)%p);
	return 0;
}