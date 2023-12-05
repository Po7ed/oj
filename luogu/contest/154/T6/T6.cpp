#include <iostream>
using namespace std;

char a[501][501];

int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

#define dx (i+d[dir][0]*k)
#define dy (j+d[dir][1]*k)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,x,c;
	cin>>n>>m>>x>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int cnt,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt=0;
			if(a[i][j]=='M')
			{
				for(int dir=0;dir<4;dir++)
				{
					for(int k=1;k<=n;k++)
					{
						if(dx>0&&dy>0&&dx<=n&&dy<=m)
						{
							if(a[dx][dy]=='F')
							{
								break;
							}
						}
						else
						{
							cnt++;
							break;
						}
					}
				}
				if(cnt>=3)
				{
					ans++;
				}
			}
			else if(a[i][j]=='F')
			{
				for(int dir=0;dir<4;dir++)
				{
					for(int k=1;k<=n;k++)
					{
						if(dx>0&&dy>0&&dx<=n&&dy<=m)
						{
							if(a[dx][dy]=='M')
							{
								break;
							}
						}
						else
						{
							cnt++;
							break;
						}
					}
				}
				if(cnt>=3)
				{
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}