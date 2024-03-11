#include <iostream>
#include <vector>

const int N=2100;
int a[N][N],n,m;

int up[N][N],l[N][N],r[N][N],left[N][N],right[N][N];

int main()
{
	scanf("%d %d",&n,&m);
	char c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf(" %c",&c);
			a[i][j]=(c=='F');
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			up[i][j]=(a[i][j]?up[i-1][j]+1:0);
			l[i][j]=(a[i][j]?l[i][j-1]+1:0);
			if(up[i][j])left[i][j]=up[i][j]>1?std::min(left[i-1][j],l[i][j]):l[i][j];
		}
		for(int j=m;j;j--)
		{
			r[i][j]=(a[i][j]?r[i][j+1]+1:0);
			if(up[i][j])right[i][j]=up[i][j]>1?std::min(right[i-1][j],r[i][j]):r[i][j];
			ans=std::max(ans,(right[i][j]+left[i][j]-1)*up[i][j]);
		}
	}
	printf("%d",ans*3);
	return 0;
}