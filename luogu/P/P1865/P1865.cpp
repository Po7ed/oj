#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	int n,m,l,r;
	scanf("%d %d",&n,&m);
	vector<int> p;
	bool b[m+1];
	int f[m+1];
	memset(b,true,sizeof(b));
	memset(f,0,sizeof(f));
	b[0]=false;
	b[1]=false;
	f[0]=0;
	f[1]=0;
	for(int i=2;i<=m;i++)
	{
		if(b[i])
		{
			p.push_back(i);
			f[i]=f[i-1]+1;
		}
		else
		{
			f[i]=f[i-1];
		}
		l=p.size();
		for(int j=0;j<l&&p[j]*i<=m;j++)
		{
			b[p[j]*i]=false;
			if(i%p[j]==0)
				break;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&l,&r);
		if(l>=1&&r<=m)
		{
			printf("%d\n",f[r]-f[l-1]);
		}
		else
		{
			puts("Crossing the line");
		}
	}
	return 0;
}