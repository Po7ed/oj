#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct man
{
	int p,v;
	// int id;
	friend bool operator < (man a,man b)
	{
		return a.p<b.p;
	}
};

int main()
{
	freopen("arnival.in","r",stdin);
	freopen("arnival.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	// int p[n+1],v[n+1];
	man a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].p,&a[i].v);
		// a[i].id=i;
	}
	sort(a+1,a+(n+1));
	deque<int> q;// id
	bool f[n+1][2];
	// int t[n+1][2];
	fill(*f,*f+(n+1)*(2),false);
	// fill(*t,*t+(n+1)*(2),-1);
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&a[q.back()].v<a[i].v)
		{
			q.pop_back();
		}
		while(!q.empty()&&a[q.front()].p<a[i].p-k)
		{
			q.pop_front();
		}
		if(!q.empty()&&a[q.front()].v>=a[i].v*2)
		{
			f[i][0]=true;
			// t[a[i].id][0]=a[q.front()].id;
		}
		q.push_back(i);
	}
	q.clear();
	for(int i=n;i>0;i--)
	{
		while(!q.empty()&&a[q.back()].v<a[i].v)
		{
			q.pop_back();
		}
		while(!q.empty()&&a[q.front()].p>a[i].p+k)
		{
			q.pop_front();
		}
		if(!q.empty()&&a[q.front()].v>=a[i].v*2)
		{
			f[i][1]=true;
			// t[a[i].id][1]=a[q.front()].id;
		}
		q.push_back(i);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(int)(f[i][0]&&f[i][1]);
		// printf("%d:%d&%d ",a[i].id,t[a[i].id][0],t[a[i].id][1]);
	}
	printf("%d",cnt);
	return 0;
}