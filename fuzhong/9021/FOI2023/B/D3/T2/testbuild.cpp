#include <iostream>
using namespace std;

int a[114514];
int n;

#define ls (pos<<1)
#define rs (pos<<1|1)
#define md ((l+r)>>1)

void build(int pos=1,int l=1,int r=n)
{
	printf("%d %d %d\n",pos,l,r);
	if(l==r)
	{
		return;
	}
	int mid=md;
	printf("mid:%d\n",mid);
	build(ls,l,mid);
	build(rs,mid+1,r);
}

int main()
{
	scanf("%d",&n);
	build();
	return 0;
}