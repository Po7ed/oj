#include <iostream>
using namespace std;

constexpr int N=114514;
int a[N],pos[N];

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",a+i),pos[a[i]]=i;
		for(int i=1,p;i<=m&&i<=n;i++)
		{
			if(a[i]==i){m++;continue;}
			p=pos[i];
			pos[i]=pos[a[i]];
			pos[a[i]]=p;
			swap(a[p],a[i]);// p <-> i
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}