#include <iostream>
#define lowbit(x) (-x&x)
using namespace std;

int n,m;
int a[500001],c[500001],s[500001];

void add(int x,int k)
{
	// a[x]+=k;
	for(;x<=n;x+=lowbit(x))
	{
		c[x]+=k;
	}
}

int sum(int x)
{
	int s=0;
	for(;x>0;x-=lowbit(x))
	{
		s+=c[x];
	}
	return s;
}

int sum(int x,int y)
{
	return sum(y)-sum(x-1);
}

int main()
{
	scanf("%d %d",&n,&m);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		c[i]=s[i]-s[i-lowbit(i)];
	}
	int f,x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&f,&x,&y);
		if(f==1)
		{
			add(x,y);
		}
		else
		{
			printf("%d\n",sum(x,y));
		}
	}
	return 0;
}