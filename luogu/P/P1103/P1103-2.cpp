#include <iostream>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int f[101][101]/* ,la[101][101][101],ra[101][101][101] */;

struct book
{
	int h,w;
};

bool cmp(book a,book b)
{
	return a.h<b.h;
}

int main()
{
	int n,k,m;
	scanf("%d %d",&n,&k);
	m=n-k;
	book a[n+2];
	// a[0].w=INF;
	// a[n+1].w=INF;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].h,&a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	fill(*f,*f+(101)*(101),INF);
	for(int i=1;i<=n;i++)
	{
		f[i][1]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int l=2;l<=min(i,m);l++)
			{
				f[i][l]=min(f[i][l],f[j][l-1]+abs(a[i].w-a[j].w));
			}
		}
	}
	int ans=INF;
	for(int i=m;i<=n;i++)
	{
		ans=min(ans,f[i][m]);
	}
	printf("%d\n",ans);
	return 0;
}