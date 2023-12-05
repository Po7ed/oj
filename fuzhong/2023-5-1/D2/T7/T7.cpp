#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

typedef unsigned long long ull;
#define lowbit(i) ((i)&(-(i)))

ull read()
{
	static ull ret;
	static char ch;
	ret=0;
	ch=getchar();
	while(ch!=EOF&&!isdigit(ch))
	{
		// sgn|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ret=ret*10+(ch-48);
		ch=getchar();
	}
	return ret;
}

int main()
{
	freopen("god.in","r",stdin);
	freopen("god.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	ull a[n+1],c[n+1];
	boll b[n+1];
	fill(c,c+n+1,0);
	fill(c,c+n+1,false);
	for(int i=1;i<=n;i++)
	{
		// scanf("%llu",&a[i]);
		a[i]=read();
		for(int x=i;x<=n;x+=lowbit(x))
		{
			c[x]+=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==lowbit(i))
		{
			b[i]=true;
		}
	}
	int k,l,r;
	int s1,s2;
	int d;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&k,&l,&r);
		if(l>r)
			swap(l,r);
		if(k)
		{
			s1=s2=0;
			for(int x=l-1;x>0;x-=lowbit(x))
			{
				s1+=c[x];
			}
			if(s1==l-1)
			{
				b[l-1]=true;
			}
			for(int x=r;x>0;x-=lowbit(x))
			{
				s2+=c[x];
			}
			if(s2==r)
			{
				b[r]=true;
			}
			printf("%d\n",s2-s1);
		}
		else
		{
			for(int j=l;j<=r;j++)
			{
				if(b[j])
				{
					j=lowbit(j)-1;
					continue;
				}
				if(a[j]==1)
					continue;
				d=a[j]-(ull)floor(sqrt((double)a[j]));
				a[j]-=d;
				for(int x=j;x<=n;x+=lowbit(x))
				{
					c[x]-=d;
					if(c[x]==lowbit(x))
					{
						b[x]=true;
					}
				}
			}
		}
	}
	return 0;
}