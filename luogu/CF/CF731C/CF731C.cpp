#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG

int f[int(2e5+1)];
// bool b[2e5+1];

int Find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=Find(f[x]);
}

inline void Union(int x,int y)
{
	f[Find(x)]=Find(y);
}

/* int bFind(int x)
{
	if(f[x]==x)
	{
		b[x]=true;
	}
} */

struct set
{
	int root;
	vector<int> son;
};
set s(int r)
{
	set t;
	t.root=r;
	return t;
}

int main()
{
#ifndef DEBUG
	freopen("slauqe.in","r",stdin);
	freopen("slauqe.out","w",stdout);
#endif
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	// scanf("%d",&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=i;
	}
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		Union(x,y);
	}
	// fill(b,b+n+1,false);
	map<int,int> ri;
	vector<set> rs;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			ri[i]=cnt++;
			rs.push_back(s(i));
		}
	}
	for(int i=1;i<=n;i++)
	{
		rs[ri[Find(i)]].son.push_back(a[i]);
	}
	for(set &t:rs)
	{
		sort(t.son.begin(),t.son.end());
	}
	int ans=0;
	for(set t:rs)//each set
	{
		cnt=0;
		int lst=-1,mx=-1;
		for(int i:t.son)//each element
		{
			if(lst!=-1&&lst!=i)
			{
				mx=max(mx,cnt);
				cnt=1;
				lst=i;
			}
			else
			{
				if(lst==-1)
				{
					lst=i;
					cnt=1;
				}
				else
				{
					cnt++;
				}
			}
		}
		mx=max(mx,cnt);
		ans+=(t.son.size()-mx);
	}
	printf("%d",ans);
	return 0;
}