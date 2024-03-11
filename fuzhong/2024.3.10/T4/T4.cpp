#include <iostream>
#include <algorithm>

typedef std::pair<int,int> pii;
constexpr int N=1145141,INF=0x3f3f3f3f;

pii a[N];
int n;

#define fo(x)\
freopen(#x ".in","r",stdin);\
freopen(#x ".out","w",stdout);

int main()
{
	fo(range)
	scanf("%d",&n);
	int pos=INF,cnt=0;
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i].first,&a[i].second);
	std::sort(a+1,a+n+1);
	for(int i=n;i;i--)if(pos>a[i].second)
	{
		pos=a[i].first;
		cnt++;
	}
	printf("%d 0",cnt);
	return 0;
}