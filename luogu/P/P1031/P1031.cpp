#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],q[n],ans=0,p=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		p+=a[i];
	}
	p/=n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		q[i]=a[i]-p;
	}
	for(int i=0;i<n;i++)
	{
		if(!q[i])
			continue;
		q[i+1]+=q[i];
		ans++;
	}
	printf("%d",ans);
	return 0;
}