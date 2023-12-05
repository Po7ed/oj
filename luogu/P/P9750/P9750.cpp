#include <iostream>
using namespace std;

int T,M;

int gcd(int a,int b)
{
	return (b?gcd(b,a%b):a);
}

inline bool fh(int x)
{
	return x>=0;
}

struct H
{
	int f,p,q;
};
inline H hj(int p,int q)
{
	// printf("**%d/%d**\n",p,q);
	if(!(p&&q))
	{
		return {1,p,q};
	}
	int ff=1;
	if(fh(p)!=fh(q))
	{
		ff=-1;
	}
	p=abs(p),q=abs(q);
	int g=gcd(p,q);
	p/=g,q/=g;
	return {ff,p,q};
}

inline void yls(int p,int q)
{
	// printf("%d/%d\n",p,q);
	H h=hj(p,q);
	if(h.p==0)
	{
		printf("0");
		return;
	}
	if(h.q==0)
	{
		// puts("ERR");
		return;
	}
	if(h.q==1)
	{
		printf("%d",h.f*h.p);
	}
	else
	{
		printf("%d/%d",h.f*h.p,h.q);
	}
}

struct S
{
	int q,r;
};
inline S getsqrt(int r)
{
	int qq=1;
	for(int i=2;r!=1&&i*i<=r;i++)
	{
		while(!(r%(i*i)))
		{
			r/=(i*i);
			qq*=i;
		}
	}
	return {qq,r};
}

int main()
{
	// freopen("out.txt","w",stdout);
	scanf("%d %d",&T,&M);
	int a,b,c,d;
	while(T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a<0)
		{
			a=-a;
			b=-b;
			c=-c;
		}
		d=b*b-4*a*c;
		if(d<0)
		{
			puts("NO");
			continue;
		}
		S res=getsqrt(d);
		// printf("%dsqrt(%d)\n",res.q,res.r);
		if(res.r==1||res.r==0)
		{
			yls(-b+res.q*res.r,2*a);
			puts("");
			continue;
		}
		if(b)
		{
			yls(-b,2*a);
			printf("+");
		}
		H rres=hj(res.q,2*a);
		int q2=rres.p,q3=rres.q;
		if(q2==1&&q3==1)
		{
			printf("sqrt(%d)",res.r);
		}
		else if(q3==1)
		{
			printf("%d*sqrt(%d)",q2,res.r);
		}
		else if(q2==1)
		{
			printf("sqrt(%d)/%d",res.r,q3);
		}
		else
		{
			printf("%d*sqrt(%d)/%d",q2,res.r,q3);
		}
		puts("");
	}
	return 0;
}