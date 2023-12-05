#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
	int h,id/* ,rk */;
	friend bool operator < (cow x,cow y)
	{
		return x.h>y.h;
	}
};

/* inline int read()
{
	int res=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
} */
#include <cstdio>
#include <cctype>
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch(){
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline int read(){
    int res = 0, ch = getch();
    while(!(isdigit(ch)) and ch != EOF)
        ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return res;
}

int n;

int bit[114514];
#define lowbit(x) ((-x)&x)
inline int query(int x){int ans=0;for(;x;x-=lowbit(x))ans+=bit[x];return ans;}
inline void modify(int x){for(;x<=n;x+=lowbit(x))bit[x]++;return;}


int main()
{
	// scanf("%d",&n);
	n=read();
	cow a[n+1];
	for(int i=1;i<=n;i++)
	{
		// scanf("%d",&a[i].h);
		a[i].h=read();
		a[i].id=i;
	}
	sort(a+1,a+(n+1));
	/* for(int i=1;i<=n;i++)
	{
		a[i].rk=
	} */
	int l,r,cnt=0;
	for(int i=1;i<=n;i++)
	{
		l=query(a[i].id);
		r=i-1-l;
		if((l*2<r)||(r*2<l))
		{
			// printf("*%d\n",a[i].id);
			cnt++;
		}
		modify(a[i].id);
	}
	printf("%d",cnt);
	return 0;
}