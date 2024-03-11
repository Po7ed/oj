#include <iostream>
#include <string>

typedef long long ll;

constexpr int B=300,M1=1e9+7,M2=1e9+9,N=5114514;

ll pre1,pre2,suf1,suf2,pow1,pow2;
ll deg[N];

int main()
{
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);
	std::string s;
	std::cin>>s;
	int n=s.length();
	s=' '+s;
	ll ans=0;
	pow1=pow2=1;
	for(int i=1;i<=n;i++)
	{
		pre1=(pre1*B+s[i])%M1;
		suf1=(suf1+pow1*s[i])%M1;
		pow1=pow1*B%M1;
		
		pre2=(pre2*B+s[i])%M2;
		suf2=(suf2+pow2*s[i])%M2;
		pow2=pow2*B%M2;
		if(pre1==suf1&&pre2==suf2)deg[i]=deg[i>>1]+1;
		ans+=deg[i];
	}
	std::cout<<ans<<'\n';
	return 0;
}