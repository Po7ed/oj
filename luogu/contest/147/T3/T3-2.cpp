#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N=1e8+3;
bool np[N];
int pri[N/10],cnt;
int mi[N],yg[N];//yg[i]+1,i/mi[i]
void init(int n)
{
	fill(mi,mi+N,0x3f3f3f3f);
	for(int i=2;i<=n;i++)
	{
		if(!np[i])
		{
			pri[++cnt]=i;
			mi[i]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			np[i*pri[j]]=1;
			mi[i*pri[j]]=min(mi[i*pri[j]],pri[j]);
			if(!(i%pri[j]))
				break;
		}
	}
}

int main()
{
	init(N-1);
/* for(int i=2;i<=15;i++)
{
	printf("%d:%d\n",i,mi[i]);
} */
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,f;
		scanf("%d",&n);
		if(n==2)
		{
			while(n--)scanf("%d",&f);
			puts("Yes");
			continue;
		}
		int a,mia;
		unordered_map<int,bool> m;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			while(a!=1)
			{
				if(m.count(mi[a]))
				{
					puts("No");
					for(int j=i+1;j<=n;j++)
					{
						scanf("%d",&f);
					}
					goto bre;
				}
				m[mi[a]]=true;
				mia=mi[a];
				while(a!=1&&a%mia==0)
				{
					a/=mia;
				}
			}
		}
		puts("Yes");
		bre:;
	}
	return 0;
}