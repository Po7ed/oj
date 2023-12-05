#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int N=1145141;
int a[N],pma[N],sma[N],pmi[N],smi[N];
ll suma,sumi;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> ma,mi;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		while(!ma.empty()&&a[ma.back()]<a[i])
		{
			ma.pop_back();
		}
		if(ma.empty())
		{
			pma[i]=0;
		}
		else
		{
			pma[i]=ma.back();
		}
		ma.push_back(i);
		while(!mi.empty()&&a[mi.back()]>a[i])
		{
			mi.pop_back();
		}
		if(mi.empty())
		{
			pmi[i]=0;
		}
		else
		{
			pmi[i]=mi.back();
		}
		mi.push_back(i);
	}
	mi.clear();
	ma.clear();
	for(int i=n;i>0;i--)
	{
		while(!ma.empty()&&a[ma.back()]<=a[i])
		{
			ma.pop_back();
		}
		if(ma.empty())
		{
			sma[i]=n+1;
		}
		else
		{
			sma[i]=ma.back();
		}
		ma.push_back(i);
		while(!mi.empty()&&a[mi.back()]>=a[i])
		{
			mi.pop_back();
		}
		if(mi.empty())
		{
			smi[i]=n+1;
		}
		else
		{
			smi[i]=mi.back();
		}
		mi.push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		suma+=(a[i]*(i-pma[i])*(sma[i]-i));
		sumi+=(a[i]*(i-pmi[i])*(smi[i]-i));
	}
	printf("%lld",suma-sumi);
	return 0;
}