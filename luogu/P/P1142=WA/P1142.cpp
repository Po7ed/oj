#include <iostream>
using namespace std;

struct point
{
	int x,y;
};

int f[701];
int Find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=Find(f[x]);
}

/* void Union(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx==fy)
		return;
	else
		f[fx]=fy;
	return;
} */

int main()
{
	int n;
	scanf("%d",&n);
	point a[n+1];
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i].x*a[j].y==a[i].y*a[j].x)
			{
				f[Find(i)]=Find(j);
			}
		}
	}
	int cnt[n+1];
	fill(cnt,cnt+(n+1),0);
	for(int i=1;i<=n;i++)
	{
		cnt[Find(i)]++;
	}
	int m=-1;
	for(int i=1;i<=n;i++)
	{
		m=max(m,cnt[i]);
	}
	printf("%d",m);
	return 0;
}