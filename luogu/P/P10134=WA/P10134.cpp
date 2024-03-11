#include <iostream>
#include <algorithm>
#include <bitset>

constexpr int N=114514,INF=0x3f3f3f3f;
int n,q,mc;
int c[N],a[N],pre[N];
std::bitset<N> b;

int main()
{
	// freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	pre[0]=-INF;
	while(T--)
	{
		scanf("%d %d %d",&n,&q,&mc);
		for(int i=1;i<=n;i++)scanf("%d",c+i),a[i]=INF,b[i]=!c[i];
		int x,y;
		while(q--)
		{
			scanf("%d %d",&x,&y);
			a[y]=std::min(a[y],x);
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i])
			{
				if(a[i]!=INF)
				{
					if(pre[i-1]!=pre[a[i]]&&b[a[i]])
					{
						c[a[i]]=pre[i-1];
						pre[a[i]]=pre[i-1];
					}
					else if(pre[i-1]!=pre[a[i]])
					{
						puts("-1");
						goto brk;
					}
				}
			}
			else
			{
				if(a[i]!=INF)
				{
					if(pre[i-1]!=pre[a[i]]&&b[a[i]])
					{
						c[a[i]]=pre[i-1];
						pre[a[i]]=pre[i-1];
						// puts("-1");
						// goto brk;
					}
					c[i]=pre[a[i]]+1;
				}
				else
				{
					c[i]=1;
				}
			}
			if(c[i]>mc)
			{
				puts("-1");
				goto brk;
			}
			pre[i]=std::max(pre[i-1],c[i]);
		}
		for(int i=1;i<=n;i++)
		{
			pre[i]=std::max(pre[i-1],c[i]);
			if(a[i]!=INF&&!(pre[a[i]]<c[i]&&pre[i-1]==pre[a[i]]))
			{
				puts("-1");
				goto brk;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",c[i]);
		}
		puts("");
		brk:;
	}
	return 0;
}