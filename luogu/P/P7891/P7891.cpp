#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	scanf("%lld",&n);
	vector<long long> v;
	long long t;
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&t);
		v.insert(lower_bound(v.begin(),v.end(),t,greater<long long>()),t);
	}
	long long a=0,b=0;
	for(long long i=1;v.size();i++)
	{
		if(i&1)
		{
			if(a<v.back())
			{
				a+=v.back();
				v.pop_back();
			}
			else
			{
				t=lower_bound(v.begin(),v.end(),a,greater<long long>())-v.begin();
				a+=v[t];
				v.erase(v.begin()+t);
			}
		}
		else
		{
			if(b<v.back())
			{
				b+=v.back();
				v.pop_back();
			}
			else
			{
				t=lower_bound(v.begin(),v.end(),b,greater<long long>())-v.begin();
				b+=v[t];
				v.erase(v.begin()+t);
			}
		}
	}
	printf("%lld %lld",a,b);
	return 0;
}