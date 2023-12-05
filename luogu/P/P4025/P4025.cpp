#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
constexpr int N=114514;
int n,z;

struct m
{
	int d,r,id;
};
vector<m> a,b;
vector<int> ans;

inline bool cmp1(m x,m y)
{
	return x.d<y.d;
}
inline bool cmp2(m x,m y)
{
	return x.r>y.r;
}

int main()
{
	scanf("%d %d",&n,&z);
	for(int i=1,d,r;i<=n;i++)
	{
		scanf("%d %d",&d,&r);
		(r>d?a:b).push_back({d,r,i});
	}
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	ll l=1ll*z;
	for(m t:a)
	{
		l-=1ll*t.d;
		if(l<=0)
		{
			puts("NIE");
			return 0;
		}
		l+=1ll*t.r;
		ans.push_back(t.id);
	}
	for(m t:b)
	{
		l-=1ll*t.d;
		if(l<=0)
		{
			puts("NIE");
			return 0;
		}
		l+=1ll*t.r;
		ans.push_back(t.id);
	}
	puts("TAK");
	for(int t:ans)
	{
		printf("%d ",t);
	}
	return 0;
}