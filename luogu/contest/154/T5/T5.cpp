#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll id[50001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	map<ll,ll> fs;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",id+i);
	}
	ll tid,cj,kk=0,bjg=0;
	for(ll i=1;i<=m;i++)
	{
		cin>>tid>>cj;
		fs[tid]=cj;
	}
	for(ll i=1;i<=n;i++)
	{
		if(fs.count(id[i]))
		{
			if(fs[id[i]]<60)
			{
				bjg++;
			}
		}
		else
		{
			bjg++;
			kk++;
		}
	}
	cout<<kk<<"\n"<<bjg<<"\n";
	return 0;
}