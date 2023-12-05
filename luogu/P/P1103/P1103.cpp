#include <iostream>
#include <algorithm>
using namespace std;

int f[101][101][101],la[101][101][101],ra[101][101][101];

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
	int n,k;
	scanf("%d %d",&n,&k);
	book a[n+1];
	// a[n+1]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].h,&a[i].w);
	}
	sort(a+1,a+n+1,cmp);
	fill(**f,**f+(n+1)*(n+1)*(k+1),0x3f3f3f3f);
	fill(**la,**la+(n+1)*(n+1)*(k+1),-1);
	fill(**ra,**ra+(n+1)*(n+1)*(k+1),-1);
	for(int l=1;l<=n;l++)
	{
		f[l][l][0]=0;
		la[l][l][0]=l;
		ra[l][l][0]=l;
		f[l][l][1]=0;
	}
	int t;
	for(int i=0;i<=k;i++)//1
	{
		for(int l=1;l<=n;l++)//1
		{
			for(int r=l+1;r<=n;r++)//2
			{
				for(int m=l;m<r;m++)//1
				{
					for(int d=0;d<=i;d++)//0
					{
						// if(la)
						t=f[l][m][d]+((ra[l][m][d]!=-1&&la[m+1][r][i-d]!=-1)?abs(a[ra[l][m][d]].w-a[la[m+1][r][i-d]].w):0)+f[m+1][r][i-d];
						if(f[l][r][i]>t)
						{
							f[l][r][i]=t;
							la[l][r][i]=(la[l][m][d]==-1?la[m+1][r][i-d]:la[l][m][d]);
							ra[l][r][i]=(ra[m+1][r][i-d]==-1?ra[l][m][d]:ra[m+1][r][i-d]);
						}
					}
				}
			}
		}
	}
	/* for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			for(int i=0;i<=k;i++)
			{
				printf("f[%d][%d][%d]=%d ",l,r,i,f[l][r][i]);
			}
			puts("");
		}
	} */
	printf("%d\n",f[1][n][k]);
	return 0;
}