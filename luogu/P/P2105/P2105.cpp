#include <iostream>
#include <bitset>
using namespace std;

/* int d[8][2]=
{
	{-1,0},
	{-1,-1},
	{-1,1},
	{0,-1},
	{0,1},
	{1,0},
	{1,-1},
	{1,1}
};
#define dx x+d[j][0]*k
#define dy y+d[j][1]*k */

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	bitset<20114> v1,v2;
	bitset<40114> v3,v4;//i-j+n-1,2*n-i-j
	int x,y;
	for(int i=1;i<=k;i++)
	{
		scanf("%d %d",&x,&y);
		v1[x]=true;
		v2[y]=true;
		v3[x-y+n-1]=true;
		v4[2*n-x-y]=true;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!v1[i])
		{
			for(int j=1;j<=m;j++)
			{
				if(!v2[j])
				{
					if(!v3[i-j+n-1]&&!v4[2*n-i-j])
					{
						ans++;
					}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}