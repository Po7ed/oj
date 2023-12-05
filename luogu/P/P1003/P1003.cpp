#include <iostream>
using namespace std;

struct carpet
{
	int a,b,g,k;
};

#define x1 a[i].a
#define x2 a[i].a+a[i].g
#define y1 a[i].b
#define y2 a[i].b+a[i].k

int main()
{
	int n;
	scanf("%d",&n);
	carpet a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a[i].a,&a[i].b,&a[i].g,&a[i].k);
	} 
	int x,y,ans=-1;
	scanf("%d %d",&x,&y);
	for(int i=1;i<=n;i++)
	{
		if(x1<=x&&x<=x2&&y1<=y&&y<=y2)
		{
			ans=i;
		}
	}
	printf("%d",ans);
	return 0;
}