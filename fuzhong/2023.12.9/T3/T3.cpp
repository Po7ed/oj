// 抽象
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int N=114514;
int n,m;

set<int> s[N*3];
map<int,int> id;

struct opt
{
	int x,y;
};
opt o[N];

vector<int> all;
int a[N];

int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	//^ input
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		all.push_back(a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&o[i].x,&o[i].y);
		all.push_back(o[i].x);
		all.push_back(o[i].y);
	}
	//^ LiSanHua
	sort(all.begin(),all.end());
	int l=all.size(),cnt=1;
	id[all[0]]=1;
	for(int i=1,lst=all[0];i<l;i++)
	{
		if(all[i]!=lst)
		{
			id[all[i]]=++cnt;
		}
		lst=all[i];
	}
	//^ init 's'
	for(int i=1;i<=n;i++)
	{
		s[id[a[i]]].insert(i);
	}
	//^ init ans
	int ans=0x7fffffff;
	for(int i=1,lst;i<=cnt;i++)
	{
		lst=-1;
		for(int t:s[i])
		{
			if(lst==-1)
			{
				lst=t;
				continue;
			}
			ans=min(ans,t-lst);
			lst=t;
		}
	}
	//^ work: opt
	for(int i=1;i<=m;i++)
	{
		if(s[id[o[i].x]].empty())
		{
			printf("%d\n",ans);
			continue;
		}
		s[id[o[i].y]].insert(s[id[o[i].x]].begin(),s[id[o[i].x]].end());
		s[id[o[i].x]].clear();
		int lst=-1;
		for(int t:s[id[o[i].y]])
		{
			if(lst==-1)
			{
				lst=t;
				continue;
			}
			ans=min(ans,t-lst);
			lst=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}