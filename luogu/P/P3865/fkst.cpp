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
// #define mod 11
// #define div (n>=10000?((int)(sqrt(n))/20):1)
#define div ((int)(sqrt(n)))

// length of each kuai
#define lk (n/div)

// id in each kuai
#define knid(i) (i-1)%(lk)+1

// id of kuai of i,begin on 0
#define kid(i) (i-1)/(lk)
// #define kid(i) (i)/(lk)/////

// #define len _log2[_r-_l+1]

// query gcd[_l,_r] (_l,_r in the same kuai)
// #define query(_kid,_l,_r) (max(st[_kid][knid(_l)][_log2[_r-_l+1]],st[_kid][knid(_r)-(1<<(_log2[_r-_l+1]))+1][_log2[_r-_l+1]])%mod)
// @param _kid kuai's id
// @param _l big index of left
// @param _r big index of right
#define query(_kid,_l,_r) (max(st[_kid][knid(_l)][_log2[_r-_l+1]],st[_kid][knid(_r)-(1<<(_log2[_r-_l+1]))+1][_log2[_r-_l+1]]))

// _kid's left index in the big
#define left(_kid) (_kid*lk+1)
#define right(_kid) min(n,(_kid+1)*(lk))

// #define kbeg(_kid) ()
#define knend(_kid) (_kid==kid(n)?((n)%lk==0?lk:(n)%lk):lk)// the knid of this _kid kuai 's end]  ??????????
// #define right(_kid) min(n,left(_kid)+lk-1)
int main()
{
	freopen("P3865_4.in","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	// n=getint();
	int q;
	// q=getint();
	scanf("%d",&q);
	int _log2[n+1];
	_log2[1]=0;
	for(int i=2;i<=n;i++)
	{
		_log2[i]=_log2[i>>1]+1;
	}
	int a[n+2];
	// puts("st.");
	int st[div+1][lk+1][_log2[lk]+1];/////////
	puts("bst.");
	int bst[div+1][_log2[div+1]+1];
	fill(**st,**st+(div+1)*(lk+1)*(_log2[lk]+1),1);
	fill(*bst,*bst+(div+1)*(_log2[div+1]+1),-0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		// a[i]=getint();
		st[kid(i)][knid(i)][0]=a[i];
	}
	for(int k=0;k<=div;k++)
	{
		if((k<div)||((k==div)&&(n%div)))
		{
			for(int j=1;j<=_log2[knend(k)];j++)
			{
				for(int i=1;i<=knend(k)-(1<<j)+1;i++)
				{
					st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<(j-1))][j-1]);
				}
			}
			bst[k][0]=query(k,left(k),right(k));
		}
	}
	for(int j=1;j<=_log2[div+1];j++)
	{
		for(int i=0;i<=div+1-(i<<j)+1;i++)
		{
			bst[i][j]=max(bst[i][j-1],bst[i+(1<<(j-1))][j-1]);
		}
	}
	// scanf("%d",&q);
	int l,r;
	int res=-0x3f3f3f3f;
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&l,&r);
		// l=getint();
		// r=getint();
		if(kid(l)==kid(r))
		{
			res=query(kid(l),l,r);
		}
		else if(kid(l)<kid(r))
		{
			res=query(kid(l),l,right(kid(l)));
			/* for(int j=kid(l)+1;j<kid(r);j++)
			{
				res=max(res,query(j,left(j),right(j)));
			} */
			if(kid(l)+1<=kid(r)-1)
			{
				#define len _log2[kid(r)-kid(l)-1]
				res=max(res,max(bst[kid(l)+1][len],bst[kid(r)-1-(1<<len)+1][len]));
			}
			res=max(res,query(kid(r),left(kid(r)),r));
		}
		printf("%d\n",res);
	}
	return 0;
}
