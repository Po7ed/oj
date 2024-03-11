#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

struct qwq
{
	int k,id;
	friend inline bool operator < (qwq x,qwq y)
	{
		printf("%d,%d\n",x.id,y.id);
		return x.k<y.k;
	}
};
int n;
constexpr int N=114514;
qwq a[N];

int main()
{
	freopen("out","w",stdout);
	std::mt19937 rd(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	// scanf("%d",&a[i].k),
	a[i].k=rd(),
	a[i].id=i;
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d\n",a[i].k);
	return 0;
}