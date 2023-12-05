#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	long long a[n+1],s[n+1];
	s[0]=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	long long l[n+1],r[n+1];
	vector<long long> v;
	for(long long i=1;i<=n;i++)
	{
		while(!v.empty()&&a[v.back()]>=a[i])
			v.pop_back();
		l[i]=(v.empty()?0:v.back());
		v.push_back(i);
	}
	v.clear();
	for(long long i=n;i>=1;i--)
	{
		while(!v.empty()&&a[v.back()]>=a[i])
			v.pop_back();
		r[i]=(v.empty()?n+1:v.back());
		v.push_back(i);
	}
	long long ans=-1;
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,(s[r[i]-1]-s[l[i]])*a[i]);
	}
	printf("%lld",ans);
	return 0;
}