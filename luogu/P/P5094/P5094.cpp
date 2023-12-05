#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
	int v,x;
	friend bool operator < (cow p,cow q)
	{
		return p.v<q.v;
	}
};

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


/* inline int Dis(int x,int y)
{
	return (x-y>=0?x-y:y-x);
} */

int main()
{
	int n;
	n=read();
	size_t ans=0,tmp;
	cow a[n+1];
	for(int i=1;i<=n;i++)
	{
		a[i].v=read(),a[i].x=read();
	}
	sort(a+1,a+(n+1));
	for(int i=1;i<=n;i++)
	{
		tmp=0;
		for(int j=1;j<i;j++)
		{
			tmp+=abs(a[i].x-a[j].x);
		}
		ans+=(tmp*a[i].v);
	}
	printf("%llu",ans);
	return 0;
}