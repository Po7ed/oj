#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

/*
 * CheckList
 * "Yes" & "No"
 */

#include <cstdio>
#include <cctype>

namespace io
{
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE;
	inline char getch()
	{
		if (is == it)
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		return (is == it) ? EOF : *is++;
	}
	inline int getint()
	{
		int res = 0;
		bool neg = false;
		char ch = getch();
		while (!(isdigit(ch) or ch == '-') and ch != EOF)
			ch = getch();
		if (ch == '-')
			neg = true, ch = getch();
		while (isdigit(ch))
			res = res * 10 + (ch - '0'), ch = getch();
		return neg ? -res : res;
	}
	inline void flush()
	{
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void putch(char ch)
	{
		*os++ = ch;
		if (os == ot)
			flush();
	}
	inline void putint(int res)
	{
		char q[10];
		int top;
		if (res < 0)
			putch('-'), res = -res;
		if (res == 0)
			putch('0');
		top = 0;
		while (res)
			q[top++] = res % 10 + '0', res /= 10;
		while (top--)
			putch(q[top]);
	}
}

constexpr int N=114514;
int n,m;
int a[N];

int S;

inline int bel(int x)// 1~S: 1
{
	return (x-1)/S+1;
}

struct query
{
	int l,r,id;
	friend inline bool operator < (query x,query y)
	{
		if(bel(x.l)!=bel(y.l))return bel(x.l)<bel(y.l);
		if(bel(x.l)&1)return x.r<y.r;
		else return x.r>y.r;
	}
};
query q[N];
bitset<N> ans;

int cnt[N],cf=0;

void mt()
{
	S=int(ceil(pow(n,0.5)));// S=sqrt(n)
	sort(q+1,q+m+1);
	for(int i=1,l=0,r=0;i<=m;i++)
	{
		#define q q[i]
		if(abs(q.l-l)+abs(q.r-r)>(r-l+1)+(q.r-q.l+1))
		{
			while(l<=r)cf-=(--cnt[a[r--]]==1);//clr
			r=(l=q.l)-1;
		}
		while(q.l<l)cf+=(++cnt[a[--l]]==2);
		while(r<q.r)cf+=(++cnt[a[++r]]==2);
		while(l<q.l)cf-=(--cnt[a[l++]]==1);
		while(q.r<r)cf-=(--cnt[a[r--]]==1);
		ans[q.id]=!cf;
		#undef q
	}
}

int main()
{
	n=io::getint(),m=io::getint();
	for(int i=1;i<=n;i++)
	{
		a[i]=io::getint();
	}
	for(int i=1;i<=m;i++)
	{
		q[i].l=io::getint(),q[i].r=io::getint();
		q[i].id=i;
	}
	mt();
	for(int i=1;i<=m;i++)
	{
		puts(ans[i]?"Yes":"No");
	}
	return 0;
}