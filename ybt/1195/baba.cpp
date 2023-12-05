/* #include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n+1],f[n+1][2];
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1][0]=((0-a[1])%k+k)%k;f[1][1]=(a[1]%k+k)%k;
	for(int i=2;i<=n;i++)
		{f[i][0]=((f[i-1][0]+a[i])%k+k)%k;f[i][1]=((f[i-1][1]-a[i])%k+k)%k;}
	if(f[n][0]==0||f[n][1]==0)printf("YES");else printf("NO");
	return 0;
} */