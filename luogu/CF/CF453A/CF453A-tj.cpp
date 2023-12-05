#include <iostream>
#include <cmath>
using namespace std;

constexpr int N=114514;
double n,m,ans;

int main()
{
	scanf("%lf %lf",&m,&n);
	for(double i=1;i<=m;i++)
	{
		ans+=i*(pow(i/m,n)-pow((i-1)/m,n));
	}
	printf("%.8lf",ans);
	return 0;
}