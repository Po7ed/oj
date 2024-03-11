#include <iostream>
#include <string>
#include <map>
#include <set>

using std::string;
using std::map;
using std::set;
constexpr int N=35;

int n,m;
string s[N];

map<string,int> cnt;
set<string> exi;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin>>n>>m;
	// scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		std::cin>>s[i];
		s[i]=" "+s[i];
	}
	int ans=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)
		{
			string t;
			for(int j=i;j<=m;j++)
			{
				t.push_back(s[k][j]);
				exi.insert(t);
			}
		}
		for(auto &t:exi)cnt[t]++;
		exi.clear();
	}
	// printf("%d\n",cnt.size());
	for(auto &t:cnt)if(t.second==n)
	{
		ans=std::max(ans,int(t.first.length()));
	}
	printf("%d",ans);
	return 0;
}