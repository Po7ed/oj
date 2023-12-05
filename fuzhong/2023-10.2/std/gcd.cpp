#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<=t;++i)
using namespace std;
const int N=1e6+11;
#define ll long long
int n,x,c[N];
ll ans;
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		++c[x];
	}
	rep(i,1,1e3){
		rep(j,i+1,1e3)
			ans+=1ll*c[i]*c[j]*__gcd(i,j);
		ans+=1ll*c[i]*(c[i]-1)/2*i;
	}
	printf("%lld\n",ans);
	return 0;
}