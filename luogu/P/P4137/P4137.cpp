#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>

namespace io
{
	constexpr int BUFSIZE = 10 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE;
	inline void init()
	{
		it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
	}
	inline char getch()
	{
		return *is++;
	}
	inline int getint()
	{
		int res = 0;
		char ch = getch();
		while (ch<'0'||ch>'9')
			ch = getch();
		while (ch>='0'&&ch<='9')
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
	}
	inline void putint(int res)
	{
		if(!res)return io::putch('0');
		static char q[20];
		int top = 0;
		while (res)
			q[top++] = res % 10ll + '0', res /= 10ll;
		while (top--)
			putch(q[top]);
	}
}

constexpr int N=214514,B=514;
int n,m,a[N];
struct qry{int l,r,id;};
qry q[N];

int S,bel[N];
int cnt[N],exi[B];
int ans[N];
void mt()
{
	S=int(ceil(n*pow(m,-.5)));
	for(int i=0;i<=n;i++)bel[i]=i/S+1;
	std::sort(q+1,q+m+1,[](qry x,qry y)->bool
	{
		return bel[x.l]!=bel[y.l]?
		(bel[x.l]<bel[y.l]):
		(bel[x.l]&1)==(x.r<y.r);
	});
	for(int i=1,l=1,r=0,j,k;i<=m;i++)
	{
		#define q q[i]
		while(q.l<l)l--,exi[bel[a[l]]]+=!(cnt[a[l]]++);
		while(r<q.r)r++,exi[bel[a[r]]]+=!(cnt[a[r]]++);
		while(l<q.l)exi[bel[a[l]]]-=!(--cnt[a[l]]),l++;
		while(q.r<r)exi[bel[a[r]]]-=!(--cnt[a[r]]),r--;
		for(j=1;j*S<=N&&exi[j]==S;j++);
		k=(j-1)*S;while(cnt[k])k++;
		ans[q.id]=k;
	}
}

int main()
{
	io::init();
	// scanf("%d %d",&n,&m);
	n=io::getint(),m=io::getint();
	for(int i=1;i<=n;i++)a[i]=io::getint();// scanf("%d",a+i);
	for(int i=1;i<=m;i++)q.l=io::getint(),q.r=io::getint()/* scanf("%d %d",&q.l,&q.r) */,q.id=i;
	mt();
	for(int i=1;i<=m;i++)io::putint(ans[i]),io::putch('\n');// printf("%d\n",ans[i]);
	io::flush();
	return 0;
}