#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N=114514;
struct node
{
	int id,v;
	friend inline bool operator < (node x,node y)
	{
		return x.v<y.v;
	}
};
int n;
node a[N];
int ans[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].v),a[i].id=i;
	sort(a+1,a+n+1);
	node tmp=a[1];
	ans[a[1].id]=-1;
	for(int i=2;i<=n;i++)
	{
		ans[a[i].id]=(tmp.id-a[i].id-1<0?-1:tmp.id-a[i].id-1);
		if(tmp.id<a[i].id)tmp=a[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}