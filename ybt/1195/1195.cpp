#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1];
	bool f[n+1][k];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1][(a[1]%k+k)%k]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<k;j++)
			f[i][j]=f[i-1][((j-a[i])%k+k)%k]||f[i-1][((j+a[i])%k+k)%k];
	if(f[n][0])printf("YES");else printf("NO");
	return 0;
}