#include <iostream>
using namespace std;
int main()
{
	double a,b,c,d;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	double f;
	// freopen("out.txt","w",stdout);
	for(double cur=-100.0;cur<=100.0;cur+=0.01)
	{
		f=cur*cur*cur*a+cur*cur*b+cur*c+d;
		// printf("f(%.2lf)=%lf\n",cur,f);
		if(-0.000001<f&&f<0.000001)
		{
			printf("%.2lf ",cur);
		}
	}
	return 0;
}