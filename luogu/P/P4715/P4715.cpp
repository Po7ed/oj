#include <iostream>
using namespace std;

int a[114+19];
short seg[514];
short n;

#define ls (pos<<1)
#define rs (pos<<1|1)

inline void update(int pos)
{
	seg[pos]=(a[seg[ls]]>a[seg[rs]]?seg[ls]:seg[rs]);
}

void build(short pos=1,short l=1,short r=n)
{
	if(l==r)
	{
		seg[pos]=l;
		return;
	}
	short mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(pos);
	return;
}

int main()
{
	scanf("%d",&n);
	n=1<<n;
	for(short i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	build();
	printf("%d",(a[seg[2]]>a[seg[3]]?seg[3]:seg[2]));
	return 0;
}