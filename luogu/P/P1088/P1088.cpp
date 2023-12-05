#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		next_permutation(a,a+n);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}