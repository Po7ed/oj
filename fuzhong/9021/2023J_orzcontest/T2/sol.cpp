#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
LL a,k,mod;
inline LL ksm(LL x,LL p){LL s=1;for(;p;(p&1)&&(s=s*x%mod),x=x*x%mod,p>>=1);return s;}
LL sol(LL x)
{
if(!x) return 1;
LL t=sol((x-1)>>1)*(ksm(a,(x+1)>>1)+1)%mod;
if(x&1^1) t=(t+ksm(a,x))%mod;return t;
}
int main()
{
cin>>a>>k>>mod;
cout<<sol(k);
return 0;
}