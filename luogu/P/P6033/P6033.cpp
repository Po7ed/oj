#include <iostream>
// #include <cstdio>
// #include <cstdlib>
#include <string.h>
#include <queue>
// #define read(a) {char c;while((c=getchar())>47) a=a*10+(c^48);}
using namespace std;

/* int read()
{
	int r=0;
	static char t;
	if(t<'0'||t>'9')
		t=getchar();
	while(t>='0'&&t<='9')
	{
		r=r*10+(t-'0');
		t=getchar();
	}
	// while()
	// getchar();
	return r;
} */
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main()
{
	int n;
	// scanf("%d",&n);
	n=read();
	// getchar();
	int c[100001];
	memset(c,0,sizeof(c));
	int t;
	for(int i=0;i<n;i++)
	{
		// scanf("%d",&t);
		t=read();
		c[t]++;
	}
	queue<long long> q1,q2;
	for(int i=1;i<=100000;i++)
	{
		for(int j=0;j<c[i];j++)
		{
			q1.push(i);
		}
	}
	long long a,b;
	long long ans=0;
	while(!(q1.empty()&&q2.size()==1))
	{
		if(q2.empty()||(!q1.empty()&&q1.front()<q2.front()))
		{
			a=q1.front();
			q1.pop();
		}
		else
		{
			a=q2.front();
			q2.pop();
		}
		if(q2.empty()||(!q1.empty()&&q1.front()<q2.front()))
		{
			b=q1.front();
			q1.pop();
		}
		else
		{
			b=q2.front();
			q2.pop();
		}
		ans+=(a+b);
		q2.push(a+b);
	}
	printf("%lld",ans);
	// write(ans);
	return 0;
}