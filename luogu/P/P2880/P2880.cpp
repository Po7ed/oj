#include <iostream>
using namespace std;

const int N=514114,L=17;
int a[N];
int ma[N][L],mi[N][L],log[N];
int n,q;

inline void init()
{
	log[1]=0;
	for(int i=2;i<N;i++)
	{
		log[i]=log[i>>1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		ma[i][0]=mi[i][0]=a[i];
	}
	for(int j=1;j<L;j++)
	{
		for(int i=1;i<=n;i++)
		{
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			// printf("%d %d:%d %d\n",i,j,ma[i][j],mi[i][j]);
		}
	}
}

inline int query(int l,int r)
{
	int len=log[r-l+1],a=max(ma[l][len],ma[r-(1<<len)+1][len]),b=min(mi[l][len],mi[r-(1<<len)+1][len]);
	return a-b;
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	init();
	int l,r;
	while(q--)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}