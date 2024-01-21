#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int N=114514,NN=114,INF=0x3f3f3f3f;

int a[N];
int n,k;

namespace t1
{
	inline void solve(){puts("0 1");}
}// namespace t1

namespace t2
{
	void solve()
	{
		int ma=-INF,mi=INF,res=INF;
		for(int i=1;i<=n;i++)
		{
			ma=max(ma,a[i]);
			mi=min(mi,a[i]);
		}
		vector<int> pa,pi;
		for(int i=1;i<=n;i++)
		{
			if(ma==a[i])pa.push_back(i);
			if(mi==a[i])pi.push_back(i);
		}
		int pj;
		for(int i:pa)
		{
			pj=lower_bound(pi.begin(),pi.end(),i)-pi.begin();
			if(pj^pi.size())res=min(res,abs(pi[pj]-i)+1);
			if(pj)res=min(res,abs(pi[pj-1]-i)+1);
		}
		printf("%d %d\n",ma-mi,res);
	}
}// namespace t2

namespace t34
{
	void solve()
	{
		#define j (i+l-1)
		int mi[NN][NN],ma[NN][NN];
		vector<int> x;
		int now,res=0,len=1;
		for(int i=1;i<=n;i++)mi[i][i]=ma[i][i]=a[i];
		for(int l=2;l<=n;l++)
		{
			x.clear();
			for(int i=1;j<=n;i++)
			{
				mi[i][j]=min(mi[i][j-1],a[j]);
				ma[i][j]=max(ma[i][j-1],a[j]);
				x.push_back(ma[i][j]-mi[i][j]);
			}
			sort(x.begin(),x.end(),greater<int>());
			now=x[k-1];
			if(now>res)
			{
				res=now;
				len=l;
			}
		}
		printf("%d %d\n",res,len);
		#undef j
	}
}// namespace t34

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		bool ist1=true;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(i^1)
			{
				ist1=ist1&&(a[i]==a[i-1]);
			}
		}
		if(ist1)t1::solve();
		else if(k==1)t2::solve();
		else t34::solve();
	}
	return 0;
}