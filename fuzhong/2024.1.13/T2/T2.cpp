#include <iostream>
#include <algorithm>
using namespace std;

constexpr int N=1145141,p=1000000007;
int n,m;
namespace bit// range add, point get
{
	int t[N];
	#define lb (x&(-x))
	inline void add(int x,int y){for(;x<N;x+=lb)t[x]=((t[x]+y)%p+p)%p;}
	inline void add(int l,int r,int y){add(l,y),add(r+1,-y);}
	inline int get(int x){int res=0;for(;x;x-=lb)res=((res+t[x])%p+p)%p;return res;}
}// namespace bit

struct bed
{
	int id,l;
	friend inline bool operator < (bed x,bed y){return x.id<y.id;}
};
bed b[N];
int id[N];

//void printbit()
//{
//	puts("***");
//	for(int i=1;i<=n;i++)printf("%d:%d ",id[i],bit::get(i));
//	puts("\n***");
//}

int main()
{
	freopen("lattice.in","r",stdin);
	freopen("lattice.out","w",stdout);
	scanf("%d %d %d",&n,&m,&b[1].l);b[1].id=1;
	for(int i=2;i<=n;i++)scanf("%d %d",&b[i].id,&b[i].l);
	b[++n]={m,0};
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)id[i]=b[i].id/*,printf("%d ",id[i])*/;
	bit::add(1,1,1);
//	printbit();
	for(int i=1,pos;i<n;i++)
	{
		pos=upper_bound(id+1,id+n+1,id[i]+b[i].l)-id-1;
//		printf("(%d,%d]+%d\n",i,pos,bit::get(i));
		if(i<pos)bit::add(i+1,pos,bit::get(i));
	}
	printf("%d",bit::get(n));
	return 0; 
}