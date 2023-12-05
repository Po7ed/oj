#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef struct light
{
	int id,v;
}li;

typedef struct range
{
	int l,r;
	friend bool operator < (range a,range b)
	{
		return (a.l<b.l);
	}
}ra;

inline bool cmp(li a,li b)
{
	return (a.v==b.v?a.id<b.id:a.v<b.v);
}

set<ra> s;
int sum;
inline void insert(int pos)
{
	auto p=s.upper_bound({pos,pos});
	int l=pos,r=pos;
	if(p->l==pos+1)
	{
		r=p->r;
		sum-=(p->r-p->l+2)/2;
		p=s.erase(p);
	}
	if(p!=s.begin())
	{
		--p;
		if(p->r==pos-1)
		{
			l=p->l;
			sum-=(p->r-p->l+2)/2;
			s.erase(p);
		}
	}
	s.insert({l,r});
	sum+=(r-l+2)/2;
}

inline void erase(int pos)
{
	auto p=--s.upper_bound({pos,pos});
	int l=p->l,r=p->r;
	s.erase(p);
	sum-=(r-l+2)/2;
	if(l!=pos)
	{
		s.insert({l,pos-1});
		sum+=((pos-1)-l+2)/2;
	}
	if(r!=pos)
	{
		s.insert({pos+1,r});
		sum+=(r-(pos+1)+2)/2;
	}
}

int main()
{
	// freopen("D3.in","r",stdin);
	// freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	li a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=1,ans=0x3f3f3f3f;
	s.insert({a[1].id,a[1].id});
	sum=1;
	for(;l<=n;l++)
	{
		while(r!=n&&sum<m)
		{
			insert(a[++r].id);
		}
		if(sum<m)
		{
			break;
		}
		ans=min(ans,a[r].v-a[l].v);
		erase(a[l].id);
	}
	printf("%d\n",ans);
	return 0;
}