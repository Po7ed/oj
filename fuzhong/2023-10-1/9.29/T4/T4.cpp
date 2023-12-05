#include <iostream>
#include <string>
using namespace std;

const int N=214514;
int n;
int f[N][2];
char s[N];

int main()
{
	// freopen("lottery.in","r",stdin);
	// freopen("lottery.out","w",stdout);
	scanf("%d %s",&n,s+1);
	int l=0;
	f[0][0]=-n;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B')
		{
			f[i][0]=max(f[l][0]+i-l-1,f[l][1]);
			f[i][1]=max(f[l][0],f[l][1])+i-l-1;
			l=i;
		}
	}
	printf("%d",max(f[l][0]+n-l,f[l][1]));
	return 0;
}