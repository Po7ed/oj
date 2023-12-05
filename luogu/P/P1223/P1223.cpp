#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> p;
#define id first
#define v second

bool cmp(p a,p b)
{
	return a.v<b.v;
}

int main()
{
	int n;
	scanf("%d",&n);
	p t[n+1];
	t[0].v=-114514;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i].v);
		t[i].id=i;
	}
	sort(t,t+n+1,cmp);
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		s+=(t[i].v*(n-i));
		printf("%d ",t[i].id);
	}
	printf("\n%.2f",(double)s/n);
	return 0;
}