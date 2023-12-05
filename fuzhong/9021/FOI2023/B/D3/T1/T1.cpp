#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct thing
{
	int type,v,id;
};

bool c1(thing a,thing b)
{
	return a.v==b.v?a.type>b.type:a.v<b.v;
}
bool c2(thing a,thing b)
{
	return a.id<b.id;
}

struct _modify
{
	int pos,l,r;
	bool f;
};

int main()
{
	// freopen("toy.in","r",stdin);
	// freopen("toy.out","w",stdout);
	int n;
	scanf("%d",&n);
	thing a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].type,&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+(n+1),c1);
	int pos[n+1];
	for(int i=1;i<=n;i++)
	{
		pos[a[i].id]=i;
	}
	sort(a+1,a+(n+1),c2);
	int present[4*n+1],toy[4*n+1],box[4*n+1];
	fill(present,present+(4*n+1),0);
	fill(toy,toy+(4*n+1),0);
	fill(box,box+(4*n+1),0);
	vector<_modify> modify;
	_modify t;
	#define ls (t.pos<<1)
	#define rs (t.pos<<1|1)
	#define m ((t.l+t.r)>>1)
	for(int i=1;i<=n;i++)
	{
		modify.push_back({1,1,n,false});
		while(!modify.empty())
		{
			t=modify.back();
			if(t.f)
			{
				present[t.pos]=present[ls]+present[rs]+min(box[rs],toy[ls]);
				toy[t.pos]=toy[rs]+max(0,toy[ls]-box[rs]);
				box[t.pos]=box[ls]+max(0,box[rs]-toy[ls]);
				modify.pop_back();
				continue;
			}
			if(t.l==t.r)
			{
				if(a[i].type)
				{
					toy[t.pos]=1;
				}
				else
				{
					box[t.pos]=1;
				}
				modify.pop_back();
				continue;
			}
			// t.f=true;
			modify.back().f=true;
			if(pos[i]<=m)
			{
				modify.push_back({ls,t.l,m,false});
			}
			else
			{
				modify.push_back({rs,m+1,t.r,false});
			}
		}
		printf("%d\n",present[1]);
	}
	return 0;
}