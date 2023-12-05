#include <iostream>
using namespace std;
typedef long long ll;
const int N=1e7+10,mod=998244353;
inline int inc(int x,int y){return x+y>=mod?x+y-mod:x+y;} // 加法
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;} // 减法
inline int mul(int x,int y){return (ll)x*y%mod;} // 乘法
inline int qpow(int x,int y){ // 快速幂运算
	int r=1;
	for(;y;y>>=1){
		if(y&1)r=mul(r,x);
		x=mul(x,x);
	}return r;
}
inline int inv(int x){return qpow(x,mod-2);} // 逆元运算
int fac[N],inf[N];
void init(int n){ // 预处理部分
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=mul(fac[i-1],i);
	inf[n]=inv(fac[n]);
	for(int i=n-1;~i;--i)inf[i]=mul(inf[i+1],i+1);
}
inline int C(int n, int m)
{
    if(n<m||m<0)
        return 0;
    return mul(fac[n],mul(inf[m],inf[n-m]));
}

int main()
{
	int n,m,a,b,c,x,y;
	scanf("%d %d %d %d %d %d %d",&n,&m,&a,&b,&c,&x,&y);
	init(n);
	int ans=0;
	for(int i=0;i<=a;i++)
	{
		ans=inc(ans,mul(mul(C(a,i),C(c,x-i)),mul(C(c-x+i+b,y),C(n-x-y,m-x-y))));
	}
	printf("%d",ans);
	return 0;
}