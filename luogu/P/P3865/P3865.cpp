#include <iostream>
using namespace std;
#define MN 100001
int log[MN];

inline void init()
{
	log[1]=0;
	for(int i=2;i<=MN;i++)
	{
		log[i]=log[i>>1]+1;
	}
}

int main()
{
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int mul[2*n][log[n]+1];
	fill(*mul,*mul+(2*n)*(log[n]+1),-0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		mul[i][0]=a[i];
	}
	for(int j=1;j<=log[n];j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			mul[i][j]=max(mul[i][j-1],mul[i+(1<<(j-1))][j-1]);
		}
	}
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&l,&r);
		#define len log[r-l+1]
		printf("%d\n",max(mul[l][len],mul[r-(1<<len)+1][len]));
	}
	return 0;
}