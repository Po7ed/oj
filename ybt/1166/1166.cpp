#include <iostream>
#include <math.h>
using namespace std;

double f(double x,double n)
{
	if(n==0)return x;
	return sqrt(n+f(x,n-1));
}

int main()
{
	double x,n;
	scanf("%lf %lf",&x,&n);
	printf("%.2lf",f(x,n));
	return 0;
}