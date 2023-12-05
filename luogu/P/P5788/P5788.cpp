#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	int a[n+1],f[n+1];
	// memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		while(!v.empty()&&a[i]>=a[v.back()])
			v.pop_back();
		f[i]=(v.empty()?0:v.back());
		v.push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}