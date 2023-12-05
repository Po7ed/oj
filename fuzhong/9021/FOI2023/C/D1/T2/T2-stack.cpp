#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("squares.in","r",stdin);
	freopen("squares.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int l[n+1],r[n+1];
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		while(!v.empty()&&a[v.back()]>a[i])
		{
			v.pop_back();
		}
		l[i]=(v.empty()?0:v.back());
		v.push_back(i);
	}
	v.clear();
	for(int i=n;i>0;i--)
	{
		while(!v.empty()&&a[v.back()]>a[i])
		{
			v.pop_back();
		}
		r[i]=(v.empty()?n+1:v.back());
		v.push_back(i);
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,(r[i]-l[i]-1)*a[i]);
	}
	printf("%d",ans);
	return 0;
}