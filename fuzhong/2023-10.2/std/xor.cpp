#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld",&n);
	ll ans=0;
	if(n>=4){
		n-=4,ans++;
		ans+=n/4*2;
		n%=4;
		if(n>2)n=2;
		ans+=n;
		printf("%lld\n",ans);
	}
	else if(n>=2)puts("1");
	else puts("0");
	return 0;
}