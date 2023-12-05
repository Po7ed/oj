#include <iostream>
using namespace std;

const int N=114514,BS=3;
int a[N];
int n,m,b;
int mb[10*BS],bel[N],btb[10*BS][10*BS],pre[10*BS][10*BS],suf[10*BS][10*BS];

inline void init()
{
	for(int i=1;i<=n;i++)// 1...BS:1
	{
		bel[i]=(i-1)/BS+1;
		mb[bel[i]]=max(mb[bel[i]],a[i]);
	}
	b=bel[n];
	for(int i=1;i<=b;i++)// btb
	{
		for(int j=i;j<=b;j++)
		{
			btb[i][j]=max(btb[i][j-1],mb[j]);
		}
	}
	#define id ((i-1)*BS+j)
	for(int i=1;i<=b;i++)// pre and suf
	// for each block
	{
		for(int j=1;j<=BS&&id<=n;j++)
		{
			pre[i][j]=max(pre[i][j-1],a[id]);
		}
		suf[i][BS]=a[(i*BS)];
		for(int j=BS-1;j;j--)
		{
			if(id>n)continue;
			suf[i][j]=max(suf[i][j+1],a[id]);
		}
	}
}

int main()
{
	// freopen("..\\P3865\\P3865_4.in","r",stdin);
	// freopen("out.txt","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	init();
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&l,&r);
		if(bel[l]==bel[r])
		{
			int res=0;
			for(int j=l;j<=r;j++)
			{
				res=max(res,a[j]);
			}
			printf("%d\n",res);
		}
		else
		{
			// printf("%d %d\n",bel[r],r-(bel[r]-1)*BS);
			printf("%d\n",max(btb[bel[l]+1][bel[r]-1],\
			max(suf[bel[l]][l-(bel[l]-1)*BS],pre[bel[r]][r-(bel[r]-1)*BS])));
		}
	}
	return 0;
}