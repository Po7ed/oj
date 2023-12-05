#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int m,n,k;
	scanf("%d\n%d\n%d\n",&m,&n,&k);
	char c;
	int t;
	bool a[m+1][n+1];
	memset(a,false,sizeof(a));
	for(int i=0;i<k;i++)
	{
		scanf("%c %d\n",&c,&t);
		if(c=='R')
			for(int j=1;j<=n;j++)
				a[t][j]=!a[t][j];
		else
			for(int j=1;j<=m;j++)
				a[j][t]=!a[j][t];
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j])
				ans++;
	printf("%d",ans);
	return 0;
}