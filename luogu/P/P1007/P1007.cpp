#include <iostream>
using namespace std;
int main()
{
	int n,l,a,ans1=0,ans2=0;
	scanf("%d %d",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		ans1=max(ans1,min(a,l-a+1));
		ans2=max(ans2,max(a,l-a+1));
	}
	printf("%d %d",ans1,ans2);
	return 0;
}