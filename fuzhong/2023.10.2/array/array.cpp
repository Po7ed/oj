#include <iostream>
using namespace std;

const int N=11451,D=11;
int a[N],s[N][D],hav[D],mah;

int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		for(int j=1;j<D;j++)
		{
			if(j==a[i])
			{
				s[i][j]=s[i-1][j]+1;
			}
			else
			{
				s[i][j]=s[i-1][j];
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			mah=-1;
			for(int k=1;k<D;k++)
			{
				hav[k]=s[j][k]-s[i-1][k];
				mah=max(mah,hav[k]);
			}
			if(mah>(j-i+1)/2)
			{
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}