#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int fvv;
	string s;
	cin>>fvv>>s;
	// cin>>s;
	reverse(s.begin(),s.end());
	long long ans=0;
	for(char c:s)
	{
		if(ans>(long long)1e18)
		{
			puts("-1");
			return 0;
		}
		ans+=(c=='B'?1:0);
		ans<<=1;
	}
	printf("%lld",ans>>1);
	return 0;
}