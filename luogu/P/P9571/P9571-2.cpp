#include <iostream>
// #include <vector>
#include <map>
#include <unordered_map>
using namespace std;

typedef pair<int,int> line;
#define _k .first
#define _b .second

// vector<line> l;
line l[114514];
int tail=0;

// int cnt[214514];
map<int,int> cnt;
map<int,unordered_map<int,int>> g;
int n;

#include <cctype>
inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}

int main()
{
	// scanf("%d",&n);
	n=read();
	int opt,k,b;
	// int cur;
	for(int i=1;i<=n;i++)
	{
		// scanf("%d %d %d",&opt,&k,&b);
		opt=read();
		k=read();
		b=read();
		if(opt==1)
		{
			// l[tail++]={k,b};
			tail++;
			g[k][b]++;
			cnt[k]++;
		}
		else if(opt==2)
		{
			printf("%d\n",(tail-cnt[k]));
		}
		else
		{
			for(auto t:cnt)
			{
				if(t.first!=k)
				{
					g.erase(t.first);
					tail-=cnt[t.first];
				}
			}
			cnt.clear();
			tail-=g[k][b];
			cnt[k]=tail;
			g[k][b]=0;
			/* cur=0;
			#define t l[i]
			for(int i=0;i<tail&&cur<cnt[k];i++)
			{
				if((t _k)==k&&(t _b)!=b)
				{
					l[cur++]=t;
				}
			}
			tail=cur;
			cnt.clear();
			cnt[k]=cur; */
		}
	}
	return 0;
}