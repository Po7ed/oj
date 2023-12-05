#include <iostream>
using namespace std;
int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	int a[n+2],l=0;
	fill(a,a+(n+1),0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=a[i]-l;
		l+=a[i];
	}
	int x,y,z;
	for(int i=0;i<p;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		a[x]+=z;
		a[y+1]-=z;
	}
	int s=0,m=114514;
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		m=min(m,s);
	}
	printf("%d",m);
	return 0;
}