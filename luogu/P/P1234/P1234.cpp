#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d\n",&n,&m);
	char a[n+1][m+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// a[i][j]=getchar();
			cin>>a[i][j];
		}
		// getchar();
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='e'&&a[i+1][j]=='h'&&a[i+2][j]=='e'&&a[i+3][j]=='h')
				ans++;
			if(a[i][j]=='h'&&a[i+1][j]=='e'&&a[i+2][j]=='h'&&a[i+3][j]=='e')
				ans++;
			if(a[i][j]=='e'&&a[i][j+1]=='h'&&a[i][j+2]=='e'&&a[i][j+3]=='h')
				ans++;
			if(a[i][j]=='h'&&a[i][j+1]=='e'&&a[i][j+2]=='h'&&a[i][j+3]=='e')
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}