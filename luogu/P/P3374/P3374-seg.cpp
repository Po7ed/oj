#include <iostream>
using namespace std;
#define mn 100001

typedef long long ll;

int n,m;
ll a[mn],d[4*mn];

void Build(int l,int r,int root)
{
	if(l==r)
	{
		d[root]=a[l];
		return;
	}
	int mid=l+((r-l)>>1);
	Build(l,mid,2*root);
	Build(mid+1,r,2*root+1);
	d[root]=d[2*root]+d[2*root+1];
	return;
}

ll query(int l,int r,int ql,int qr,int pos)
{
	if(ql<=l&&r<=qr)
	{
		return d[pos];
	}
	int mid=l+((r-l)>>1);
	ll s=0;
	if(ql<=mid)
	{
		s+=query(l,mid,ql,qr,2*pos);
	}
	if(mid<qr)
	{
		s+=query(mid+1,r,ql,qr,2*pos+1);
	}
	return s;
}

void modify(int l,int r,int x,int pos,ll k)
{
	d[pos]+=k;
	if(l==r)
	{
		a[l]+=k;
		return;
	}
	int mid=l+((r-l)>>1);
	if(x<=mid)
	{
		modify(l,mid,x,2*pos,k);
	}
	if(mid<x)
	{
		modify(mid+1,r,x,2*pos+1,k);
	}
	return;
}

int main()
{
	scanf("%d %d",&n,&m);
	// int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	Build(1,n,1);
	// puts("Build Done");
	int x,y,opt;
	ll k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt-1)
		{
			scanf("%d %d",&x,&y);
			printf("%lld\n",query(1,n,x,y,1));
		}
		else
		{
			scanf("%d %lld",&x,&k);
			modify(1,n,x,1,k);
		}
	}
	return 0;
}