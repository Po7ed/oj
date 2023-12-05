#include <iostream>
// #include <numeric>
#include <algorithm>
// #include <vector>
#include <queue>
using namespace std;

struct plane
{
	int l,r;
	friend inline bool operator < (plane x,plane y)
	{
		return x.l<y.l;
	}
};

const int N=114514;
int n,m1,m2;
// plane list[N];
// int tail;
int ca[N],cb[N],nxt[N],na[N],nb[N];
// m:planes
struct message
{
	int out,id;
	friend inline bool operator < (message x,message y)
	{
		return x.out>y.out;
	}
};
int check(plane* a,int* c,int m)
{
	int res=0;
	priority_queue<message> in;
	priority_queue<int,vector<int>,greater<int>> free;
	for(int i=1;i<=n;i++)
	{
		free.push(i);
	}
	for(int i=1;i<=m;i++)
	{
		while(!in.empty()&&in.top().out<a[i].l)
		{
			free.push(in.top().id);
			in.pop();
		}
		if(!free.empty())
		{
			in.push({a[i].r,free.top()});
			c[free.top()]++;
			free.pop();
			res++;
		}
	}
	return res;
}

plane a[N],b[N];

int main()
{
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d %d",&b[i].l,&b[i].r);
	}
	sort(a+1,a+m1+1);
	sort(b+1,b+m2+1);
	na[n]=check(a,ca,m1);
	nb[n]=check(b,cb,m2);
	for(int i=n-1;i>=0;i--)
	{
		na[i]=na[i+1]-ca[i+1];
		nb[i]=nb[i+1]-cb[i+1];
	}
	int ans=-1;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,na[i]+nb[n-i]);
	}
	// puts("");
	printf("%d",ans);
	return 0;
}