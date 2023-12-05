#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

ll bit[114514];
#define lowbit ((-x)&x)
int n;
ll query(int x)
{
	ll res=0;
	for(;x;x-=lowbit)
	{
		res+=bit[x];
	}
	return res;
}
void modify(int x)
{
	for(;x<=n;x+=lowbit)
	{
		bit[x]++;
	}
}
map<string,int> /* id, */pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// scanf("%d",&n);
	cin>>n;
	string a[n+1],t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		// id[a[i]]=n-i+1;
	}
	reverse(a+1,a+(n+1));
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		pos[t]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=query(pos[a[i]]);
		modify(pos[a[i]]);
	}
	printf("%lld",ans);
	return 0;
}