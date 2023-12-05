#include <iostream>
using namespace std;

int f[1000];
int Find(int k)
{
	if(f[k]==k)
		return k;
	return f[k]=Find(f[k]);
}
void Union(int a,int b)
{
	int fa=Find(a),fb=Find(b);
	f[fa]=fb;
	return;
}


int main()
{
	int n,m;
	scanf("%d",&n);
	int u,v,ans=0;
	while(n)
	{
		for(int i=0;i<=n;i++)
		{
			f[i]=i;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			Union(u,v);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i)
			{
				ans++;
			}
		}
		printf("%d\n",ans-1);
		scanf("%d",&n);
	}
	return 0;
}