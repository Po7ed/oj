#include <iostream>
#include <cstring>
using namespace std;

/* inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
} */

int main()
{
	// freopen("hack","r",stdin);
	int m,n,k;
	scanf("%d\n%d\n%d\n",&m,&n,&k);
	char ch;
	int t;
	bool a[m+1][n+1];
	memset(a,false,sizeof(a));
	bool r[m+1],c[n+1];
	memset(r,false,sizeof(r));
	memset(c,false,sizeof(c));
	for(int i=0;i<k;i++)
	{
		scanf("%c %d\n",&ch,&t);
		//c=getchar();
		//// getchar();
		//t=read();
		//// char debug=getchar();
		if(ch=='R')
			r[t]=!r[t];
			// for(int j=1;j<=n;j++)
				// a[t][j]=!a[t][j];
		else
			c[t]=!c[t];
			// for(int j=1;j<=m;j++)
				// a[j][t]=!a[j][t];
	}
	int ans=0;
	/* for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j])
				ans++; */
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			ans+=int(r[i]^c[j]);
	printf("%d",ans);
	return 0;
}