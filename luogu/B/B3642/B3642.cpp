#include <iostream>
using namespace std;

struct node
{
	int ls,rs;
};

node tree[1000001];

void nlr(int x)
{
	printf("%d ",x);
	if(tree[x].ls)
		nlr(tree[x].ls);
	if(tree[x].rs)
		nlr(tree[x].rs);
}
void lnr(int x)
{
	if(tree[x].ls)
		lnr(tree[x].ls);
	printf("%d ",x);
	if(tree[x].rs)
		lnr(tree[x].rs);
}
void lrn(int x)
{
	if(tree[x].ls)
		lrn(tree[x].ls);
	if(tree[x].rs)
		lrn(tree[x].rs);
	printf("%d ",x);
}

int main()
{
	int n,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&l,&r);
		tree[i].ls=l;
		tree[i].rs=r;
	}
	nlr(1);
	puts("");
	lnr(1);
	puts("");
	lrn(1);
	puts("");
	return 0;
}