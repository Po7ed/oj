#include <iostream>
#include <vector>
using namespace std;

int w[214514],sum=0,ma=-1;
vector<int> e[214514];
const int mod=10007;


int main()
{
	int n;
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
	}
	int cnt,ma1,ma2;
	for(int now=1;now<=n;now++)
	{
		cnt=0,ma1=-1,ma2=-1;
		for(int son:e[now])
		{
			sum+=cnt*w[son];
			sum%=mod;
			cnt+=w[son];
			cnt%=mod;
			if(ma1<w[son])
			{
				ma2=ma1;
				ma1=w[son];
			}
			else if(ma2<w[son])
			{
				ma2=w[son];
			}
		}
		ma=max(ma,ma1*ma2);
	}
	printf("%d %d",ma,(sum*2)%mod);
	return 0;
}