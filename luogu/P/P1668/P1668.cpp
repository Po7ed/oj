#include <iostream>
using namespace std;

typedef pair<int,int> pii;
constexpr int T=1145141;
int n,t;

int to[T];
pii pre[T];

int main()
{
	scanf("%d %d",&n,&t);
	for(int i=1,l,r;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		to[l]=max(to[l],r);
	}
	for(int i=1;i<=t;i++)
	{
		if(pre[i-1].second<to[i])pre[i]={i,to[i]};
		else pre[i]=pre[i-1];
	}
	int ans=1,l=1,r=to[l];
	while(r<t)
	{
		if(pre[r+1].second==r)
		{
			puts("-1");
			return 0;
		}
		l=pre[r+1].first;
		r=pre[r+1].second;
		ans++;
	}
	printf("%d",ans);
	return 0;
}