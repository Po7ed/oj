#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	int T,xa,ya,xb,yb,xc,yc,xd,yd,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d %d %d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
		ans+=!(xa<=xc&&xc<=xb);
		ans+=!(yc<=ya&&ya<=yd);
		printf("%d\n",ans);
	}
	return 0;
}