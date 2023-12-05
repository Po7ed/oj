#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int w[n+1],v[n+1],f[m+1];
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int tw,tv;
		scanf("%d %d",&tw,&tv);
		w[i]=tw;v[i]=tw*tv;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(j-w[i]>=0)
				f[j]=(f[j]>(v[i]+f[j-w[i]])?f[j]:(v[i]+f[j-w[i]]));
		}
	}
	printf("%d",f[m]);
	return 0;
}