#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514;
ll a[N];

ll gcd(ll a,ll b)
{
	return (b?gcd(b,a%b):a);
}

struct Max
{
	ll pre_gcd,pre_len;
	ll suf_gcd,suf_len;
	ll mid_gcd,mid_len;
	ll allgcd;
};

Max solve(int l,int r)
{
	if(l==r)
	{
		return (Max){a[l],1,a[l],1,a[l],1,a[l]};
	}
	int mid=(l+r)>>1;
	Max ls=solve(l,mid);
	Max rs=solve(mid+1,r);
	Max res;
	//allgcd
	res.allgcd=gcd(ls.allgcd,rs.allgcd);

	ll ag,al,bg,bl;

	// pre
	ag=ls.pre_gcd;
	al=ls.pre_len;
	bg=gcd(ls.allgcd,rs.pre_gcd);
	bl=(mid-l+1+rs.pre_len);
	if(ag*al==bg*bl?ag>bg:ag*al>bg*bl)
	{
		res.pre_gcd=ag;
		res.pre_len=al;
	}
	else
	{
		res.pre_gcd=bg;
		res.pre_len=bl;
	}

	// suf
	ag=rs.suf_gcd;
	al=rs.suf_len;
	bg=gcd(rs.allgcd,ls.suf_gcd);
	bl=(r-mid+ls.suf_len);
	if(ag*al==bg*bl?ag>bg:ag*al>bg*bl)
	{
		res.suf_gcd=ag;
		res.suf_len=al;
	}
	else
	{
		res.suf_gcd=bg;
		res.suf_len=bl;
	}

	// mid
	ag=gcd(ls.suf_gcd,rs.pre_gcd);
	al=ls.suf_len+rs.pre_len;
	if(ls.mid_gcd*ls.mid_len==rs.mid_gcd*rs.mid_len?
	ls.mid_gcd>rs.mid_gcd:ls.mid_gcd*ls.mid_len>rs.mid_gcd*rs.mid_len)
	{
		bg=ls.mid_gcd;
		bl=ls.mid_len;
	}
	else
	{
		bg=rs.mid_gcd;
		bl=rs.mid_len;
	}
	if(ag*al==bg*bl?ag>bg:ag*al>bg*bl)
	{
		res.mid_gcd=ag;
		res.mid_len=al;
	}
	else
	{
		res.mid_gcd=bg;
		res.mid_len=bl;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	Max ans=solve(1,n);
	printf("%lld",max(max(ans.mid_gcd*ans.mid_len,ans.pre_gcd*ans.pre_len),ans.suf_gcd*ans.suf_len));
	return 0;
}