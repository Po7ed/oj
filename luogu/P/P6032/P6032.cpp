#include <iostream>
// #include <vector>
using namespace std;

typedef long long ll;

ll ans,cnt[10051];
int color[1000114];

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
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return res;
}

int main()
{
	int n,k,p;
// 	scanf("%d %d %d",&n,&k,&p);
    n=read(),k=read(),p=read();
	int a,b,last;
	for(int i=1;i<=n;i++)
	{
// 		scanf("%d %d",&a,&b);
        color[i]=read(),b=read();
		if(b<=p)
		{
			for(int j=i;j>last;j--)
			{
				cnt[color[j]]++;
			}
			ans+=cnt[color[i]]-1;
			last=i;
		}
		else
		{
			ans+=cnt[color[i]];
		}
	}
	/* ll cnt=0;
	for(int i=0;i<k;i++)
	{
		cnt+=ans[i];
	} */
	printf("%lld",ans);
}
/* 
5 2 3
0 5
1 3
0 2
1 4
1 5
 */