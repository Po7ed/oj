#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int w[3],v[3],ans=0x3f3f3f3f;
	for(int i=0;i<3;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}
	for(int i=0;i<3;i++)
	{
		int u=0,m=0;
		while(m<n)
		{
			u+=v[i];
			m+=w[i];
		}
		ans=min(ans,u);
		// printf("#%d\n",u);
	}
	printf("%d",ans);
	return 0;
}