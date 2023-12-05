#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;

typedef long long ll;

const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch()
{
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline ll getll()
{
    ll res = 0, neg = 0;
	char ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
}
inline int getint()
{
    int res = 0, neg = 0;
	char ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
}

// #define N 1000001
#define mod 11
#define div (n>=100000?(3*(int)(sqrt(n))):1)

// length of each kuai
#define lk (n/div)

// id in each kuai
#define knid(i) (i-1)%(lk)+1

// id of kuai of i,begin on 0
#define kid(i) (i-1)/(lk)
// #define kid(i) (i)/(lk)////////////////////////////////////

// #define len _log2[_r-_l+1]

// query gcd[_l,_r] (_l,_r in the same kuai)
//#define query(_kid,_l,_r) (__gcd(st[_kid][knid(_l)][_log2[_r-_l+1]],st[_kid][knid(_r)-(1<<(_log2[_r-_l+1]))+1][_log2[_r-_l+1]])%mod)
// @param _kid kuai's id
// @param _l big index of left
// @param _r big index of right
#define query(_kid,_l,_r) (__gcd(st[_kid][knid(_l)][_log2[_r-_l+1]],st[_kid][knid(_r)-(1<<(_log2[_r-_l+1]))+1][_log2[_r-_l+1]]))

// _kid's left index in the big
#define left(_kid) (_kid*lk+1)
#define right(_kid) min(n,(_kid+1)*(lk))

// #define kbeg(_kid) ()
#define knend(_kid) (_kid==kid(n)?((n)%lk==0?lk:(n)%lk):lk)// the knid of this _kid kuai 's end]  ??????????
// #define right(_kid) min(n,left(_kid)+lk-1)
int main()
{
	// printf("%d\n",__gcd(10,25));
	int n;
	// scanf("%d",&n);
	n=getint();
	ll _log2[n+1];
	_log2[1]=0;
	for(int i=2;i<=n;i++)
	{
		_log2[i]=_log2[i>>1]+1;
	}
	ll a[n+2];
	ll st[div+1][lk+1][_log2[lk]+1];
	fill(**st,**st+(div+1)*(lk+1)*(_log2[lk]+1),1ll);
	for(int i=1;i<=n;i++)
	{
		// scanf("%lld",a+i);
		a[i]=getll();
		st[kid(i)][knid(i)][0]=a[i];
		// printf("%d %d %d:%lld\n",kid(i),knid(i),0,st[kid(i)][knid(i)][0]);
	}
	for(int k=0;k<=div;k++)
	{
		if((k<div)||((k==div)&&(n%div)))
		{
			for(int j=1;j<=_log2[knend(k)];j++)
			{
				for(int i=1;i<=knend(k)-(1<<j)+1;i++)
				{
					st[k][i][j]=__gcd(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1])/* %mod */;
					// printf("%d %d %d:%lld\n",k,i,j,st[k][i][j]);
				}
				// for(int i=n-(1<<j)+2;i<=n;i++)
				// {
				// 	st[i][j]=1;
				// }
			}
		}
	}
	// puts("End of st.");
	int q;
	// scanf("%d",&q);
	q=getint();
	int l,r;
	ll res=0;
	for(int i=0;i<q;i++)
	{
		// scanf("%d %d",&l,&r);
		l=getint();
		r=getint();
		if(kid(l)==kid(r))
		{
			res=query(kid(l),l,r);
			// puts("kid(l)==kid(r)");
		}
		/* else if(kid(l)==kid(r)-1)
		{
			res=__gcd(query(kid(l),left(kid(l)),right(kid(l))),
			query(kid(r),left(kid(r)),right(kid(r))))%mod;
		} */
		else if(kid(l)<kid(r))// cha >=2
		{
			// res=query(kid(l),left(kid(l)),right(kid(l)));
			res=query(kid(l),l,right(kid(l)));
			// puts("kid(l)<kid(r)");
			for(int j=kid(l)+1;j<kid(r);j++)
			{
				res=__gcd(res,query(j,left(j),right(j)));
			}
			res=__gcd(res,query(kid(r),left(kid(r)),r));
		}
		printf("%lld\n",res%mod);
	}
	return 0;
}