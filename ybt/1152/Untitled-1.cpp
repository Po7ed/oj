#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double m=(double)max(a,max(b,c))/(max(a+b,max(b,c))*max(a,max(b,b+c)));
	printf("%.3lf",m);
	return 0;
}