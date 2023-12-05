#include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

#include <cstdio>
#include <cctype>
const int BUFSIZE = 1 << 20;
char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
inline char getch(){
    if(is == it)
        it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
    return is == it ? EOF : *is++;
}
inline int getint(){
    int res = 0, neg = 0, ch = getch();
    while(!(isdigit(ch) or ch == '-') and ch != EOF)
        ch = getch();
    if(ch == '-')
        neg = 1, ch = getch();
    while(isdigit(ch))
        res = res * 10 + (ch - '0'), ch = getch();
    return neg ? -res : res;
}

int main()
{
	int n;
	// scanf("%d",&n);
	n=getint();
	int u,v;
	vector<int> e[n+1];
	for(int i=1;i<n;i++)
	{
		// scanf("%d %d",&u,&v);
		u=getint();
		v=getint();

		e[u].push_back(v);
		e[v].push_back(u);
	}
	int d[n+1],now,pre;
	d[0]=0;
	e[0]={1};
	vector<pair<int,int>> dfs={make_pair(0,-1)};
	int s=0;
	while(!dfs.empty())
	{
		now=dfs.back().first;
		pre=dfs.back().second;
		dfs.pop_back();
		if(now)
		{
			d[now]=d[pre]+1;
		}
		s+=d[now];
		for(int to:e[now])
		{
			if(to!=pre)
			{
				dfs.push_back({to,now});
			}
		}
	}
	if(s&1)
	{
		puts("-1");
		return 0;
	}
	bool dp[s+1][s+1];
	int p[s+1][s+1];
	fill(*dp,*dp+(s+1)*(s+1),false);
	fill(*p,*p+(s+1)*(s+1),-1);
	dp[0][0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=s-d[i];j>=0;j--)
		{
			for(int k=s-d[i];k>=0;k--)
			{
				if(dp[j][k])
				{
					dp[j][k+d[i]]=dp[j+d[i]][k]=true;
					dp[j][k]=false;
					p[j+d[i]][k]=i;
					p[j][k+d[i]]=-i;
				}
			}
		}
	}
	if(dp[s/2][s/2]==false)
	{
		puts("-1");
	}
	else
	{
		bool w[n+1];
		fill(w,w+(n+1),false);
		int a=s/2,b=s/2;
		while(a||b)
		{
			if(p[a][b]>0)
			{
				w[p[a][b]]=true;
				a-=d[p[a][b]];
			}
			else
			{
				w[-p[a][b]]=false;
				b-=d[-p[a][b]];
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",(w[i]==true?1:0));
		}
	}
	return 0;
}