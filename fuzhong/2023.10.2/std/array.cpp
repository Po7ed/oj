#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<=t;++i)
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const int N=1e6+11;
int n;
int a[N],cnt,b[N];
int s[N],t[N];
int find(int x){
	return lower_bound(b,b+n+1,x)-b+1;
}
void ins(int x){
	for(;x<=(1e5)+1;x+=x&-x)
		++t[x];
}
int qry(int x){
	int ss=0;
	for(;x;x-=x&-x)
		ss+=t[x];
	return ss;
}
ll sol(int x){
	ll ans=0;
	rep(i,0,N-1)
		t[i]=0;
	rep(i,1,n){
		if(a[i]==x)
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1]-1;
		b[i]=s[i];
	}
	sort(b,b+n+1);
	rep(i,0,n){
		int x=find(s[i]);
		ans+=qry(x-1);
		ins(x);
	}
	return ans;
}
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n); 
	rep(i,1,n)
		scanf("%d",a+i);
	ll ans=0;
	rep(i,1,10)
		ans+=sol(i);
	printf("%lld\n",ans);
	return 0;
} 