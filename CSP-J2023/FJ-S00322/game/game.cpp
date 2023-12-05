#include <iostream>
#include <bitset>
using namespace std;

typedef long long ll;
const int N=10000;
bitset<N> vis[N];
char s[N];

int main()
{
	// freopen("game.in","r",stdin);
	// freopen("game.out","w",stdout);
	int n;
	scanf("%d\n%s",&n,s+1);
	if(n>8000)
	{
		ll tmp=0;
		for(int i=1;i<n;i++)
		{
			if(i+2<=n&&s[i]==s[i+1]&&s[i+1]==s[i+2])
			{
				tmp+=3;
				i+=2;
			}
			else if(s[i]==s[i+1])
			{
				tmp++;
				i++;
			}
		}
		printf("%lld\n",tmp);
		return 0;
	}
	ll ans=0;
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		for(int i=1;j<=n;i++)
		{
			if(l==2)
			{
				vis[i][j]=(s[i]==s[j]);
			}
			else
			{
				if(s[i]==s[i+1]&&vis[i+2][j])
				{
					vis[i][j]=true;
				}
				else if(s[j]==s[j-1]&&vis[i][j-2])
				{
					vis[i][j]=true;
				}
				else if(s[i]==s[j]&&vis[i+1][j-1])
				{
					vis[i][j]=true;
				}
				else
				{
					for(int k=i+2;k<j-2;k++)
					{
						if(vis[i][k]&&vis[k+1][j])
						{
							vis[i][j]=true;
							break;
						}
					}
				}
			}
			if(vis[i][j])ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
