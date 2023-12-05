#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ma[9]={0,0,1,3,7,15,31,63,127},mi[9]={-1,-1,-2,-4,-8,-16,-32,-64,-128};
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	// int a[n+1];
	vector<int> a(n+1,0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a.begin()+1,a.end());
	int sum=0,x,y;
	for(int i=1;i<=n;i++)
	{
		auto p=lower_bound(a.begin()+1,a.end(),-sum);
		x=*(p-1);
		y=*p;
		if(abs(x+sum)>abs(y+sum))
		{
			if(p==a.end())
			{
				goto el;
			}
			sum+=y;
			a.erase(p);
		}
		else
		{
			el:
			sum+=x;
			a.erase(p-1);
		}
		if(sum<mi[k]||sum>ma[k])
		{
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",n);
	return 0;
}