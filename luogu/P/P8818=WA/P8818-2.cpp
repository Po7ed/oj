#include <iostream>
using namespace std;

typedef long long ll;
const int N=114514,LN=20,INF=0x3f3f3f3f;
int log[N];
inline void initlog()
{
	log[1]=0;
	for(int i=2;i<=N;i++)
	{
		log[i]=log[i>>1]+1;
	}
}

struct st
{
	int ma[N][LN],mi[N][LN],pmi[N][LN],nma[N][LN];
	st(int *a,int n)
	{
		fill(*ma,*ma+N*LN,-INF);
		fill(*mi,*mi+N*LN,INF);
		fill(*pmi,*pmi+N*LN,INF);
		fill(*nma,*nma+N*LN,-INF);
		for(int i=1;i<=n;i++)
		{
			ma[i][0]=mi[i][0]=a[i];
			if(a[i]>=0)
			{
				pmi[i][0]=a[i];
			}
			if(a[i]<=0)
			{
				nma[i][0]=a[i];
			}
		}
		for(int j=1;j<=LN;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				ma[i][j] =max(ma[i][j-1] ,ma [i+(1<<(j-1))][j-1]);
				mi[i][j] =min(mi[i][j-1] ,mi [i+(1<<(j-1))][j-1]);
				pmi[i][j]=min(pmi[i][j-1],pmi[i+(1<<(j-1))][j-1]);
				nma[i][j]=max(nma[i][j-1],nma[i+(1<<(j-1))][j-1]);
			}
		}
	}
	#define MA 0
	#define MI 1
	#define PMI 2
	#define NMA 3
	inline int query(int l,int r,const int CODE)
	{
		if(CODE==MA)
		{
			return max(ma[l][log[r-l+1]],ma[r-(1<<log[r-l+1])+1][log[r-l+1]]);
		}
		if(CODE==MI)
		{
			return min(mi[l][log[r-l+1]],mi[r-(1<<log[r-l+1])+1][log[r-l+1]]);
		}
		if(CODE==PMI)
		{
			return min(pmi[l][log[r-l+1]],pmi[r-(1<<log[r-l+1])+1][log[r-l+1]]);
		}
		if(CODE==NMA)
		{
			return max(nma[l][log[r-l+1]],nma[r-(1<<log[r-l+1])+1][log[r-l+1]]);
		}
		return 114514;
	}
};

int n,m,q;
int a[N],b[N];

int main()
{
	initlog();
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",b+i);
	}
	st sta(a,n),stb(b,m);
	int l1,r1,l2,r2;
	bool ap,an,bp,bn;
	ll t1,t2;
	while(q--)
	{
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		ap=(sta.query(l1,r1,MA)>=0);
		an=(sta.query(l1,r1,MI)<=0);
		bp=(stb.query(l2,r2,MA)>=0);
		bn=(stb.query(l2,r2,MI)<=0);
		if(ap&&an)
		{
			if(bp&&bn)
			{
				t1=1ll*sta.query(l1,r1,PMI)*stb.query(l2,r2,MI);
				t2=1ll*sta.query(l1,r1,NMA)*stb.query(l2,r2,MA);
				t1=max(t1,t2);
			}
			else if(bp)
			{
				t1=1ll*sta.query(l1,r1,MA)*stb.query(l2,r2,MI);
			}
			else
			{
				t1=1ll*sta.query(l1,r1,MI)*stb.query(l2,r2,MA);
			}
		}
		else if(ap)
		{
			if(bn)
			{
				t1=1ll*sta.query(l1,r1,MI)*stb.query(l2,r2,MI);
			}
			else
			{
				t1=1ll*sta.query(l1,r1,MA)*stb.query(l2,r2,MI);
			}
		}
		else
		{
			if(bp)
			{
				t1=1ll*sta.query(l1,r1,MA)*stb.query(l2,r2,MA);
			}
			else
			{
				t1=1ll*sta.query(l1,r1,MI)*stb.query(l2,r2,MA);
			}
		}
		printf("%lld\n",t1);
	}
	return 0;
}