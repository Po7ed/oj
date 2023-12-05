#include <iostream>
// #include <vector>
#include <map>
using namespace std;

typedef pair<int,int> line;
#define _k .first
#define _b .second

// vector<line> l;
line l[114514];
int tail=0;

// int cnt[214514];
map<int,int> cnt;

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
	int cur;
	for(int i=1;i<=n;i++)
	{
		// scanf("%d %d %d",&opt,&k,&b);
		opt=read();
		k=read();
		b=read();
		if(opt==1)
		{
			// l.push_back({k,b});
			l[tail++]={k,b};
			cnt[k]++;
			// cnt[k]=(cnt.count(k)?cnt[k]+1:1);
		}
		else if(opt==2)
		{
			printf("%d\n",(tail-cnt[k]/* (cnt.count(k)?cnt[k]:0) */));
		}
		else
		{
			// vector<line> tmp;
			cur=0;
			// for(line t:l)
			#define t l[i]
			for(int i=0;i<tail&&cur<cnt[k];i++)
			{
				if((t _k)==k&&(t _b)!=b)
				{
					l[cur++]=t;
					// tmp.push_back(t);
				}
				/* if(tmp.size()==cnt[k])
				{
					break;
				} */
			}
			tail=cur;
			// l=tmp;
			cnt.clear();
			// cnt[k]=tmp.size();
			cnt[k]=cur;
			// auto p=l.begin();
			/* #define p (l.begin()+cur)
			cur=0;
			while(p!=l.end())
			{
				if((p _k)!=k||((p _k)==k&&(p _b)==b))
				{
					cnt[(p _k)]--;
					l.erase(p);
				}
				else
				{
					cur++;
				}
			} */
		}
	}
	return 0;
}