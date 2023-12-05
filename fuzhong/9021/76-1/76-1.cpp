#include <iostream>
// #define u first \
   #define v second\
   #define p pair<int,int>

// #define f0en(i,n) for(int i=0;i<n;i++) \
   #define f1en(i,n) for(int i=1;i<n;i++) \
   #define f0tn(i,n) for(int i=0;i<=n;i++)\
   #define f1tn(i,n) for(int i=1;i<=n;i++)\

// #define _i int       \
   #define _l long      \
   #define _ll long long\
   #define _u unsigned  \
   #define _s signed    \
   #define _b bool      \
   #define _c char      \
   #define _d double    \
   #define _f float

using namespace std;

int f[30001],d[30001],n[30001];
int father(int k)
{
	if(!f[k])
	{
		return k;
	}
	int fk=father(f[k]);
	d[k]+=d[f[k]];
	return f[k]=fk;
}

int main()
{
	int t;
	scanf("%d\n",&t);
	int a,b;
	fill(f,f+30001,0);
	fill(n,n+30001,1);
	fill(d,d+30001,0);
	char op;
	for(int i=0;i<t;i++)
	{
		scanf("%c %d %d\n",&op,&a,&b);
		int fa=father(a),fb=father(b);
		if(op=='M')
		{
			d[fa]+=n[fb];
			f[fa]=fb;
			n[fb]+=n[fa];
			n[fa]=0;
		}
		if(op=='C')
		{
			if(fa!=fb)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n",abs(d[a]-d[b])-1);
			}
		}
	}
	return 0;
}