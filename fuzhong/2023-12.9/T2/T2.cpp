#include <iostream>
using namespace std;
int n,m;
int main()
{
	freopen("draw.in","r",stdin);
	freopen("draw.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%d",n*m/2);
	return 0;
}