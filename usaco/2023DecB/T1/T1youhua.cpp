#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
/*
 * 13:06 开题
 * 13:22 增加 min(ai,bj)-ai-1，<0:=0
 * 若一头牛比前面矮，必然长不高
 * 13:23 二分 a：bj。先码输入
 * 13:30 先打 O(n^2)
 * 13:37 单调队列？
 * 13:45 码完了
 * 13:46 挂了。只过了一个点，弱智
 * 13:47 弱智，没有每次算单调队列
 * 13:49 再交一发|tmd sb
 * 13:51 开新文件
 * cao 垃圾gdb
 * 14:00 14/20*100 pts,O(n^2)
 * 14:08 调出原码
 * 14:09 交了，14/20*100 pts,O(n^2) 心态平稳
 * 润
 * 16:48 开改
 * 16:53 改完，交！
 * 跟原来一样，悲
 * 上快读
 * 16:58 交！！！
 * 不变……
 * 润
 */

#include <cstdio>
#include <cctype>
typedef long long ll;

namespace io
{
	constexpr int BUFSIZE = 1 << 17;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE;
	inline char getch()
	{
		if (is == it)
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		return (is == it) ? EOF : *is++;
	}
	inline ll getll()
	{
		ll res = 0;
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
	inline void putll(ll res)
	{
		char q[21];
		ll top;
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


constexpr int N=214514;
ll a[N],b[N];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=io::getll();
	for(int i=1;i<=m;i++)b[i]=io::getll();
	ll tmp;
	int lst;
	for(int j=1;j<=m;j++)
	{
		lst=0;
		tmp=0ll;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=a[lst]-tmp)continue;
			tmp=min(a[i],b[j])-a[lst]+tmp;
			if(tmp<0)tmp=0;
			a[i]+=tmp;
			lst=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		io::putll(a[i]);
		io::putch('\n');
	}
	io::flush();
	return 0;
}