#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr int N=1<<21|1;
constexpr double pi=3.141592653589793;

struct cp
{
	double a,b;
	cp():a(0),b(0){}
	cp(double _a,double _b):a(_a),b(_b){}
	inline cp operator + (cp y){return cp(a+y.a,b+y.b);}
	inline cp operator - (cp y){return cp(a-y.a,b-y.b);}
	inline cp operator * (cp y){return cp(a*y.a-b*y.b,a*y.b+b*y.a);}
	// inline void print(){printf("(%lf+%lfi)",a,b);}
};

int n,m;

int rev[N];
void init()
{
	for(m+=n,n=1;n<=m;n<<=1);
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
}

void fft(cp *f,int sgn=1)
{
	for(int i=0;i<n;i++)if(rev[i]<i)swap(f[rev[i]],f[i]);
	cp t,w1,w;
	for(int l=2,hl=1;l<=n;hl=l,l<<=1)
	{
		w1={cos(2*pi/l),sgn*sin(2*pi/l)};
		for(int i=0;i<n;i+=l)
		{
			w={1,0};
			for(int k=i;k<i+hl;k++)
			{
				t=w*f[hl+k];
				f[hl+k]=f[k]-t;
				f[k]=f[k]+t;
				w=w*w1;
			}
		}
	}
}

cp f[N],g[N];
long long ans[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string t;
	cin>>t;n=t.size()-1;for(int i=0;i<=n;i++)f[i].a=t[i]-'0';
	cin>>t;m=t.size()-1;for(int i=0;i<=m;i++)g[i].a=t[i]-'0';
	init(),fft(f),fft(g);
	for(int i=0;i<n;i++)f[i]=f[i]*g[i];
	fft(f,-1);
	for(int i=0;i<=m;i++)ans[i]=(long long)(f[i].a/n+.5),printf("%d ",ans[i]);
	puts("");
	for(int i=m;i;i--)
	ans[i-1]+=(ans[i]/10),ans[i]%=10;
	for(int i=0;i<=m;i++)printf("%lld",ans[i]);
	return 0;
}