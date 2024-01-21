#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N=51411;
int n;

int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	int maxw=-0x3f3f3f3f,sumw=0;
	for(int i=1,u,v,w;i<=n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		maxw=max(maxw,w);
		sumw+=w;
	}	
	printf("%d",sumw-maxw);
	return 0;
}