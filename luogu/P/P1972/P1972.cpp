#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;

#include <cstdio>
#include <cctype>

namespace io
{
	constexpr int BUFSIZE = 21 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE;
	inline void init()
	{
		it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
	}
	inline char getch()
	{
		// if (is == it)
		// 	it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		return /* (is == it) ? EOF :  */*is++;
	}
	inline int getint()
	{
		int res = 0;
		char ch = getch();
		while (!(isdigit(ch))/*  and ch != EOF */)
			ch = getch();
		while (isdigit(ch))
			res = res * 10 + (ch - '0'), ch = getch();
		return res;
	}
	inline void flush()
	{
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void putch(char ch)
	{
		*os++ = ch;
		// if (os == ot)
		// 	flush();
	}
	inline void putint(int res)
	{
		char q[10];
		int top;
		top = 0;
		while (res)
			q[top++] = res % 10 + '0', res /= 10;
		while (top--)
			putch(q[top]);
	}
}

constexpr int N=1145141,A=1145141,M=1145141;
int n,m;
int a[N];

int S,bel[N];

struct query
{
	int l,r,id;
};
query q[M];
int ans[M];

int /* cnt[A], */bt=0;
int lst[A],pre[N],nxt[N];

void mt()
{
	S=int(ceil(1.732*n/pow(m,0.5)));// S=sqrt(n)
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
	sort(q+1,q+m+1,
	[](const query &x,const query &y)-> bool
	{
		return ((bel[x.l]!=bel[y.l])?
			bel[x.l]<bel[y.l]:
			((bel[x.l]&1)?
				x.r<y.r:
				x.r>y.r));
	});
	for(int i=1;i<=n;i++)pre[i]=lst[a[i]],lst[a[i]]=i;
	fill(lst,lst+A,0x3f3f3f3f);
	for(int i=n;i;i--)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		#define q q[i]
		// if(abs(q.l-l)+abs(q.r-r)>(r-l+1)+(q.r-q.l+1))
		// {
		// 	while(l<=r)bt-=(!--cnt[a[r--]]);//clr
		// 	r=(l=q.l)-1;
		// }
		while(q.l<l)bt+=(nxt[--l]>r);
		while(r<q.r)bt+=(pre[++r]<l);
		while(l<q.l)bt-=(nxt[l++]>r);
		while(q.r<r)bt-=(pre[r--]<l);
		// while (L > Opt[i].L) Sum += (Suf[--L] > R);
		// while (R < Opt[i].R) Sum += (Pre[++R] < L);
		// while (L < Opt[i].L) Sum -= (Suf[L++] > R);
		// while (R > Opt[i].R) Sum -= (Pre[R--] < L);
		ans[q.id]=bt;
		#undef q
	}
}

int main()
{
	io::init();
	n=io::getint();
	for(int i=1;i<=n;i++)
	{
		a[i]=io::getint();
	}
	m=io::getint();
	for(int i=1;i<=m;i++)
	{
		q[i].l=io::getint(),q[i].r=io::getint();
		q[i].id=i;
	}
	mt();
	for(int i=1;i<=m;i++)
	{
		// printf("%d\n",ans[i]);
		io::putint(ans[i]);
		io::putch('\n');
	}
	io::flush();
	return 0;
}