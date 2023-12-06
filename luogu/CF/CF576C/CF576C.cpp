#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int N=1145141;

int n,bel[N],S;

struct p
{
	int x,y,id;
	friend inline bool operator < (p u,p v)
	{
		return (bel[u.x]^bel[v.x]?bel[u.x]<bel[v.x]:(bel[u.x]&1?u.y<v.y:v.y<u.y));
	}
};
p a[N];

inline void init()
{
	S=int(ceil(pow(n,0.5)));
	for(int i=1;i<=n;i++)bel[i]=(i-1)/S+1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].y),a[i].id=i;
	init();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d ",a[i].id);
	return 0;
}