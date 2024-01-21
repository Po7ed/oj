#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
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
	// inline cp operator ! (){return cp(a,-b);}// gong'e
	// inline void print(){printf("%lf+%lfi",a,b);}
};

int n,m;

cp w[N];
void init()// calc omega
{
	w[n]=w[0]={1,0};
	w[1]={cos(2*pi/n),sin(2*pi/n)};
	for(int i=2;i<n;i++)w[i]=w[i-1]*w[1];
}

int cn,dis;
cp getw(int i,int base)// get omega
{
	dis=cn-__builtin_ctz(base);// n/base=1<<dis
	return w[i<<dis];// w_base^i=w_{base<<dis}^{i<<dis}=w_n^{i<<dis}
}// good!

cp f[N],g[N];

int rev[N];

// flg=1:dft;flg=0:idft
void fft(cp *f,int len=n)// dft&idft
{
	if(len==1)return;
	fft(f,len>>1),fft(f+(len>>1),len>>1);
	cp t;
	for(int k=0;k<(len>>1);k++)
	{
		t=getw(k,len)*f[(len>>1)+k];
		// printf("w_%d^%d=",len,k),getw(k,len).print(),puts("");
		f[(len>>1)+k]=f[k]-t;
		f[k]=f[k]+t;
	}
}

inline void swp(cp* f){for(int i=0;i<n;i++)if(rev[i]<i)swap(f[rev[i]],f[i]);}

int main()
{
	clock_t beg=clock();
	freopen("rand.in","r",stdin);
	freopen("func.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++)scanf("%lf",&f[i].a);
	for(int i=0;i<=m;i++)scanf("%lf",&g[i].a);
	for(m+=n,n=1;n<=m;n<<=1,cn++);// up to 2^cn
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
	swp(f),swp(g),init(),fft(f),fft(g);/* puts(""); */
	for(int i=0;i<n;i++)f[i]=f[i]*g[i];
	swp(f),reverse(w,w+n+1),fft(f);
	for(int i=0;i<=m;i++)printf("%d ",int((f[i].a/n)+.5));
	printf("***\n%ldms.\n",clock()-beg);
	return 0;
}