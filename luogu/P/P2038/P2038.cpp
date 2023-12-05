#include <iostream>
#include <vector>
using namespace std;

struct pub
{
	int x,y,k;
};
pub a[21];
int vis[129][129];
#define dx (a[i].x+j)
#define dy (a[i].y+k)

int main()
{
	int d,n;
	scanf("%d\n%d",&d,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].k);
		for(int j=-d;j<=d;j++)
		{
			for(int k=-d;k<=d;k++)
			{
				if(dx>=0&&dy>=0&&dx<=128&&dy<=128)
				{
					vis[dx][dy]+=a[i].k;
				}
			}
		}
	}
	int cnt=0,ans=-1;
	for(int i=0;i<=128;i++)
	{
		for(int j=0;j<=128;j++)
		{
			// printf("%d ",vis[i][j]);
			if(vis[i][j]==ans)
			{
				cnt++;
			}
			else if(ans<vis[i][j])
			{
				cnt=1;
				ans=vis[i][j];
			}
		}
		// puts("");
	}
	printf("%d %d",cnt,ans);
	return 0;
}