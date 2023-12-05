#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int a[n+1][m+1][4];
	memset(a,0,sizeof(a));
	int x,y,t,c;
	for(int k=0;k<q;k++)
	{
		scanf("%d %d %d %d",&x,&y,&t,&c);
		if(m==1)
		{
			puts("Yes");
			goto con;
		}
		a[x][y][t]+=(c%256);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=(m+1)/2+1;j++)
			{
				if(a[i][j][1]!=a[i][m-j+1][1]||a[i][j][2]!=a[i][m-j+1][2]||a[i][j][3]!=a[i][m-j+1][3])
				{
					puts("No");
					goto con;
				}
			}
		}
		puts("Yes");
		con:;
	}
	return 0;
}